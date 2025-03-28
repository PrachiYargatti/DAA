// interval sceduling problems using greedy approach

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start; 
    int finish; 
} Interval;

int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return (i1->finish - i2->finish);
}

void intervalScheduling(Interval intervals[], int n) {
    qsort(intervals, n, sizeof(Interval), compare);

    printf("Selected intervals:\n");

    int lastSelectedIndex = 0;
    printf("[%d, %d]\n", intervals[lastSelectedIndex].start, intervals[lastSelectedIndex].finish);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= intervals[lastSelectedIndex].finish) {
            printf("[%d, %d]\n", intervals[i].start, intervals[i].finish);
            lastSelectedIndex = i;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n]; 

    printf("Enter the start and finish times of the intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d:\n", i + 1);
        printf("Start: ");
        scanf("%d", &intervals[i].start);
        printf("Finish: ");
        scanf("%d", &intervals[i].finish);
    }

    intervalScheduling(intervals, n);

    return 0;
}

