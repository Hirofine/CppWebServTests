#ifndef HIGH_SCORES_WIDGET_H_
#define HIGH_SCORES_WIDGET_H_

// std

// Wt
#include <Wt/WContainerWidget.h>

// local

using namespace Wt;

class Session;

class HighScoresWidget : public WContainerWidget{
    public:
        HighScoresWidget(Session *session);
        void update();
    private:
        Session *session_;
};

#endif //HIGH_SCORES_WIDGET_H_