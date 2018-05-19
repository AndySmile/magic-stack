#include "MenuController.h"
#include "../../Model/ControllerTransition.h"
#include "../../Model/Action/TransitionAction.h"
#include "../../Model/Action/QuitAction.h"

namespace MagicStack
{
    void CMenuController::Init(CControllerTransition& transition) 
    {
        this->Menu.AddItem(1, "Start Game", nullptr);
        this->Menu.AddItem(2, "Help", new CTransitionAction(transition, "help"));
        this->Menu.AddItem(3, "Quit", new CQuitAction(transition));
    }

    void CMenuController::OnEnter() 
    {
        this->View.DisplayHeadline();
        this->View.DisplayWelcome();
    }

    void CMenuController::OnLeave() 
    {
    }

    std::string CMenuController::GetAlias() const
    {
        return "main";
    }
}