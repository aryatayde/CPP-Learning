
#include<iostream>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {

    int temp[1000];
    int i = si;
    int j = mid + 1;
    int k = 0;

    // Merge two sorted halves
    while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half
    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while(j <= ei) {
        temp[k++] = arr[j++];
    }

    // Copy temporary array back to original array
    for(int x = 0; x < k; x++) {
        arr[si + x] = temp[x];
    }
}

void mergeSort(int arr[], int si, int ei) {

    if(si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

int main() {

    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
