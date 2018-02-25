#include "MainController.h"
#include "MenuController.h"

namespace MagicStack
{
    CMainController::CMainController()
    {
        this->FrontController.AddController(new CMenuController());
    }

    void CMainController::Run()
    {
        this->FrontController.Run();
    }
}