#include <iostream>
using namespace std;

int bubbleSortIterations(int arr[], int n) {
    int iterations = 0;
    // bool swapped;

    for (int i = 0; i < n - 1; i++) {
        iterations++;  // Increment iteration count
        // swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                // swapped = true;
            }
        }


        // If no elements were swapped in the inner loop, then the array is sorted
        // if (!swapped) {
        //     break;
        // }
    }

    return iterations;
}

int main() {
    int arr[] = {1, 3, 0, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int arr[];
    // int n = 6;

    // for (int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }

    int iterations = bubbleSortIterations(arr, n);

    cout << iterations << endl;

    return 0;
}
