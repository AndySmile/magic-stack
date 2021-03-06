#ifndef __MAGICSTACK_CONTROLLER_MENU_BASEMENUCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_MENU_BASEMENUCONTROLLER_H__

#include "../IController.h"
#include "../BaseController.h"
#include "../../Model/Menu.h"
#include "../../View/MenuView.h"

namespace MagicStack
{
    struct IAction;

    class CBaseMenuController : public CBaseController
    {
        public:
            CBaseMenuController() = default;
            virtual ~CBaseMenuController();

            virtual void Render() const override;
            virtual IAction* Execute() override;

        protected:
            CMenu Menu;
            CMenuView View;
    };
}

#endif
