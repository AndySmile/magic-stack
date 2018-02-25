#ifndef __MAGICSTACK_CONTROLLER_ICONTROLLERACTIONEXECUTABLE_H__
#define __MAGICSTACK_CONTROLLER_ICONTROLLERACTIONEXECUTABLE_H__

namespace MagicStack
{
    struct IControllerActionExecutable
    {
        virtual ~IControllerActionExecutable() = default;

        virtual void ExecuteControllerAction(const std::string& action) = 0;
    };
}

#endif