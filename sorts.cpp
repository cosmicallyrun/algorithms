#include <cstddef> 
#include <iterator>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <random>

void selectionSort(std::vector<int>& inputArray) {
    for (size_t i = 0; i < inputArray.size(); ++i) {
        size_t smallestIndex = i;
        for (size_t j=i+1; j < inputArray.size(); ++j) {
            if (inputArray[j]<inputArray[smallestIndex]){
                smallestIndex = j;
            }
        };
    std::swap(inputArray[i],inputArray[smallestIndex]);
    };
}

std::vector<int> mergesort(std::vector<int>& inputArray) {
    if (inputArray.size() <= 1) {
        return inputArray;
    }
    int mid = inputArray.size() / 2;
    std::vector<int> lft(inputArray.begin(), inputArray.begin() + mid);
    std::vector<int> rgt(inputArray.begin() + mid, inputArray.end());
    lft = mergesort(lft);
    rgt = mergesort(rgt);
    std::vector<int> res;
    int i = 0, j = 0;
    while (i < lft.size() && j < rgt.size()) {
        if (lft[i] < rgt[j]) {
            res.push_back(lft[i+1]);
            i+=1;
        } else {
            res.push_back(rgt[j+1]);
            j+=1;
        }
    }
    while (i < lft.size()) {
        res.push_back(lft[i+1]);
        i+=1;
    }
    while (j < rgt.size()) {
        res.push_back(rgt[j+1]);
        j+=1;
    }
    return res;
}

void quickSort(std::vector<int>& inputArray, int l, int r) {
    std::random_device rd;
    std::mt19937 g(rd());
    //only shuffle the entire array once
    if (l == 0 && r == inputArray.size() - 1) {
        std::shuffle(inputArray.begin(), inputArray.end(), g);
    }
    if (r<=l) {
        return; 
    }
    //now partition the array
    int i = l, j = r + 1;
    int pivot = inputArray[l];
    while (true) {
        while (inputArray[i] < pivot) {
            if (i == r) {break;}
            i++;
        }
        while (inputArray[j] > pivot) {
            if (j == l) {break;}
            j--;
        }
        if (i >= j) break;
        std::swap(inputArray[i], inputArray[j]);
    }
    //put the pivot in the right place
    std::swap(inputArray[l], inputArray[j]);
    //now sort the two sub arrays
    quickSort(inputArray, l, j - 1);
    quickSort(inputArray, j + 1, r);
}
int main() {
    return 0;
}