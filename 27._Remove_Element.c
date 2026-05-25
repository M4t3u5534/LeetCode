int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize - k; i++) {
        if (nums[i] == val) {
            k++;
            for (int j = i; j < numsSize - k; j++) {
                nums[j] = nums[j+1];
            }
            i--;
        }
    }
    return numsSize - k;
}