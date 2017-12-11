#ifndef Map_H
#define Map_H
#include "Game.h"

/*! \class Map
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Map 
{
public:
    Map();
    ~Map();

    void loadMap(int arr[20][10]);
    void drawMap();

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

   int map[20][10];
};


#endif
