#include <iostream>
#include <vector>

using std::cout, std::vector;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

void print(const vector<int> &arr) {
    for (int i: arr)
        cout << i << " ";
}

int main() {
    vector<int> arr = {4, 2, 8, 6, 0, 5, 1, 7, 3, 9};
    cout << "Base arr: ";
    print(arr);
    mergeSort(arr);

    cout << "\nArr after mergeSort: ";
    print(arr);

    return 0;
}
