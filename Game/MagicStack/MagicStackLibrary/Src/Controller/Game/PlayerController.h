#ifndef __MAGICSTACK_CONTROLLER_GAME_PLAYERCONTORLLER_H__
#define __MAGICSTACK_CONTROLLER_GAME_PLAYERCONTORLLER_H__

#include "IPlayerController.h"

namespace MagicStack
{
    struct ICardAction;
    class CCard;
    
    class CPlayerController : public IPlayerController
    {
        public:
            CPlayerController();
            ~CPlayerController() = default;

            virtual CCard* GetActiveCard() const override;
            virtual ICardAction* PickCardAction() const override;

        private:
            CCard* ActiveCard;
            ICardAction* DefaultAction;
    };
}

#endif