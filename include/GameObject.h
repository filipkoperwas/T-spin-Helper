#ifndef GameObject_H
#define GameObject_H
#include "Game.h"

/*! \class GameObject
 *  \brief Brief class description
 *
 *  Detailed description
 */
class GameObject
{
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void update();
    void render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};

#endif
