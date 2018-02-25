#include "Menu.h"
#include "IAction.h"

namespace MagicStack
{
    void CMenu::AddItem(const unsigned int id, const std::string& label, IAction* action)
    {
        SMenuItem item(id, label, action);

        this->AddItem(item);
    }

    void CMenu::AddItem(const SMenuItem& item)
    {
        this->ItemList.push_back(item);
    }

    const TMenuList& CMenu::GetItemList() const
    {
        return this->ItemList;
    }

    IAction* CMenu::GetAction(const unsigned int id) const
    {
        for (auto it = this->ItemList.begin(); it != this->ItemList.end(); ++it) {
            if (it->Id == id) {
                return it->Action;
            }
        }

        return nullptr;
    }

    bool CMenu::IsValidItemId(const unsigned int id) const
    {
        if (this->ItemList.size() > 0) {
            for (auto it = this->ItemList.begin(); it != this->ItemList.end(); ++it) {
                if (it->Id == id) {
                    return true;
                }
            }
        }

        return false;
    }
}