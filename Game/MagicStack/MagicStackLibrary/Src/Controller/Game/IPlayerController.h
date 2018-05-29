#ifndef __MAGICSTACK_CONTROLLER_GAME_IPLAYERCONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_GAME_IPLAYERCONTROLLER_H__

namespace MagicStack
{
    struct ICardAction;
    class CCard;

    struct IPlayerController
    {
        ~IPlayerController() = default;

        virtual ICardAction* PickCardAction() const = 0;
        virtual CCard* GetActiveCard() const = 0;
    };
}

#endif