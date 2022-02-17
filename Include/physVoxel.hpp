#ifndef VOXELS
#define VOXELS

class Voxels
{
public:    
    int count = 0;
    int posVoxs[812][2]{};
    char voxels[812];

    bool dir[812]{};

    void RemoveVox();
    void RemoveVox(int y, int x, bool hr);
    void CreateVox(int y, int x, char symb);

    void Update();

    bool Collision(bool &L, bool &R, bool &U, bool &D, int i);

    bool Fall(int i);
};

#endif