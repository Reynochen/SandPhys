#include "field.hpp"
#include "Player/Player.hpp"
#include "voxels/physVoxel.hpp"

int main()
{
    Field gField('#', ' ');
    Player player(5, 5, 'P');
    Voxels voxs;

    while(true)
    {
        player.Input(voxs);
        gField.FillField();
        gField.Update(voxs);
        gField.Update(player.pos[0], player.pos[1], player.symb);
        voxs.Update();
        gField.Draw(voxs);
        
    }

    return 0;
}