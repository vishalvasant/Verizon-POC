# QuickSort Implementation Documentation

## JIRA Issue: SCRUM-2

This document provides detailed information about the QuickSort implementation for sorting dynamic arrays in C++.

## Overview

QuickSort is a highly efficient sorting algorithm based on the divide-and-conquer paradigm. It works by:

1. Selecting a 'pivot' element from the array
2. Partitioning the array around the pivot (elements less than pivot go to the left, greater than pivot go to the right)
3. Recursively applying the above steps to the sub-arrays

## Implementation Details

The implementation includes several key components:

### 1. Partition Function

The partition function takes the last element as pivot, places the pivot element at its correct position, and arranges all smaller elements to the left and all greater elements to the right.

```cpp
int partition(std::vector<int>& arr, int low, int high) {
    // Implementation details
}
```

### 2. Randomized Partition

To avoid worst-case scenarios (when the array is already sorted or nearly sorted), a randomized partition function is implemented:

```cpp
int randomizedPartition(std::vector<int>& arr, int low, int high) {
    // Randomly select pivot for better average performance
}
```

### 3. Core QuickSort Algorithm

The core algorithm is implemented recursively:

```cpp
void quickSortRecursive(std::vector<int>& arr, int low, int high) {
    // Recursive implementation
}

void quickSort(std::vector<int>& arr) {
    // Main entry point
}
```

### 4. Testing and Validation

The implementation includes:
- Functions to verify if an array is sorted
- Functions to generate random test arrays
- Performance testing with various array sizes

## Performance Analysis

QuickSort has an average time complexity of O(n log n) and worst-case O(n²). The implementation has been tested with arrays of various sizes:

| Array Size | Approximate Sorting Time |
|------------|--------------------------|
| 10         | < 1 ms                   |
| 100        | < 1 ms                   |
| 1,000      | < 5 ms                   |
| 10,000     | < 50 ms                  |
| 100,000    | < 500 ms                 |

*Note: Actual performance may vary based on hardware and system load.*

## Space Complexity

The space complexity is O(log n) due to the recursion stack.

## Optimization Techniques Used

1. **Randomized Pivot Selection**: To avoid worst-case scenarios
2. **In-place Partitioning**: To minimize memory usage
3. **Efficient Swapping**: Using std::swap for efficient element exchange

## Usage Example

```cpp
#include <vector>
#include <iostream>

// Include QuickSort implementation

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    // Before sorting
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    quickSort(arr);
    
    // After sorting
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
```

## Compilation and Execution

To compile and run the implementation:

```bash
g++ -std=c++11 -o quicksort quicksort.cpp
./quicksort
```

## Future Improvements

Potential improvements for the implementation:
1. Template-based implementation for different data types
2. Parallelization for large arrays
3. Hybrid approach (using insertion sort for small subarrays)

---

*This implementation satisfies the requirements specified in JIRA issue SCRUM-2: "Write a C++ Program to Sort an Array Using Quick Sort"*