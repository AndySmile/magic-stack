#ifndef __MAGICSTACK_CONTROLLER_GAME_GAMECONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_GAME_GAMECONTROLLER_H__

#include "../Menu/BaseMenuController.h"

namespace MagicStack
{
    struct IAction;

    class CGameController : public CBaseMenuController
    {
        public:
            CGameController() = default;
            virtual ~CGameController() = default;

            virtual void Init(CControllerTransition& transition) override;
            virtual std::string GetAlias() const;
    };
}

#endif