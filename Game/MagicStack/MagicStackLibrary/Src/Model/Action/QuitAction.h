#ifndef __MAGICSTACK_MODEL_ACTION_QUITACTION_H__
#define __MAGICSTACK_MODEL_ACTION_QUITACTION_H__

#include "../IAction.h"

namespace MagicStack
{
    class CControllerTransition;

    class CQuitAction : public IAction
    {
        public:
            CQuitAction(CControllerTransition& transition);
            virtual ~CQuitAction() = default;

            virtual void Execute() override;

        private:
            CControllerTransition& Transition;
    };
}

#endif