// std

// Wt
#include <Wt/WPushButton.h>
#include <Wt/WTable.h>
#include <Wt/WApplication.h>
#include <Wt/WEvent.h>
#include <Wt/WAny.h>

// local
#include "LettersWidget.hpp"

using namespace Wt;
LettersWidget::LettersWidget() : WCompositeWidget(){
    impl_ = new WTable();
    setImplementation(std::unique_ptr<WTable>(impl_));

    impl_->resize(13*30,WLength::Auto);

    for(unsigned int i = 0; i < 26; ++i){

    }
}

LettersWidget::~LettersWidget(){
    for(auto &connection : connections_){
        connection.disconnect();
    }
}

void LettersWidget::processButton(WPushButton *b){
    b->disable();
    letterPushed_.emit(b->text().toUTF8()[0]);
}

void LettersWidget::processButtonPushed(const WKeyEvent &e, WPushButton *b){
    if(isHidden())
        return;
    
    if(e.key() == static_cast<Key>(b->text().toUTF8()[0]))
        processButton(b);
}

void LettersWidget::reset(){
    for(auto& letterButton : letterButtons_)
        letterButton->enable();
    
    show();
}
