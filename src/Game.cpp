#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/GameObject.h"
#include "../include/Map.h"

SDL_Renderer* Game::renderer = nullptr;

GameObject* player;
Map* map;

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window) {
            std::cout << "Window Created!" << std::endl;
        }
        Game::renderer = SDL_CreateRenderer(window, -1, 0);
        if(Game::renderer) {
            SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    player = new GameObject("assets/blue_square.png", 0, 0);
    map = new Map();

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    player->update();
}

void Game::render() {
    SDL_RenderClear(Game::renderer);
    map->drawMap();
    player->render();
    SDL_RenderPresent(Game::renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}


