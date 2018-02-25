#include "MainController.h"
#include "MenuController.h"
#include "HelpController.h"

namespace MagicStack
{
    CMainController::CMainController()
    {
        this->FrontController.AddController(new CMenuController());
        this->FrontController.AddController(new CHelpController());
    }

    void CMainController::Run()
    {
        this->FrontController.Run();
    }
}