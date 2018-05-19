#include "MainController.h"
#include "Menu/MenuController.h"
#include "Menu/HelpController.h"
#include "Game/GameController.h"

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