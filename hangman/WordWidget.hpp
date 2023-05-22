#ifndef WORD_WIDGET_H_
#define WORD_WIDGET_H_
//std

// Wt
#include <Wt/WContainerWidget.h>

//local

using namespace Wt;
class WordWidget : public WContainerWidget{
    public: 
        WordWidget();
        std::wstring word() const {return word_;}

        void init(const std::wstring &word);
        bool guess(wchar_t c);
        bool won();
    private:
        std::vector<WText *>    wordLetters_;
        std::wstring            word_;

        unsigned                displayedLetters_;
};


#endif //WORD_WIDGET_H_