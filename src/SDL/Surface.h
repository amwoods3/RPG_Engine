#ifndef SURFACE_H
#define SURFACE_H

#include <SDL.h>
#include "SDL_image.h"
#include <string>
#include <iostream>

class Surface {
public:
    Surface(std::string image_path="");
    ~Surface();
    SDL_Surface * get_surface() {return surf_;}
    SDL_Texture * get_texture() {return tex_;}
    void set_texture(SDL_Texture * tex) {tex_ = tex;
        if (tex_ == NULL)
            std::cout << "Error: " << SDL_GetError() << std::endl;
        
    }

    void change_surface(SDL_Surface * surf) {
        if (surf_ != NULL) {
            SDL_FreeSurface(surf_);
            surf_ = NULL;
        }
        if (tex_ != NULL) {
            SDL_DestroyTexture(tex_);
            tex_ = NULL;
        }
        surf_ = surf;
    }
    void change_texture(SDL_Texture * tex) {
        // SDL_FreeTexture(tex_);
        tex_ = tex; }
private:
    SDL_Surface * surf_;
    SDL_Texture * tex_;
};

#endif

