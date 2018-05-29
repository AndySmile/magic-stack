#include "AIController.h"
#include "../../Model/CardAction/FireAction.h"
#include "../../Model/Card.h"

namespace MagicStack
{
    CAIController::CAIController()
        : ActiveCard(new CCard("MagicGuard", 50, 60))
        , DefaultAction(new CFireAction())
    {
    }

    CCard* CAIController::GetActiveCard() const
    {
        return this->ActiveCard;
    }

    ICardAction* CAIController::PickCardAction() const
    {
        return this->DefaultAction;
    }
}