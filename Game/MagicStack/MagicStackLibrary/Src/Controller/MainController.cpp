#include "MainController.h"
#include "MenuController.h"
#include "HelpController.h"
#include "GameController.h"

namespace MagicStack
{
    CMainController::CMainController()
    {
        this->FrontController.AddController(new CMenuController());
        this->FrontController.AddController(new CHelpController());
        this->FrontController.AddController(new CGameController());
    }

    void CMainController::Run()
    {
        this->FrontController.Run();
    }
}