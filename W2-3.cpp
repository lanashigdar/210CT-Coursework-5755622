#include <iostream>

using namespace std;

int W2_3()

{
/*
PSEUDOCODE:

    ADDMATRIX(matrixA, matrixB)
        FOR i to size of matrix row
            FOR j to size of matrix column
                addition[i][j] = matrixA[i,j] + matrixB[i,j]
        RETURN addition
        END
Run-time: o(n^2)

    SUBMATRIX(matrixA, matrixB)
        FOR i to size of matrix row
            FOR j to size of matrix column
                subtraction[i][j] = matrixA[i,j] - matrixB[i,j]
        RETURN subtraction
        END
Run-time: o(n^2)

    MULTMATRIX(matrixA, matrixB)
        FOR i to size of matrix row
            FOR j to size of matrix column
                FOR k to iterate over a row or column of matrixA or matrixB
                    multiplication[i][j] = multiplication[i,j] + matrixA[i,k] * matrixB[k,j]
        RETURN multiplication
        END
Run-time: o(n^2)

compute A = B*C-2*(B+C):

    R = B*C+2*(B+C)
    R1 <- MULTMATRIX(B,C)
    R2 <- ADDMATRIX(B,C)
    R3 <- MULTNRMATRIX(R2,2)
    R <- ADDMATRIX(R1,R3)

Run-time: o(n^2)

*/

    return 0;
}
