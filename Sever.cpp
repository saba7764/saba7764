//#include <mpi.h>
//#include <iostream>
//#include "server.h"
//
//using namespace std;
//void sortArray(int arr[], int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int findMin(int arr[], int size) {
//    int min = arr[0];
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] < min) {
//            min = arr[i];
//        }
//    }
//    return min;
//}
//``
//
//int findMax(int arr[], int size) {
//    int max = arr[0];
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    return max;
//}
//
//
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    if (rank == 0) {
//        std::cout << "Server is running..." << std::endl;
//    }
//
//    MPI_Finalize();
//    return 0;
//}
