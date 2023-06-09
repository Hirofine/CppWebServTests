#ifndef HANGMAN_WIDGET_H_
#define HANGMAN_WIDGET_H

#include <vector>

#include <Wt/WContainerWidget.h>

class Session;
class WordWidget;
class ImagesWidget;
class LettersWidget;

class HangmanWidget: public Wt::WContainerWidget{
    public:
        HangmanWidget(const std::string &name);

        Wt::Signal<int>& scoreUpdated() {return scoreUpdated_;}
    private:
        Wt::WText       *title_;
        WordWidget      *word_;
        ImagesWidget    *images_;
        LettersWidget   *letters_;
        Wt::WText       *statusText_;
        Wt::WComboBox   *language_;
        Wt::WPushButton *newGameButton_;

        Wt::Signal<int> scoreUpdated_;
        std::string     name_;
        int             badGuesses_;

        void registerGuess(char c);
        void newGame();
};



#endif //HANGMAN_WIDGET_H_