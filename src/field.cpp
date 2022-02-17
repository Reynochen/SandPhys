#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include "field.hpp"
#include "physVoxel.hpp"

Field::Field(char wall, char air) {    
    this->wall = wall;
    this->air = air;
    Field::FillField();        
}


void Field::gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Field::FillField() {
    for(int y = 0; y < height; y++)
        for(int x = 0; x < weight; x++)
        {
            if(x == 0 || y == 0 || x == weight - 1 || y == height - 1)
            {
                field[y][x] = this->wall;
            }
            else
                field[y][x] = this->air;
        }
}


void Field::Update(int y, int x, char symb) 
{
    field[y][x] = symb;
}
void Field::Update(Voxels &voxs) 
{
    for (int i = 0; i < voxs.count; i++)
    {
        field[voxs.posVoxs[i][0]][voxs.posVoxs[i][1]] = voxs.voxels[i]; 
    }
}


void Field::Draw(Voxels &voxs) {
    //Draw field
    std::string Frame;
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < weight; x++)
            Frame += field[y][x];
        Frame += '\n';
    }
    gotoxy(0, 0);
    std::cout << Frame;
    voxs.count != 0 ? std::cout << "Voxels count:\t" << voxs.count << "    " << '\n' << "Pos last vox: \tY:" << voxs.posVoxs[voxs.count - 1][0] << "\tX:" << voxs.posVoxs[voxs.count - 1][1] << "    ": 
                        std::cout << "Voxels count:\t" << "0  \n" << "Pos last vox: \tY:" << "0   " << "\tX:" << "0   ";
    std::cout << "\n\nControls: \n\tWalk: WASD\n\tSand: Q \n\tWater: E\n\tBarrier: Space\n\tRemove voxs: Z/X";

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
