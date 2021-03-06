#pragma once
#include<iostream>
#include <stdio.h>
using namespace std;

template<class T>
class DinamicArray {
    int len, maxLen;
    T* array;
public:
    DinamicArray(int maxLen) {
        this->maxLen = maxLen;
        len = 0;
        array = new T[maxLen];
    };


    void print(bool crescent = 1) {
        cout << "Dinamic array with max size: " << maxLen << endl;
        if (!crescent) {
            for (int i = len-1; i >= 0; i--) {
                cout <<'\t'<< len-1-i << ": " << array[i] << endl;
            }
            return;
        }
        for (int i = 0; i < len; i++) {
            cout <<'\t'<< i << ": " << array[i] << endl;
        }
    }


    void insert(T n) {
        if (len >= maxLen) {
            maxLen *= 2;
            T* tmp = new T[maxLen];
            for (int i = 0; i < len; i++) {
                tmp[i] = array[i];
            }
            T* toDel = array;
            array = tmp;
            delete[] toDel;
        }
        array[len++] = n;
    }


    int pop_out() {
        return pop(len - 1);
    }
 

    void sort() {
        for(int j = 0; j<len-1; j++){
            bool sorted = 1;
            for (int i = 0; i < len-j-1; i++) {
                if (array[i] > array[i + 1]) {
                    sorted = 0;
                    swap(array[i], array[i+1]);
                }
            }
            if (sorted)break;
        }
    }


    T* pop(int i) {
        if (i >= maxLen) return nullptr;
        T *toRet = &array[i];
        for (int j = i; j < len-1; j++) {
            array[j] = array[j + 1];
        }
        len--;

        if (len <= maxLen / 2) {
            T* tmp = new T[maxLen / 2];
            for (int j = 0; j < len; j++) {
                tmp[j] = array[j];
            }
            T* toDel = array;
            array = tmp;
            delete[] toDel;
            maxLen /= 2;
        }
        return toRet;


    }


    T& operator[](int i)const {
        if (i >= 0 && i < len) {
            return array[i];
        }
        cout << "List index out of range" << endl;
        exit(0);

    }


    void setMaxLen(int _maxLen) {
        maxLen = _maxLen;
    }


    const int getMaxLen() {
        return maxLen;
    }


    int size() {
        return len;
    }

};
