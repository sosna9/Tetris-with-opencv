#include "Pieces.h"

// Pieces definition
char mPieces[7]     //kind
            [4]     //rotation
            [5]     //horizontal 
            [5]=    //and vertical blocks
{
    // Square
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },

    // I
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
      ,
    // L
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // L mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // T
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
};


// correction to 'spawning' new blocks
int mPiecesInitialPosition  [7 /*kind*/]
                            [4 /* rotation*/]
                            [2 /* position*/] =
{
    // Square boi 
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
       },
    // long straight one
      {
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}
       },
    // L
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    // L but mirrored
      {
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}
       },
    // N  or Z
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    // N mirrored
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    //space invader ship
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
};
// it turns out those blocks have actual names xD 'Z''s Cleveland and chonky square is called Smashboy

/*
Return the type of a block (0 = no-block, 1 = normal block, 2 = pivot block)
*/
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY];//checks if point is taken, empty, or is center of rotation
}

int Pieces::GetXInitialPosition(int pPiece, int pRotation) //gets x coordinate of block according to board, to place it when its created
{
    return mPiecesInitialPosition[pPiece][pRotation][0]; 
}
int Pieces::GetYInitialPosition(int pPiece, int pRotation)// same but y
{
    return mPiecesInitialPosition[pPiece][pRotation][1]; 
}

