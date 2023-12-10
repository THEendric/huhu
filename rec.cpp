#include <iostream>
#include <vector>

// Sorting Algorithms

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Searching Algorithms

int linearSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Recursive Programs

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + multiply(a, b - 1);
}

int main() {
    // Sorting
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    insertionSort(arr);
    std::cout << "After Insertion Sort: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    bubbleSort(arr);
    std::cout << "After Bubble Sort: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    selectionSort(arr);
    std::cout << "After Selection Sort: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Searching
    int target = 5;
    int linearResult = linearSearch(arr, target);
    std::cout << "Linear Search Result for " << target << ": " << linearResult << "\n";

    int binaryResult = binarySearch(arr, target);
    std::cout << "Binary Search Result for " << target << ": " << binaryResult << "\n";

    // Recursive Programs
    int n = 5;
    std::cout << "Factorial of " << n << ": " << factorial(n) << "\n";

    int fibN = 6;
    std::cout << "Fibonacci at position " << fibN << ": " << fibonacci(fibN) << "\n";

    int num1 = 4, num2 = 3;
    std::cout << "Multiplication of " << num1 << " and " << num2 << ": " << multiply(num1, num2) << "\n";

    return 0;
}
