#include <iostream>

// Function to calculate the sum of elements in an array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in an array
int maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    // Get the size of the array from the user
    std::cout << "Enter the number of elements (n): ";
    std::cin >> n;

    // Declare an array of length n
    int arr[n];

    // Get array elements from the user
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Call summation function and display the result
    int sum = summation(arr, n);
    std::cout << "Sum of the integers: " << sum << std::endl;

    // Call maximum function and display the result
    int max = maximum(arr, n);
    std::cout << "Maximum integer: " << max << std::endl;

    return 0;
}
