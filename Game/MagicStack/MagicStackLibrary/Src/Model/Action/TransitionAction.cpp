#include "TransitionAction.h"
#include "../../Model/ControllerTransition.h"

namespace MagicStack
{
    CTransitionAction::CTransitionAction(CControllerTransition& transition, const std::string& alias)
        : Transition(transition)
        , Alias(alias)
    {
    }

    void CTransitionAction::Execute()
    {
        this->Transition.GoTo(this->Alias);
    }
}