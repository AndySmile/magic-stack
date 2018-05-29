#ifndef __MAGICSTACK_MODEL_BASECARDACTION_H__
#define __MAGICSTACK_MODEL_BASECARDACTION_H__

#include "ICardAction.h"

namespace MagicStack
{
    class CBaseCardAction : public ICardAction
    {
        public:
            virtual ~CBaseCardAction() = default;

            virtual void Execute() override;
    };
}

#endif