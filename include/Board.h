#ifndef Board_H
#define Board_H
#include "Game.h"

/*! \class Map
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Board 
{
public:
    Board();
    ~Board();

    void loadBoard(int arr[20][10]);
    void drawBoard();

private:

   SDL_Rect src, dest;
   SDL_Texture* empty;
   SDL_Texture* blue;
   SDL_Texture* orange;
   SDL_Texture* green;
   SDL_Texture* red;
   SDL_Texture* teal;
   SDL_Texture* purple;
   SDL_Texture* yellow;

   int board[20][10];
};


#endif
