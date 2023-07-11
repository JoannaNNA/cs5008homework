
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Function to convert decimal to binary
int decimalToBinary(int n) {
    int binary = 0, remainder, i = 1;

    while(n != 0) {
        remainder = n % 2;
        n /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(int n) {
    int decimal = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimal += remainder << i;
        ++i;
    }

    return decimal;
}


// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int size, target, *arr, *bin_arr;

    printf("Input array size: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));
    bin_arr = malloc(size * sizeof(int));

    printf("Input elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        bin_arr[i] = decimalToBinary(arr[i]);
    }

    printf("Input target: ");
    scanf("%d", &target);

    printf("The array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("The target: %d\n", target);

    int bin_target = decimalToBinary(target);
    printf("Converted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", bin_arr[i]);
    }

    printf("\n");
    printf("Converted target: %d\n", bin_target);

    int result = linearSearch(bin_arr, size, bin_target);
    printf("Search result: %d\n", result);

    printf("Original array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", binaryToDecimal(bin_arr[i]));
    }

    printf("\n");
    printf("Original target: %d\n", binaryToDecimal(bin_target));

    free(arr);
    free(bin_arr);

    return 0;
}
