#include "../include/PieceBox.h"
#include "../include/TextureManager.h"

PieceBox::PieceBox(int x, int y, float size) {
    objTexture = TextureManager::LoadTexture("assets/next_square_box.png");
    xpos = x;
    ypos = y;
    boxSize = size;
}

void PieceBox::update() {
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * boxSize;
    destRect.h = srcRect.h * boxSize;
}

void PieceBox::render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

