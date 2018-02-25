#include "MenuItem.h"

namespace MagicStack
{
    SMenuItem::SMenuItem(const unsigned int id, const std::string& label, IAction* action)
        : Id(id)
        , Label(label)
        , Action(action)
    {
    }
}