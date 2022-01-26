#ifndef FIELD
#define FIELD
#include "voxels/physVoxel.hpp"

class Field
{
public:
    static const int weight = 40;
    static const int height = 20;

private:
    char wall;
    char air; 
    char field[height][weight];

public:
    Field(char Wall, char air);

    void gotoxy(short x, short y);

    void FillField();
    void Draw(Voxels &voxs);
    void Update(int y, int x, char symb);
    void Update(Voxels &voxs);

    void SetPos();
    void GetPos();
};
#endif