#include <conio.h>
#include "Player.hpp"
#include "physVoxel.hpp"
#include "field.hpp"

Player::Player(int y, int x, char symb) {
    pos[0] = y;
    pos[1] = x;
    this->symb = symb;
}

void Player::Input(Voxels &voxs) {
    if (_kbhit())
        switch (_getch())
        {
        //Control
        case 'w':
            if (pos[0] - 1 != 0)   
                pos[0] -= 1;
            break;
        case 'a':
            if (pos[1] - 1 != 0)   
                pos[1] -= 1;
            break;
        case 's':
            if (pos[0] + 1 != Field::height - 1)             
                pos[0] += 1;           
            break;
        case 'd':
            if (pos[1] + 1 != Field::weight - 1)
                pos[1] += 1;
            break;        
        //paste voxel
        case 'q':
            voxs.CreateVox(pos[0], pos[1], '%');
            break;
        case 'e':
            voxs.CreateVox(pos[0], pos[1], '~');
            break;
        case 32:
            voxs.CreateVox(pos[0], pos[1], '#');
            break;
        case 'z':
            voxs.RemoveVox(pos[0], pos[1], false);
            break;
        case 'x':
            voxs.RemoveVox(pos[0], pos[1], true);
            break;
        case 'r':
            voxs.RemoveVox();
            break;
        }


    while (_kbhit()) _getch();
}