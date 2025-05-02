/**
 * @file quicksort.cpp
 * @brief Implementation of QuickSort algorithm for dynamic arrays
 * 
 * This file contains the implementation of the QuickSort algorithm
 * for sorting dynamic arrays (using std::vector) in C++.
 * 
 * JIRA Issue: SCRUM-2
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>

/**
 * @brief Partition function for QuickSort
 * 
 * This function takes the last element as pivot, places the pivot element at its
 * correct position in sorted array, and places all smaller elements to left of
 * pivot and all greater elements to right of pivot.
 * 
 * @param arr Array to be partitioned
 * @param low Starting index
 * @param high Ending index
 * @return int Index of the pivot element
 */
int partition(std::vector<int>& arr, int low, int high) {
    // Select the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of smaller element
    int i = (low - 1);
    
    // Traverse through all elements
    // compare each element with pivot
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot to its final position
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Randomized partition for better performance
 * 
 * This function selects a random pivot to avoid worst-case scenarios
 * in particular input sequences.
 * 
 * @param arr Array to be partitioned
 * @param low Starting index
 * @param high Ending index
 * @return int Index of the pivot element
 */
int randomizedPartition(std::vector<int>& arr, int low, int high) {
    // Generate a random number between low and high
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    int random = dis(gen);
    
    // Swap the randomly selected element with the last element
    std::swap(arr[random], arr[high]);
    
    // Call the standard partition function
    return partition(arr, low, high);
}

/**
 * @brief Recursive QuickSort function
 * 
 * This function implements the recursive part of QuickSort algorithm.
 * 
 * @param arr Array to be sorted
 * @param low Starting index
 * @param high Ending index
 */
void quickSortRecursive(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // element smaller than pivot are on the left
        // element greater than pivot are on the right
        int pi = randomizedPartition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

/**
 * @brief Main QuickSort function
 * 
 * This is the main function that sorts an array using QuickSort.
 * 
 * @param arr Array to be sorted
 */
void quickSort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return; // Already sorted
    }
    
    // Call the recursive implementation
    quickSortRecursive(arr, 0, arr.size() - 1);
}

/**
 * @brief Function to verify if an array is sorted
 * 
 * @param arr Array to be checked
 * @return true If the array is sorted
 * @return false If the array is not sorted
 */
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Create a random array of given size
 * 
 * @param size Size of the array
 * @return std::vector<int> Random array
 */
std::vector<int> createRandomArray(int size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

/**
 * @brief Test QuickSort with different array sizes and measure performance
 */
void testQuickSort() {
    // Test with various array sizes
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000};
    
    std::cout << "QuickSort Performance Test\n";
    std::cout << "==========================\n";
    
    for (int size : sizes) {
        // Create a random array
        std::vector<int> arr = createRandomArray(size);
        
        // Measure sorting time
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        
        // Calculate duration in milliseconds
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        // Verify if sorted
        bool sorted = isSorted(arr);
        
        std::cout << "Array size: " << size << "\n";
        std::cout << "Sorting time: " << duration << " ms\n";
        std::cout << "Correctly sorted: " << (sorted ? "Yes" : "No") << "\n";
        std::cout << "--------------------------\n";
    }
}

/**
 * @brief Main function for demonstration
 * 
 * @return int Exit code
 */
int main() {
    // Test small array for demonstration
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    quickSort(arr);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
    
    // Run performance tests
    testQuickSort();
    
    return 0;
}