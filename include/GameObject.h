#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Game.h"

/*! \class GameObject
 *  \brief Brief class description
 *
 *  Detailed description
 */
class GameObject
{
public:
    GameObject() {};//needed for child class constructors
    GameObject(const char* textureSheet, int x, int y);
    virtual ~GameObject();

    virtual void update();
    virtual void render();

protected:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};

#endif
