//
// Created by Hz Yang on 2018/2/8.
//

#ifndef PRACTICE_SORTTESTHELPER_H
#define PRACTICE_SORTTESTHELPER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
namespace sortTestHelper {
    //生成有n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    //打印arr数组的所有内容
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
}
#endif //PRACTICE_SORTTESTHELPER_H
