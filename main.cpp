#include "field.hpp"
#include "Player.hpp"
#include "physVoxel.hpp"

int main()
{
    Field gField('#', ' ');
    Player player(5, 5, 'P');
    Voxels voxs;

    while(true)
    {
        gField.FillField();
        gField.Update(voxs);
        gField.Update(player.pos[0], player.pos[1], player.symb);
        voxs.Update();
        player.Input(voxs);
        gField.Draw(voxs);
        
    }

    return 0;
}