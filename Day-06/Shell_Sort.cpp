#include<iostream>
using namespace std;

int main() {
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = 8;

    for(int gap = n/2; gap > 0; gap /= 2) {

        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while(j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}