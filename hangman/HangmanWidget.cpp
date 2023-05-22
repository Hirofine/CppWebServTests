#include "HangmanWidget.hpp"

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WAny.h>

#include "Session.hpp"
#include "Dictionary.hpp"
#include "WordWidget.hpp"
#include "ImagesWidget.hpp"
#include "LettersWidget.hpp"

using namespace Wt;

namespace {
    const int MaxGuesses = 9;
}

HangmanWidget::HangmanWidget(const std::string &name) : WContainerWidget(), name_(name), badGuesses_(0){
    setContentAlignment(AlignmentFlag::Center);

    title_ = addWidget(std::make_unique<WText>(tr("hangman.readyToPlay")));

    word_ = addWidget(std::make_unique<WordWidget>());
    statusText_ = addWidget(std::make_unique<WText>());
    images_ = addWidget(std::make_unique<ImagesWidget>(MaxGuesses));

    letters_ = addWidget(std::make_unique<LettersWidget>());
    letters_->letterPushed().connect(this, &HangmanWidget::registerGuess);

    language_ = addWidget(std::make_unique<WComboBox>());
    language_->addItem(tr("hangman.englishWords").arg(18957));
    language_->addItem(tr("hangman.dutchWords").arg(1688));

    addWidget(std::make_unique<WBreak>());

    newGameButton_ = addWidget(std::make_unique<WPushButton>(tr("hangman.newGame")));
    newGameButton_->clicked().connect(this, &HangmanWidget::newGame);

    letters_->hide();
}

void HangmanWidget::newGame(){
    WString title(tr("hangman.guessTheWord"));
    title_->setText(title.arg(name_));

    language_->hide();
    newGameButton_->hide();

    Dictionary dictionary = (Dictionary) language_->currentIndex();
    word_->init(RandomWord(dictionary));
    letters_->reset();
    badGuesses_ = 0;
    images_->showImage(badGuesses_);
    statusText_->setText("");
}

void HangmanWidget::registerGuess(char c){
    if(badGuesses_ < MaxGuesses){
        bool correct = word_->guess(c);

        if(!correct){
            ++badGuesses_;
            images_->showImage(badGuesses_);
        }
    }

    if (badGuesses_ == MaxGuesses){
        WString status = tr("hangman.youHang");
        statusText_->setText(status.arg(word_->word()));

        letters_->hide();
        language_->show();
        newGameButton_->show();

        scoreUpdated_.emit(-10);
    } else if (word_->won()){
        statusText_->setText(tr("hangman.youWin"));
        images_->showImage(ImagesWidget::HURRAY);

        letters_->hide();
        language_->show();
        newGameButton_->show();

        scoreUpdated_.emit(20-badGuesses_);
    }
}