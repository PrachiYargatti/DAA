#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[1] - intervalB[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int nonOverlappingCount = 1; 
    int lastEnd = intervals[0][1]; 

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= lastEnd) { 
            nonOverlappingCount++;
            lastEnd = intervals[i][1]; 
        }
    }

    return intervalsSize - nonOverlappingCount;
}

int main() {
    int intervalsSize = 4;
    int intervalsColSize[] = {2, 2, 2, 2};
    
    int intervalsArray[4][2] = {{1, 3}, {2, 4}, {3, 5}, {1, 2}};
    int* intervals[4];
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = intervalsArray[i];
    }

    int result = eraseOverlapIntervals(intervals, intervalsSize, intervalsColSize);
    printf("Minimum number of intervals to remove: %d\n", result);
    
    return 0;
}

