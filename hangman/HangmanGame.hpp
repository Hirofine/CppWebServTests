#ifndef HANGMAN_GAME_H_
#define HANGMAN_GAME_H_

// std

// Wt
#include <Wt/WContainerWidget.h>

// local
#include "Session.hpp"

using namespace Wt;

namespace Wt{
    class WStackedWidget;
    class WAnchor;
}

class HangmanWidget;
class HighScoresWidget;
class Session;

class HangmanGame : public WContainerWidget{
    public:
        HangmanGame();
        void handleInternalPath(const std::string &internalPath);
    private:
        WStackedWidget *mainStack_;
        HangmanWidget *game_;
        HighScoresWidget *scores_;
        WContainerWidget *links_;
        WAnchor *backToGameAnchor_;
        WAnchor *scoresAnchor_;

        Session session_;

        void onAuthEvent();
        void showGame();
        void showHighScores();
};

#endif //HANGMAN_GAME_H_