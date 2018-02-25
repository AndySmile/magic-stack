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

    void CMenuView::DisplayBoxLine() const
    {
        std::cout << "##################################################################" << std::endl;
    }

    void CMenuView::DisplayBoxText(const std::string& text) const
    {
        std::cout << "##### " << text << std::endl;
    }

    void CMenuView::DisplayDotLine() const
    {
        std::cout << "...................................................................................................................................." << std::endl;
    }

    void CMenuView::DisplayRoundLine() const
    {
        std::cout << "*************************************************************************************************************************************" << std::endl;
    }

    void CMenuView::DisplayArrowText(const std::string& text) const
    {
        std::cout << ">>> " << text << std::endl;
    }

    void CMenuView::DisplayNewLine() const
    {
        std::cout << std::endl;
    }

    void CMenuView::DisplayMessageBox(const std::string& message) const
    {
        this->DisplayBoxLine();
        this->DisplayBoxText("");
        this->DisplayBoxText(message);
        this->DisplayBoxText("");
        this->DisplayBoxLine();
    }
}