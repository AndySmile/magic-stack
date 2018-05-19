#include "ControllerTransition.h"
#include "../Controller/FrontController.h"

namespace MagicStack
{
    CControllerTransition::CControllerTransition(CFrontController& frontController)
        : FrontController(frontController)
    {
    }

    void CControllerTransition::GoTo(const std::string& controllerAlias)
    {
        this->FrontController.GoToController(controllerAlias);
    }

    void CControllerTransition::Quit()
    {
        this->FrontController.Quit();
    }
}