#include "ControllerTransition.h"
#include "FrontController.h"

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
