#ifndef __MAGICSTACK_CONTROLLER_GAME_GAMECONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_GAME_GAMECONTROLLER_H__

#include "../BaseController.h"
#include "../../Model/MatchRound.h"

namespace MagicStack
{
    class CTransitionAction;

    class CGameController : public CBaseController
    {
        public:
            CGameController();
            virtual ~CGameController() = default;

            virtual void Init(CControllerTransition& transition) override;
            virtual void Render() const;
            virtual IAction* Execute();
            virtual std::string GetAlias() const override;

        private:
            CTransitionAction* TransitionAction;
            CMatchRound Round;
            
    };
}

#endif