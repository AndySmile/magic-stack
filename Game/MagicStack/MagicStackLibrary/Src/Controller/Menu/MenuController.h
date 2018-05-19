#ifndef __MAGICSTACK_CONTROLLER_MENU_MENUCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_MENU_MENUCONTROLLER_H__

#include "BaseMenuController.h"
#include <string>

namespace MagicStack
{
    class CControllerTransition;

    class CMenuController : public CBaseMenuController
    {
        public:
            CMenuController() = default;
            virtual ~CMenuController() = default;

            virtual void Init(CControllerTransition& transition) override;
            virtual void OnEnter() override;
            virtual void OnLeave() override;
            virtual std::string GetAlias() const override;
    };
}

#endif
