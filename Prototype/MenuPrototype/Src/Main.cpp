#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Model\IMenuAction.h"
#include "Controller\FrontController.h"
#include "Controller\ControllerTransition.h"
#include "Controller\IController.h"

struct IControllerAction
{
    virtual ~IControllerAction() = default;

    virtual void ExecuteControllerAction(const std::string& action) = 0;
};

class CTransitionAction : public IMenuAction
{
    public:
        CTransitionAction(CControllerTransition& transition, const std::string& alias)
            : Transition(transition)
            , Alias(alias)
        {
        }

        virtual ~CTransitionAction() = default;

        virtual void Execute() override
        {
            this->Transition.GoTo(this->Alias);
        }

    private:
        CControllerTransition& Transition;
        std::string Alias;
};

class CQuitAction : public IMenuAction
{
    public:
        CQuitAction(CControllerTransition& transition)
            : Transition(transition)
        {
        }

        virtual ~CQuitAction() = default;

        virtual void Execute() override
        {
            this->Transition.Quit();
        }

    private:
        CControllerTransition& Transition;
};

class CControllerAction : public IMenuAction
{
    public:
        CControllerAction(IControllerAction& controller, const std::string& action)
            : Controller(controller)
            , Action(action)
        {
        }

        ~CControllerAction() = default;

        virtual void Execute() override
        {
            this->Controller.ExecuteControllerAction(this->Action);
        }

    private:
        IControllerAction& Controller;
        std::string Action;
};

struct SMenuItem
{
    SMenuItem(const unsigned int id, const std::string& label, IMenuAction* action)
        : Id(id)
        , Label(label)
        , Action(action)
    {
    }

    unsigned int Id;
    IMenuAction* Action;
    std::string Label;
};

typedef std::vector<SMenuItem> TMenuList;

class CMenu
{
    public:
        CMenu() = default;
        ~CMenu() = default;

        void AddItem(const unsigned int id, const std::string& label, IMenuAction* action)
        {
            SMenuItem item(id, label, action);

            this->AddItem(item);
        }

        void AddItem(const SMenuItem& item)
        {
            this->ItemList.push_back(item);
        }

        const TMenuList& GetItemList() const
        {
            return this->ItemList;
        }

        IMenuAction* GetAction(const unsigned int id) const
        {
            for (auto it = this->ItemList.begin(); it != this->ItemList.end(); ++it) {
                if (it->Id == id) {
                    return it->Action;
                }
            }

            return nullptr;
        }

        bool IsValidItemId(const unsigned int id) const
        {
            if (this->ItemList.size() > 0) {
                for (auto it = this->ItemList.begin(); it != this->ItemList.end(); ++it) {
                    if (it->Id == id) {
                        return true;
                    }
                }
            }

            return false;
        }

    private:
        TMenuList ItemList;
};

class CMenuView
{
    public:
        CMenuView() = default;
        ~CMenuView() = default;

        void DisplayHeadline() const
        {
            this->DisplayMessageBox("Magic Stack Menu Prototype - Build " __DATE__ " " __TIME__);
            this->DisplayNewLine();
        }

        void DisplayWelcome() const
        {
            this->DisplayArrowText("Welcome to the Magic Stack!");
            this->DisplayNewLine();
            this->DisplayArrowText("You're in the main menu right now!");
            this->DisplayArrowText("Please choose what you're like to do right now!");
            this->DisplayNewLine();
        }

        void DisplayMenu(const CMenu& menu) const
        {
            const TMenuList& list = menu.GetItemList();

            for (auto it = list.begin(); it != list.end(); ++it) {
                std::cout << "[" << it->Id << "] " << it->Label << std::endl;
            }

            this->DisplayNewLine();
        }

    private:
        void DisplayBoxLine() const
        {
            std::cout << "##################################################################" << std::endl;
        }

        void DisplayBoxText(const std::string& text) const
        {
            std::cout << "##### " << text << std::endl;
        }

        void DisplayDotLine() const
        {
            std::cout << "...................................................................................................................................." << std::endl;
        }

        void DisplayRoundLine() const
        {
            std::cout << "*************************************************************************************************************************************" << std::endl;
        }

        void DisplayArrowText(const std::string& text) const
        {
            std::cout << ">>> " << text << std::endl;
        }

        void DisplayNewLine() const
        {
            std::cout << std::endl;
        }

        void DisplayMessageBox(const std::string& message) const
        {
            this->DisplayBoxLine();
            this->DisplayBoxText("");
            this->DisplayBoxText(message);
            this->DisplayBoxText("");
            this->DisplayBoxLine();
        }
};

class CBaseMenuController : public IController
{
    public:
        CBaseMenuController() = default;
        virtual ~CBaseMenuController() = default;

        virtual void Render() const override
        {
            this->View.DisplayMenu(this->Menu);
        }

        virtual IMenuAction* ProcessUserInput() const override
        {
            unsigned int selectedMenuId = 0;

            do {
                std::cout << "Your selection: ";
                std::cin >> selectedMenuId;
            } while (!this->Menu.IsValidItemId(selectedMenuId));

            return this->Menu.GetAction(selectedMenuId);
        }

    protected:
        CMenu Menu;
        CMenuView View;
};

class CMainMenuController : public CBaseMenuController
{
    public:
        CMainMenuController() = default;
        virtual ~CMainMenuController() = default;

        virtual void Init(CControllerTransition& transition) override
        {
            this->Menu.AddItem(1, "Start Game", nullptr);
            this->Menu.AddItem(2, "Help", new CTransitionAction(transition, "help"));
            this->Menu.AddItem(3, "Quit", new CQuitAction(transition));
        }

        virtual void Enter() override
        {
            this->View.DisplayHeadline();
            this->View.DisplayWelcome();
        }

        virtual void Leave() override
        {
        }

        virtual std::string GetAlias() const
        {
            return "main";
        }
};

class CHelpController 
    : public CBaseMenuController
    , public IControllerAction
{
    public:
        CHelpController() = default;
        virtual ~CHelpController() = default;

        virtual void Init(CControllerTransition& transition) override
        {
            this->Menu.AddItem(1, "About the world", new CControllerAction(*this, "world"));
            this->Menu.AddItem(2, "The game", new CControllerAction(*this, "game"));
            this->Menu.AddItem(3, "Cards", new CControllerAction(*this, "cards"));
            this->Menu.AddItem(4, "Back", new CTransitionAction(transition, "main"));
        }

        virtual void ExecuteControllerAction(const std::string& action) override
        {
            if (action == "world") {
                this->DisplayWorldDescription();
            }
            else {
                this->DisplayUnknownTopic();
            }
        }

        virtual void Enter() override
        {
        }

        virtual void Leave() override
        {
        }

        virtual std::string GetAlias() const
        {
            return "help";
        }

    private:
        void DisplayWorldDescription() const
        {
            std::cout << "The world is big and round! lot's of things happen upon it!" << std::endl;
        }

        void DisplayUnknownTopic() const
        {
            std::cout << "No clue about this topic!" << std::endl;
        }
};

int main()
{
    CFrontController frontController;

    frontController.AddController(new CMainMenuController());
    frontController.AddController(new CHelpController());
    frontController.Run();

    system("pause");

    return EXIT_SUCCESS;
}