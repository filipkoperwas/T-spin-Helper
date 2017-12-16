#ifndef PIECEBOX_H
#define PIECEBOX_H

#include "GameObject.h"

class PieceBox : public GameObject
{
public:
    PieceBox(int x, int y, float size); //no need texture parameter since its always black box
    ~PieceBox() {};

    void update(); //probably will have to put piece in this function
    void render();

private:
    float boxSize;
    //Tpiece piece; //This is to render next piece in box, have not made class yet

};
#endif
