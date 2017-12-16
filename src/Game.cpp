#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/GameObject.h"
#include "../include/Board.h"
#include "../include/PieceBox.h"
#include <vector>

SDL_Renderer* Game::renderer = nullptr;

std::vector<GameObject*> gObjects;

Board* board;

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

    board = new Board();
    PieceBox* holdBox = new PieceBox(10, 50, 2.5);
    gObjects.push_back(holdBox);
    PieceBox* nextBox1 = new PieceBox(450, 50, 2.25);
    gObjects.push_back(nextBox1);
    PieceBox* nextBox2 = new PieceBox(450, 125, 2);
    gObjects.push_back(nextBox2);
    PieceBox* nextBox3 = new PieceBox(450, 200, 2);
    gObjects.push_back(nextBox3);
    PieceBox* nextBox4 = new PieceBox(450, 270, 2);
    gObjects.push_back(nextBox4);
    PieceBox* nextBox5 = new PieceBox(450, 350, 2);
    gObjects.push_back(nextBox5);
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
    for(GameObject* object : gObjects) {
        object->update();
    }
}

void Game::render() {
    SDL_RenderClear(Game::renderer);
    board->drawBoard();
    for(GameObject* object : gObjects) {
        object->render();
    }
    SDL_RenderPresent(Game::renderer);
}

void Game::clean() {
    delete(board);
    std::cout << "Cleaned board" << std::endl;
    for(GameObject* object : gObjects) {
        delete(object);
    }
    gObjects.clear();
    std::cout << "Cleaned GObjects" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}


