#include "GameController.h"
#include "IPlayerController.h"
#include "PlayerController.h"
#include "AIController.h"
#include "../../Model/Action/TransitionAction.h"
#include "../../Model/ICardAction.h"

// DEBUG BEGIN
#include <iostream>
// DEBUG END

namespace MagicStack
{
    CGameController::CGameController()
        : TransitionAction(nullptr)
    {
    }

    void CGameController::Init(CControllerTransition& transition)
    {
        this->TransitionAction = new CTransitionAction(transition, "menu");

        //this->Menu.AddItem(1, "Fire Attack");
        //this->Menu.AddItem(2, "Surrender", new CTransitionAction(transition, "menu"));

        this->Round.SetPlayerController(new CPlayerController(), CMatchRound::PlayerIndex::FirstPlayer);
        this->Round.SetPlayerController(new CAIController(), CMatchRound::PlayerIndex::SecondPlayer);
    }

    void CGameController::Render() const
    {
    }
    
    IAction* CGameController::Execute()
    {
        if (!this->Round.HasAllPlayer()) {
            std::cout << "ERROR: not enough player registered!" << std::endl;
        } else {
            while (this->Round.IsRunning()) {
                std::cout << "game round is running!" << std::endl;
            
                IPlayerController* controller = this->Round.GetCurrentController();
                ICardAction* currAction = controller->PickCardAction();

                currAction->Apply(this->Round.GetAttackCard(), this->Round.GetDefenseCard());

                this->Round.NextRound();
            }
        }

        return this->TransitionAction;
    }

    std::string CGameController::GetAlias() const
    {
        return "game";
    }
}