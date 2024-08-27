#include <iostream>
#include <mpi.h>
#include <vector>
#include <random>
#include "server.h"

using namespace std;

void initializeMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        cout << "Client Running..." << endl;
        int m, n;
        cout << "Enter the number of rows: ";
        cin >> m;
        cout << "Enter the number of columns: ";
        cin >> n;

        int** matrixArray = new int* [m];
        for (int i = 0; i < m; ++i) {
            matrixArray[i] = new int[n];
        }

        initializeMatrix(matrixArray, m, n);

        for (int i = 0; i < m; ++i) {
            MPI_Bcast(matrixArray[i], n, MPI_INT, 0, MPI_COMM_WORLD);
        }

        cout << "Original matrix:" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrixArray[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < m; ++i) {
            sortArray(matrixArray[i], n);
        }

        cout << "Sorted matrix:" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrixArray[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < m; ++i) {
            delete[] matrixArray[i];
        }
        delete[] matrixArray;
    }
    else {
        int m, n;
        MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        int** matrixArray = new int* [m];
        for (int i = 0; i < m; ++i) {
            matrixArray[i] = new int[n];
            MPI_Bcast(matrixArray[i], n, MPI_INT, 0, MPI_COMM_WORLD);
        }
        for (int i = 0; i < m; ++i) {
            delete[] matrixArray[i];
        }
        delete[] matrixArray;
    }

    MPI_Finalize();
    return 0;
}
