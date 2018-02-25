#include "BaseView.h"
#include <iostream>

namespace MagicStack
{
    void CBaseView::DisplayBoxLine() const
    {
        std::cout << "##################################################################" << std::endl;
    }

    void CBaseView::DisplayBoxText(const std::string& text) const
    {
        std::cout << "##### " << text << std::endl;
    }

    void CBaseView::DisplayDotLine() const
    {
        std::cout << "...................................................................................................................................." << std::endl;
    }

    void CBaseView::DisplayRoundLine() const
    {
        std::cout << "*************************************************************************************************************************************" << std::endl;
    }

    void CBaseView::DisplayArrowText(const std::string& text) const
    {
        std::cout << ">>> " << text << std::endl;
    }

    void CBaseView::DisplayNewLine() const
    {
        std::cout << std::endl;
    }

    void CBaseView::DisplayMessageBox(const std::string& message) const
    {
        this->DisplayBoxLine();
        this->DisplayBoxText("");
        this->DisplayBoxText(message);
        this->DisplayBoxText("");
        this->DisplayBoxLine();
    }
}