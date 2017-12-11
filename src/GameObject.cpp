#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
    //load object texture
    objTexture = TextureManager::LoadTexture(textureSheet);

    //set initial position
    xpos = x;
    ypos = y;
}

void GameObject::update() {
    
    xpos++;
    ypos++;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
