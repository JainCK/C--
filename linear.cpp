#include <iostream>
using namespace std;

void sequentialSearch(int arr[], int size, int key) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout <<  i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element " << key << " not found in the array (Sequential Search)\n";
    }
}

int main() {
    int n = 5;
    int key = 7;
    int arr[] = {2, 6, 5, 7, 9};

    // cout << "Enter the number of elements: ";
    // cin >> n;

    // int arr[n];
    // cout << "Enter " << n << " elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // cout << "Enter the element to search: ";
    // cin >> key;

    sequentialSearch(arr, n, key);

    return 0;
}
