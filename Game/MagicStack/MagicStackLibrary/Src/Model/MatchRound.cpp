#include "MatchRound.h"
#include "Card.h"
#include "../Controller/Game/IPlayerController.h"
#include "../Helper/Macros.h"

namespace MagicStack
{
    CMatchRound::CMatchRound()
        : CurrentRound(0)
        , FirstPlayerController(nullptr)
        , SecondPlayerController(nullptr)
        , AttackCard(nullptr)
        , DefenseCard(nullptr)
    {
    }

    CMatchRound::~CMatchRound()
    {
        /*DELETE_OBJECT(this->AIController);
        DELETE_OBJECT(this->PlayerController);*/
    }

    void CMatchRound::SetPlayerController(IPlayerController* controller, const PlayerIndex index)
    {
        if (index == PlayerIndex::FirstPlayer) {
            this->FirstPlayerController = controller;
            this->AttackCard = this->FirstPlayerController->GetActiveCard();
        } else {
            this->SecondPlayerController = controller;
            this->DefenseCard = this->SecondPlayerController->GetActiveCard();
        }
    }

    CCard* CMatchRound::GetAttackCard() const
    {
        return (this->CurrentRound == 0) ? this->AttackCard : this->DefenseCard;
    }

    CCard* CMatchRound::GetDefenseCard() const
    {
        return (this->CurrentRound == 0) ? this->DefenseCard : this->AttackCard;
    }

    IPlayerController* CMatchRound::GetCurrentController() const
    {
        return (this->CurrentRound == 0) ? this->FirstPlayerController : this->SecondPlayerController;
    }

    void CMatchRound::NextRound()
    {
        this->CurrentRound = (this->CurrentRound == 0) ? 1 : 0;
    }

    bool CMatchRound::IsRunning() const
    {
        return (
                this->AttackCard->IsAlive() 
            &&  this->DefenseCard->IsAlive()
        );
    }

    bool CMatchRound::HasAllPlayer() const
    {
        return (
                this->FirstPlayerController != nullptr 
            &&  this->SecondPlayerController != nullptr
        );
    }
}