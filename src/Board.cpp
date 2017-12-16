#include "../include/Board.h"
#include "../include/TextureManager.h"

//Constants
#define ROWS 20
#define COLUMNS 10
/*
   This class draws a board of the tetris board. It
   1 = blue
   2 = orange
   3 = red
   4 = green
   5 = teal
   6 = purple
   7 = yellow
*/
int test[20][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,4,0,0,0,0},
    {7,7,0,0,0,4,4,7,7,0},
    {7,7,5,5,5,5,4,7,7,0}
};

Board::Board() {
    empty = TextureManager::LoadTexture("assets/empty_square.png");
    blue = TextureManager::LoadTexture("assets/blue_square.png");
    orange = TextureManager::LoadTexture("assets/orange_square.png");
    green = TextureManager::LoadTexture("assets/green_square.png");
    red = TextureManager::LoadTexture("assets/red_square.png");
    teal = TextureManager::LoadTexture("assets/teal_square.png");
    purple = TextureManager::LoadTexture("assets/purple_square.png");
    yellow = TextureManager::LoadTexture("assets/yellow_square.png");



    loadBoard(test);

    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h= 32;
    dest.w = 32;
    dest.h = 32;

    dest.x = 0;
    dest.y = 0;
}

void Board::loadBoard(int arr[20][10]) {
    for (int row = 0; row < ROWS; row++) {
        for(int column = 0; column < COLUMNS; column++) {
            board[row][column] = arr[row][column];
        }
        
    }

}

void Board::drawBoard() {
    int type = 0;
    for (int row = 0; row < ROWS; row++) {
        for(int column = 0; column < COLUMNS; column++) {
            type = board[row][column];
            dest.x = column * 32 + 100;
            dest.y = row * 32;

            switch (type) {
                case 0:
                    TextureManager::Draw(empty, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(blue, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(orange, src, dest);
                    break;
                case 3:
                    TextureManager::Draw(green, src, dest);
                    break;
                case 4:
                    TextureManager::Draw(red, src, dest);
                    break;
                case 5:
                    TextureManager::Draw(teal, src, dest);
                    break;
                case 6:
                    TextureManager::Draw(purple, src, dest);
                    break;
                case 7:
                    TextureManager::Draw(yellow, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}

Board::~Board() {
    SDL_DestroyTexture(empty);
    SDL_DestroyTexture(blue);
    SDL_DestroyTexture(orange);
    SDL_DestroyTexture(green);
    SDL_DestroyTexture(red);
    SDL_DestroyTexture(teal);
    SDL_DestroyTexture(purple);
    SDL_DestroyTexture(yellow);
}
