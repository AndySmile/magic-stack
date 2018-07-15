#include "BaseController.h"

#ifdef _DEBUG
    #include <iostream>
    #include "../Helper/Macros.h"
#endif

namespace MagicStack
{
    CBaseController::~CBaseController()
    {
        PRINT_RELEASE_INFO("CBaseController");
    }

    void CBaseController::OnEnter()
    {
    }

    void CBaseController::OnLeave()
    {
    }
}