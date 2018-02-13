//
// Created by Hz Yang on 2018/2/8.
//
#include <iostream>
#include "sortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    const int N = 20000;
    int *arr = sortTestHelper::generateRandomArray(N, 0, 100000);
    selectionSort(arr, N);
    sortTestHelper::printArray(arr, N);
    delete[] arr;

    return 0;
}

