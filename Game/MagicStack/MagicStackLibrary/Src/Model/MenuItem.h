#ifndef __MAGICSTACK_MODEL_MENUITEM_H__
#define __MAGICSTACK_MODEL_MENUITEM_H__

#include <string>

namespace MagicStack
{
    struct IAction;

    struct SMenuItem
    {
        SMenuItem(const unsigned int id, const std::string& label, IAction* action);
        ~SMenuItem() = default;

        unsigned int Id;
        IAction* Action;
        std::string Label;
    };
}

#endif