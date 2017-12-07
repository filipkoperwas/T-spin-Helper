#ifndef TextureManager_H
#define TextureManager_H

#include "Game.h"
class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren);

private:
};

#endif
