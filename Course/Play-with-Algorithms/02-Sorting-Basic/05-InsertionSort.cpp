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

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
//方法一
//        for(int j=i;j>0;j--){
//            if(arr[j]<arr[j-1])
//                swap(arr[j],arr[j-1]);
//            else
//                break;
//        }
//方法二
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            swap(arr[j], arr[j - 1]);
    }
}

template<typename T>
void insertionSort2(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int N = 20000;
    int *arr = sortTestHelper::generateRandomArray(N, 0, N);
    int *arr2 = sortTestHelper::copyIntArray(arr, N);
    int *arr3 = sortTestHelper::copyIntArray(arr, N);
    sortTestHelper::testSort("Selection Sort", selectionSort, arr, N);
    sortTestHelper::testSort("Insertion Sort", insertionSort, arr2, N);
    sortTestHelper::testSort("Insertion Sort2", insertionSort2, arr3, N);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}

