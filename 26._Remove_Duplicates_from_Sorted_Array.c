int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    for (int i = 1; i < numsSize - k; i++) {
        if (nums[i] == nums[i-1]) {
            k++;
            for (int j = i; j < numsSize - k; j++) {
                nums[j] = nums[j+1];
            }
            i--;
        }
    }
    return numsSize - k;
}