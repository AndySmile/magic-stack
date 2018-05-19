#include "QuitAction.h"
#include "../../Model/ControllerTransition.h"

namespace MagicStack
{
    CQuitAction::CQuitAction(CControllerTransition& transition)
        : Transition(transition)
    {
    }

    void CQuitAction::Execute()
    {
        this->Transition.Quit();
    }
}