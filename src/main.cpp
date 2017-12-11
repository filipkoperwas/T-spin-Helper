#include "../include/Game.h"
#define FPS 60
#define FRAME_DELAY (1000 / FPS)

Game *game = nullptr;

int main(int argc, const char *argv[])
{
    game = new Game();

    Uint32 frameStart;
    int frameTime;

    game->init("T-Spin-Helper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while(game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    game->clean();
    return 0;
}
             
