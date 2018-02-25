#ifndef __MAGICSTACK_MODEL_ACTION_CONTROLLERACTION_H__
#define __MAGICSTACK_MODEL_ACTION_CONTROLLERACTION_H__

#include "../IAction.h"
#include <string>

namespace MagicStack
{
    struct IControllerActionExecutable;

    class CControllerAction : public IAction
    {
        public:
            CControllerAction(IControllerActionExecutable& controller, const std::string& action);
            ~CControllerAction() = default;

            virtual void Execute() override;

        private:
            IControllerActionExecutable& Controller;
            std::string Action;
    };
}

#endif