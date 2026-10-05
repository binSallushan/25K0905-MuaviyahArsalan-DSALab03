#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertionArmSorter(int arr[], int size) {
    long long totalShift = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        int shifts = 0;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
        totalShift += shifts;

        cout << "Key " << key << " placed: ";
        printArray(arr, size);
        if (shifts == 0) cout << "  No shift required" << endl;
        cout << "  Positions shifted: " << shifts << endl;
    }
    cout << "Total shift distance: " << totalShift << endl;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Task 2:" << endl;
    insertionArmSorter(v.data(), n);
    cout << "Sorted array: ";
    printArray(v.data(), n);
    return 0;
}
