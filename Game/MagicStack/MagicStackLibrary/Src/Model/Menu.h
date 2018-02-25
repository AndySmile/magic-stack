#ifndef __MAGICSTACK_MODEL_MENU_H__
#define __MAGICSTACK_MODEL_MENU_H__

#include "MenuItem.h"
#include <vector>

namespace MagicStack
{
    typedef std::vector<SMenuItem> TMenuList;

    struct IAction;

    class CMenu
    {
        public:
            CMenu() = default;
            ~CMenu() = default;

            void AddItem(const unsigned int id, const std::string& label, IAction* action);
            void AddItem(const SMenuItem& item);
            const TMenuList& GetItemList() const;
            IAction* GetAction(const unsigned int id) const;
            bool IsValidItemId(const unsigned int id) const;

        private:
            TMenuList ItemList;
    };
}

#endif