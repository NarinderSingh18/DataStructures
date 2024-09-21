/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <vector>

//get the value from a[i][j] but if it is out of bound then return 0
int getVal(std::vector<std::vector<int>>& zarr, int i, int j, int L, int H)
{
     if(i < 0 || i >= L || j < 0 || j >=H )
     {
         return 0;
     }
     else
     {
         return zarr[i][j];
     }
}


void findMaxBlock(std::vector<std::vector<int>>& zarr, int r, int c, int L, int H,int size, 
                  std::vector<std::vector<bool>>& cntarr, int& maxSize)
{
    if (r >= L || c >= H) return;

    cntarr[r][c] = true;
    size++;
    
    if(size > maxSize) maxSize = size;
    
    //search in 8 direction;
    int direction[][2] = { {-1,0},
                           {-1,-1},
                           {0,-1},
                           {1,-1},
                           {1,0},
                           {1,1},
                           {0,1},
                           {-1,1} };
                           
    for (int i = 0; i < 8; i++)
    {
        int newi = r + direction[i][0];
        int newj = c + direction[i][1];
        
        int val = getVal(zarr, newi, newj, L, H);
        
        //if value is not zero and it is not travered before, call again 
        if(val > 0 && cntarr[newi][newj] == false)
        {
            findMaxBlock(zarr, newi, newj, L, H, size, cntarr, maxSize);
        }
        
    }
     
    cntarr[r][c] = false;                   
    
}



int getMaxOnes(std::vector<std::vector<int>>& zarr, int rmax, int colmax)
{
    int maxsize = 0;
    int size = 0;
    
    std::vector<std::vector<bool>> cntarr(rmax, std::vector<bool>(colmax,false));
    for (int i = 0 ; i < rmax; i++)
    {
        for(int j = 0 ; j < colmax; j++)
        {
            if(zarr[i][j] == 1)
            {
                findMaxBlock(zarr, i, j , rmax, colmax, 0, cntarr, maxsize);
            }
        }
    }
    
    return maxsize;
}




int main()
{
    std::cout<<"Hello World" << std::endl;
    int maxRow = 5, maxCol = 5;
    
    
    //using array 
    //int zarr[][5] = { {1,1,0,0,0},
    //                  {0,1,1,0,0},
    //                  {0,0,1,0,1},
    //                  {1,0,0,0,1},
    //                  {0,1,0,1,1} };
    
    //initialize 2D with+ vector with default value 0
    //std::vector<std::vector<int>> zarr(maxRow, std::vector<int>(maxCol, 0));
    
    std::vector<std::vector<int>> zarr { {1,1,0,0,0},
                                         {0,1,1,0,0},
                                         {0,0,1,0,1},
                                         {1,0,0,0,1},
                                         {0,1,1,1,1} };
    
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            std::cout << zarr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    
    std::cout << "Nummber of maximium 1's are " << getMaxOnes(zarr, 5,5) << std::endl;

    return 0;
}