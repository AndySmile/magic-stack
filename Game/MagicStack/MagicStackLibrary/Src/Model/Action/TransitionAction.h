#ifndef __MAGICSTACK_MODEL_ACTION_TRANSITIONACTION_H__
#define __MAGICSTACK_MODEL_ACTION_TRANSITIONACTION_H__

#include "../IAction.h"
#include <string>

namespace MagicStack
{
    class CControllerTransition;

    class CTransitionAction : public IAction
    {
        public:
            CTransitionAction(CControllerTransition& transition, const std::string& alias);
            virtual ~CTransitionAction() = default;

            virtual void Execute() override;

        private:
            CControllerTransition& Transition;
            std::string Alias;
    };
}

#endif