#include "FrontController.h"
#include "IController.h"
#include "../Model/IMenuAction.h"
#include "../Macros.h"

CFrontController::CFrontController()
    : IsRunning(true)
    , CurrentController(nullptr)
    , Transition(*this)
{
}

CFrontController::~CFrontController()
{
    for (auto it = this->ControllerIndex.begin(); it != this->ControllerIndex.end(); ++it) {
        DELETE_OBJECT(it->second);
    }

    this->ControllerIndex.clear();
}

void CFrontController::AddController(IController* controller, bool isDefault)
{
    this->ControllerIndex[controller->GetAlias()] = controller;

    controller->Init(this->Transition);

    if (isDefault || this->CurrentController == nullptr) {
        this->SwitchToController(controller);
    }
}

void CFrontController::GoToController(const std::string& alias)
{
    this->SwitchToController(this->ControllerIndex[alias]);
}

void CFrontController::Quit()
{
    this->IsRunning = false;
}

void CFrontController::Run() const
{
    do {
        this->CurrentController->Render();
        IMenuAction* action = this->CurrentController->ProcessUserInput();

        if (action != nullptr) {
            action->Execute();
        }
    } while (this->IsRunning);
}

void CFrontController::SwitchToController(IController* controller)
{
    if (this->CurrentController != nullptr) {
        this->CurrentController->Leave();
    }

    this->CurrentController = controller;
    this->CurrentController->Enter();
}