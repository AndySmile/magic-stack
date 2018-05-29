#include "BaseMenuController.h"
#include <iostream>

namespace MagicStack
{
    void CBaseMenuController::Render() const
    {
        this->View.DisplayMenu(this->Menu);
    }

    IAction* CBaseMenuController::Execute()
    {
        unsigned int selectedMenuId = 0;

        do {
            std::cout << "Your selection: ";
            std::cin >> selectedMenuId;
        } while (!this->Menu.IsValidItemId(selectedMenuId));

        return this->Menu.GetAction(selectedMenuId);
    }
}