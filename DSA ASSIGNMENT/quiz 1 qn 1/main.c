#include <stdio.h>

int removeDuplicates(int nums[], int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int newLength = 1;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[newLength] = nums[i];
            ++newLength;
        }
    }

    return newLength;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    printf("New Length: %d\n", newLength);
    printf("Updated Array: ");
    for (int i = 0; i < newLength; ++i) {
        printf("%d ", nums[i]);
    }

    return 0;
}
