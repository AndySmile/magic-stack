#ifndef __MAGICSTACK_MODEL_CARDACTION_FIREACTION_H__
#define __MAGICSTACK_MODEL_CARDACTION_FIREACTION_H__

#include "../BaseCardAction.h"

namespace MagicStack
{
    class CCard;

    class CFireAction : public CBaseCardAction
    {
        public:
            CFireAction() = default;
            virtual ~CFireAction() = default;

            virtual void Apply(CCard* attack, CCard* defense) override;
            virtual std::string GetDescription() const override;

        private:
            static const int FireMultiplier = 2;
    };
}

#endif