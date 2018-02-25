#include "ControllerAction.h"
#include "../../Controller/IControllerActionExecutable.h"

namespace MagicStack
{
    CControllerAction::CControllerAction(IControllerActionExecutable& controller, const std::string& action)
        : Controller(controller)
        , Action(action)
    {
    }

    void CControllerAction::Execute()
    {
        this->Controller.ExecuteControllerAction(this->Action);
    }
}