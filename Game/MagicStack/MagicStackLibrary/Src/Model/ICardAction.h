#ifndef __MAGICSTACK_MODEL_ICARDACTION_H__
#define __MAGICSTACK_MODEL_ICARDACTION_H__

#include "IAction.h"
#include <string>

namespace MagicStack
{
    class CCard;

    struct ICardAction : public IAction
    {
        virtual ~ICardAction() = default;

        virtual void Apply(CCard* attack, CCard* defense) = 0;
        virtual std::string GetDescription() const = 0;
    };
}

#endif