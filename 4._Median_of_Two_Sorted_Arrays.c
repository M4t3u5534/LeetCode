double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int tam = nums1Size + nums2Size;
    int aux[tam];
    int cont = 0;

    int i = 0;
    int j = 0;
    while (i < nums1Size && j < nums2Size) {
        if(nums1[i] < nums2[j]) aux[cont++] = nums1[i++];
        else aux[cont++] = nums2[j++];
    }

    if (i >= nums1Size) {
        for(j; j < nums2Size; j++) aux[cont++] = nums2[j];
    }
    else {
        for(i; i < nums1Size; i++) aux[cont++] = nums1[i];
    }

    double median;
    if (tam % 2 != 0) {
        int ax = tam / 2;
        median = (double)aux[ax];
    }
    else {
        int ax = tam / 2;
        median = (aux[ax - 1] + aux[ax]) / 2.0;
    }

    return median;
}