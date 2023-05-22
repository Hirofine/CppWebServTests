// std

// Wt
#include <Wt/WImage.h>
#include <Wt/WAny.h>

// local
#include "ImagesWidget.hpp"

ImagesWidget::ImagesWidget(int maxGuesses){
    for(int i = 0; i <= maxGuesses; i++){
        std::string fname = "icons/hangman";
        fname += std::to_string(i) + ".jpg";
        WImage *theImage = addWidget(std::make_unique<WImage>(fname));
        images_.push_back(theImage);

        theImage->hide();
    }

    WImage *hurray = addWidget(std::make_unique<WImage>("icons/hangmanhurray.jpg"));
    hurray->hide();
    images_.push_back(hurray);

    image_ = 0;
    showImage(maxGuesses);
}

void ImagesWidget::showImage(int index){
    image(image_)->hide();
    image_ = index;
    image(image_)->show();
}

WImage *ImagesWidget::image(int index) const{
    return index == HURRAY ? images_.back() : images_[index];
}