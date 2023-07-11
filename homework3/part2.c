#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int size, target, *arr;

    printf("Input array size: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));

    printf("Input elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Input target: ");
    scanf("%d", &target);

    printf("The array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("The target: %d\n", target);

    bubbleSort(arr, size);

    int result = binarySearch(arr, 0, size - 1, target);
    printf("Search result: %d\n", result);

    free(arr);

    return 0;
}
