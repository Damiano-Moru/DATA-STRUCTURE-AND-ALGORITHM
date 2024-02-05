#include <stdio.h>

int containsDuplicate(int nums[], int numsSize) {
    // Check for empty or single-element array
    if (numsSize <= 1) {
        return 0;
    }

    // Sort the array (you can use any sorting algorithm)
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] > nums[j]) {
                // Swap elements if they are in the wrong order
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    // Check for duplicates
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            return 1; // Duplicates found
        }
    }

    return 0; // No duplicates
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 3, 4, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

    printf("Array 1: %s\n", containsDuplicate(nums1, numsSize1) ? "Contains duplicates" : "No duplicates");
    printf("Array 2: %s\n", containsDuplicate(nums2, numsSize2) ? "Contains duplicates" : "No duplicates");

    return 0;
}
