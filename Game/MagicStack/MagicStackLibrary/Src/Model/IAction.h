#ifndef __MAGICSTACK_MODEL_IACTION_H__
#define __MAGICSTACK_MODEL_IACTION_H__

namespace MagicStack
{
    struct IAction
    {
        virtual ~IAction() = default;

        virtual void Execute() = 0;
    };
}

#endif