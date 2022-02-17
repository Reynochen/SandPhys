#ifndef PLAYER
#define PLAYER
#include "physVoxel.hpp"

class Player
{
public:
    //Pos Y/X
    int pos[2];
    char symb;

    Player(int y, int x, char symb);

    void Input(Voxels &voxs);
};
#endif