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


void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
            res.push_back(lft[i]);
            i+=1;
        } else {
            res.push_back(rgt[j]);
            j+=1;
        }
    }
    while (i < lft.size()) {
        res.push_back(lft[i]);
        i+=1;
    }
    while (j < rgt.size()) {
        res.push_back(rgt[j]);
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
    int i = l, j = r+1;
    int pivot = inputArray[l];
    while (true) {
       do {
           i++;
       } while (i <= r && inputArray[i] < pivot);
       do {
           j--;
       } while (inputArray[j] > pivot && j > l);
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

    std::vector<int> data(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::generate(data.begin(), data.end(), g);
    std::cout << "Unsorted data rn: ";
    for(auto& num : data)
    {
       num = std::abs(num) % 7;
    }
    for (const auto& num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //quickSort(data, 0, data.size() - 1);
    selectionSort(data);
    if (is_sorted(data.begin(), data.end())) {
        std::cout << "Data is sorted using selection sort." << std::endl;
    } else {
        std::cout << "Data is not sorted using selection sort." << std::endl;
    }
    // heapify(data);
    // heapsort(data);
    // data = mergesort(data);
    //quickSort(data, 0, data.size() - 1);

    return 0;
}