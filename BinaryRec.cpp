#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        }
        // If target is smaller, ignore the right half
        else {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
    }

    // If we reach here, the element was not found
    return -1;
}

int main() {
    int n, target;

    // Custom input
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
