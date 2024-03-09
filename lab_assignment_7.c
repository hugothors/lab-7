#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int size) {
    int i, j, temp, swaps = 0;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int selectionSort(int arr[], int size) {
    int i, j, min_idx, temp, swaps = 0;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps++;
    }
    return swaps;
}

int countTotalSwaps(int arr[], int size, int (*sortingFunc)(int[], int)) {
    return sortingFunc(arr, size);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printf("array1:\n");
    int total_swaps_bubble1 = countTotalSwaps(array1, size1, bubbleSort);
    for (int i = 0; i < size1; i++) {
        printf("%d: %d swaps\n", array1[i], total_swaps_bubble1);
    }
    printf("Total number of Bubble Sort Swaps: %d\n\n", total_swaps_bubble1);

    int total_swaps_selection1 = countTotalSwaps(array1, size1, selectionSort);
    for (int i = 0; i < size1; i++) {
        printf("%d: %d swaps\n", array1[i], total_swaps_selection1);
    }
    printf("Total number of Selection Sort Swaps: %d\n\n", total_swaps_selection1);

    printf("array2:\n");
    int total_swaps_bubble2 = countTotalSwaps(array2, size2, bubbleSort);
    for (int i = 0; i < size2; i++) {
        printf("%d: %d swaps\n", array2[i], total_swaps_bubble2);
    }
    printf("Total number of Bubble Sort Swaps: %d\n\n", total_swaps_bubble2);

    int total_swaps_selection2 = countTotalSwaps(array2, size2, selectionSort);
    for (int i = 0; i < size2; i++) {
        printf("%d: %d swaps\n", array2[i], total_swaps_selection2);
    }
    printf("Total number of Selection Sort Swaps: %d\n", total_swaps_selection2);

    return 0;
}
