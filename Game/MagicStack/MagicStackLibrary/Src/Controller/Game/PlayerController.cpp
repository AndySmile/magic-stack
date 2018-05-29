#include "PlayerController.h"
#include "../../Model/CardAction/FireAction.h"
#include "../../Model/Card.h"

namespace MagicStack
{
    CPlayerController::CPlayerController()
        : ActiveCard(new CCard("MagicDragon", 100, 70))
        , DefaultAction(new CFireAction())
    {
    }

    CCard* CPlayerController::GetActiveCard() const
    {
       return this->ActiveCard;
    }

    ICardAction* CPlayerController::PickCardAction() const
    {


        return this->DefaultAction;
    }
}