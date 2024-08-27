/*   #include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 4) {
        if (rank == 0) {
            cout << "Number of processors must be 4. Please Enter 4 " << endl;
        }
        MPI_Finalize();
        return 1;
    }
    int matrix[4][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {11, 13, 15, 17},
        {12, 14, 16, 18}
    };
    int indRow[4];
    for (int i = 0; i < 4; i++) {
        indRow[i] = matrix[rank][i];
    }
    int transposeRow[4];
    MPI_Alltoall(indRow, 1, MPI_INT, transposeRow, 1, MPI_INT, MPI_COMM_WORLD);
    cout << "Process ";
    cout << rank;
    cout << " has transposed row: ";
    for (int i = 0; i < 4; i++) {
        cout << transposeRow[i];
        cout << " ";
    }
    cout << endl;

    int transpose[4][4];

    MPI_Gather(transposeRow, 4, MPI_INT, transpose, 4, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        cout << "Transposed Matrix Are :";
        cout << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << transpose[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }
    MPI_Finalize();
    return 0;
}




*/




