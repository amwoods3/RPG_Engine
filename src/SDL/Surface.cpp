#include "Surface.h"

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

Surface::Surface(std::string image_path) {
    tex_ = NULL;
    if (image_path == "") {
        surf_ = NULL;
    }
    else {
        surf_ = IMG_Load(image_path.c_str());
        if (surf_ == NULL) {
            std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
        }
    }
}


Surface::~Surface() {
    SDL_FreeSurface(surf_);
    SDL_DestroyTexture(tex_);
}
