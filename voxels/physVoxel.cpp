#include "physVoxel.hpp"
#include "field.hpp"

void Voxels::RemoveVox(int y, int x, bool hr)
{
    for (int i = 0; i < count; i++)
        if (posVoxs[i][0] == y && posVoxs[i][1] == x)
        {
            posVoxs[i][0] = posVoxs[count - 1][0];
            posVoxs[i][1] = posVoxs[count - 1][1];
            voxels[i] = voxels[count - 1];
            count--;
            break;
        }
        else if (posVoxs[i][0] == y && hr)
        {
            posVoxs[i][0] = posVoxs[count - 1][0];
            posVoxs[i][1] = posVoxs[count - 1][1];
            voxels[i] = voxels[count - 1];
            count--;
        }    
}
void Voxels::RemoveVox() { count = 0; }

void Voxels::CreateVox(int y, int x, char symb)
{
    bool overlap = false;
    for (int i = 0; i < count; i++)
        if (y == posVoxs[i][0] && x == posVoxs[i][1]) {
            overlap = true;
            break;       
        }
           
    if (!overlap)
    {   
        dir[count] = 0; 
        voxels[count] = symb;
        posVoxs[count][0] = y;
        posVoxs[count][1] = x;
        count++;
    }    
}

bool Voxels::Collision(bool &L, bool &R, bool &U, bool &D, int i)
{
    for (int j = 0; j < count; j++) 
    {
        if(posVoxs[i][1] + 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0] || posVoxs[i][1] + 1 == Field::weight - 1) {
            R = true;
        }
        if(posVoxs[i][1] - 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0] || posVoxs[i][1] - 1 == 0) {
            L = true;
        }

        if(posVoxs[i][0] - 1 == posVoxs[j][0] && posVoxs[i][1] == posVoxs[j][1] || posVoxs[i][0] - 1 == 0) {
            U = true;
        }
        if(posVoxs[i][0] + 1 == posVoxs[j][0] && posVoxs[i][1] == posVoxs[j][1] || posVoxs[i][0] + 1 == Field::height - 1) {
            D = true;
        }
    }
    return R || L || U || D;
}

void Voxels::Update()
{
    for (int i = 0; i < count; i++)
        switch (voxels[i]) 
        {
        case '%': {
            bool L, R, U, D{false};
            bool waterD = false;
            Collision(L, R, U, D, i);
            if(D) {
                //Phys sand
                bool collRD = false;
                bool collLD = false;

                int lastX;
                int lastY;

                for (int j = 0; j < count; j++)
                    if (posVoxs[i][0] + 1 == posVoxs[j][0] && posVoxs[i][1] == posVoxs[j][1])
                        if (voxels[j] == '~') {
                            lastX = posVoxs[i][1];
                            lastY = posVoxs[i][0];

                            posVoxs[i][1] = posVoxs[j][1];
                            posVoxs[i][0] = posVoxs[j][0];

                            posVoxs[j][1] = lastX;
                            posVoxs[j][0] = lastY;
                            break; }                        
                        else
                            break;

                for (int j = 0; j < count; j++) {
                    if (posVoxs[i][1] + 1 == posVoxs[j][1] && posVoxs[i][0] + 1 == posVoxs[j][0])
                        collRD = true;
                    else if (posVoxs[i][1] - 1 == posVoxs[j][1] && posVoxs[i][0] + 1 == posVoxs[j][0])
                        collLD = true;
                }

                if (!collRD && posVoxs[i][1] + 1 != Field::weight - 1 && posVoxs[i][0] + 1 != Field::height - 1)
                    posVoxs[i][1] += 1;
                else if(!collLD && posVoxs[i][1] - 1 != 0 && posVoxs[i][0] + 1 != Field::height - 1) 
                    posVoxs[i][1] -= 1;  
                /////
            }
            
            if(!D){
                posVoxs[i][0] += 1;
            }

            break;}

        case '~': {
            bool L, R, U, D{false};
            char retSymb;
            Collision(L, R, U, D, i);
            
            //Phys water
            bool collR = false;
            bool collL = false;
            for (int j = 0; j < count; j++) {
                switch (dir[i])
                {                        
                    case 1:
                        if (posVoxs[i][1] + 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0] || posVoxs[i][1] + 1 == Field::weight - 1)
                            dir[i] = 0;
                        break;

                    case 0:
                        if (posVoxs[i][1] - 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0] || posVoxs[i][1] - 1 == 0)
                            dir[i] = 1;
                        break;
                }

                if (posVoxs[i][1] + 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0])
                    collR = true;
                else if (posVoxs[i][1] - 1 == posVoxs[j][1] && posVoxs[i][0] == posVoxs[j][0])
                    collL = true;
            }
            
            if (dir[i] && posVoxs[i][1] + 1 != Field::weight - 1 && !collR)
                posVoxs[i][1] += 1;
            else if(!dir[i] && posVoxs[i][1] - 1 != 0 && !collL)
                posVoxs[i][1] -= 1;
            /////

            if(!D){
                posVoxs[i][0] += 1;
            }

            break;}

        } 

}

