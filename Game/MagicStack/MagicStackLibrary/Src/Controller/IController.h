#ifndef __MAGICSTACK_CONTROLLER_ICONTROLLER_H__
#define __MAGICSTACK_CONTROLLER_ICONTROLLER_H__

#include <string>

namespace MagicStack
{
    struct IAction;
    class CControllerTransition;

    struct IController
    {
        virtual ~IController() = default;

        virtual void Init(CControllerTransition& transition) = 0;
        virtual void Render() const = 0;
        virtual IAction* Execute() const = 0;
        virtual void OnEnter() = 0;
        virtual void OnLeave() = 0;
        virtual std::string GetAlias() const = 0;
    };
}

#endif
