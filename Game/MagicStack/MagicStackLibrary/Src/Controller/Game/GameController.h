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
            virtual ~CGameController();

            virtual void Init(CControllerTransition& transition) override;
            virtual void Render() const override;
            virtual IAction* Execute() override;
            virtual std::string GetAlias() const override;

        private:
            CTransitionAction* TransitionAction;
            CMatchRound Round;
            
    };
}

#endif