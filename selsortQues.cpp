#include <iostream>
using namespace std;

//NOTE: UNCOMMENT THE BELOW LINE TO ENABLE WHITEBOX TEST CASE
//#ifndef __CXX_TEST_MAIN__
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Assume the current index is the minimum
        int minIndex = i;
        
        // Find the minimum element in the unsorted array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    int arr[] = {45, 13, 112, 150, 116};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform selection sort
    selectionSort(arr, n);


    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
