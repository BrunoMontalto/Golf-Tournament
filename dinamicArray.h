#pragma once
#include<iostream>
#include <stdio.h>
#define INT_MAX 2147483647
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

    void print() {
        cout << "Array Dinamico di dimensione massima " << maxLen << endl;
        for (int i = 0; i < len; i++) {
            cout << i << ": " << array[i] << endl;
        }
    }

    void insert(T n) {//inserisci alla prima posizione libera
        if (len >= maxLen) {
            maxLen *= 2;
            T* tmp = new int[maxLen];
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


    T pop(int i) {
        if (i >= maxLen) return -INT_MAX;
        T toRet = array[i];
        for (int j = i; j < len; j++) {
            array[j] = array[j + 1];
        }
        len--;

        if (len <= maxLen / 2) {
            T* tmp = new int[maxLen / 2];
            for (int j = 0; j < len; j++) {
                tmp[j] = array[j];
            }
            T* toDel = array;//mamama si
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


    const int* getMaxLen() {
        return &maxLen;
    }








};