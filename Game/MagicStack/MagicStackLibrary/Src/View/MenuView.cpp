#include "MenuView.h"
#include "../Model/Menu.h"
#include <iostream>

namespace MagicStack
{
    void CMenuView::DisplayHeadline() const
    {
        this->DisplayMessageBox("Magic Stack Menu Prototype - Build " __DATE__ " " __TIME__);
        this->DisplayNewLine();
    }

    void CMenuView::DisplayWelcome() const
    {
        this->DisplayArrowText("Welcome to the Magic Stack!");
        this->DisplayNewLine();
        this->DisplayArrowText("You're in the main menu right now!");
        this->DisplayArrowText("Please choose what you're like to do right now!");
        this->DisplayNewLine();
    }

    void CMenuView::DisplayMenu(const CMenu& menu) const
    {
        const TMenuList& list = menu.GetItemList();

        for (auto it = list.begin(); it != list.end(); ++it) {
            std::cout << "[" << it->Id << "] " << it->Label << std::endl;
        }

        this->DisplayNewLine();
    }
}