#include "HelpController.h"
#include "../Model/Action/TransitionAction.h"
#include <iostream>

namespace MagicStack
{
    void CHelpController::Init(CControllerTransition& transition)
    {
        this->Menu.AddItem(1, "About the world", new CControllerAction(*this, "world"));
        this->Menu.AddItem(2, "The game", new CControllerAction(*this, "game"));
        this->Menu.AddItem(3, "Cards", new CControllerAction(*this, "cards"));
        this->Menu.AddItem(4, "Back", new CTransitionAction(transition, "main"));
    }

    void CHelpController::ExecuteControllerAction(const std::string& action)
    {
        if (action == "world") {
            this->DisplayWorldDescription();
        }
        else {
            this->DisplayUnknownTopic();
        }
    }

    void CHelpController::OnEnter()
    {
    }

    void CHelpController::OnLeave()
    {
    }

    std::string CHelpController::GetAlias() const
    {
        return "help";
    }

    void CHelpController::DisplayWorldDescription() const
    {
        std::cout << "The world is big and round! lot's of things happen upon it!" << std::endl;
    }

    void CHelpController::DisplayUnknownTopic() const
    {
        std::cout << "No clue about this topic!" << std::endl;
    }
}