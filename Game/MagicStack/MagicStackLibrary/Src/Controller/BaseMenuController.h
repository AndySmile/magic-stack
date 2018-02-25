#ifndef __MAGICSTACK_CONTROLLER_BASEMENUCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_BASEMENUCONTROLLER_H__

#include "IController.h"
#include "../Model/Menu.h"

namespace MagicStack
{
    struct IAction;

    class CBaseMenuController : public IController
    {
        public:
            CBaseMenuController() = default;
            virtual ~CBaseMenuController() = default;

            virtual void Render() const override;
            virtual IAction* Execute() const override;

        protected:
            CMenu Menu;
            CMenuView View;
    };
}

#endif
