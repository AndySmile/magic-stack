#include "QuitAction.h"
#include "../../Controller/ControllerTransition.h"

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