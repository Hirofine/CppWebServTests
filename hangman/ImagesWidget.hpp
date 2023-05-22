#ifndef IMAGES_WIDGET_H_
#define IMAGES_WIDGET_H_

// std
#include <vector>

// Wt
#include <Wt/WContainerWidget.h>

using namespace Wt;

class ImagesWidget : public WContainerWidget{
    public:
        static const int HURRAY;

        ImagesWidget(int maxGuesses);

        void showImage(int index);
        int currentImage() const {return image_;}

    private:
        std::vector<WImage*> images_;
        int image_;

        WImage *image(int index) const;
};


#endif //IMAGES_WIDGET_H_