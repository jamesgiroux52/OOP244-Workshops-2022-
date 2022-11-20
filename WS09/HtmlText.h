/*************************************************************
// File    htmlText.h
// Version 1.0
// Date    November 19, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// HtmlText class
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 19, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"

namespace sdds {
    class HtmlText : public Text{
        char* m_title{};
    public:
        HtmlText(const char* title = nullptr);
        HtmlText& operator=(const HtmlText& H);
        HtmlText(const HtmlText& html);
        virtual ~HtmlText();
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_HTMLTEXT_H_
