#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} NumIndex;

void merge(NumIndex* arr, int* counts, int left, int mid, int right) {
    int size = right - left + 1;
    NumIndex* temp = (NumIndex*)malloc(size * sizeof(NumIndex));
    int i = left, j = mid + 1, k = 0, rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < size; x++) {
        arr[left + x] = temp[x];
    }

    free(temp);
}

void mergeSort(NumIndex* arr, int* counts, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, counts, left, mid);
    mergeSort(arr, counts, mid + 1, right);
    merge(arr, counts, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    NumIndex* numIndexArr = (NumIndex*)malloc(numsSize * sizeof(NumIndex));

    for (int i = 0; i < numsSize; i++) {
        numIndexArr[i].value = nums[i];
        numIndexArr[i].index = i;
    }

    mergeSort(numIndexArr, counts, 0, numsSize - 1);
    free(numIndexArr);
    return counts;
}
