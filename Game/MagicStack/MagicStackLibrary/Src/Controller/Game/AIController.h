#ifndef __MAGICSTACK_CONTROLLER_GAME_AICONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_GAME_AICONTROLLER_H__

#include "IPlayerController.h"

namespace MagicStack
{
    class CAIController : public IPlayerController
    {
        public:
            CAIController();
            ~CAIController() = default;

            virtual CCard* GetActiveCard() const override;
            virtual ICardAction* PickCardAction() const override;

        private:
            CCard* ActiveCard;
            ICardAction* DefaultAction;
    };
}

#endif