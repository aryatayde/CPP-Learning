#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid = (left + right)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90};
    int n = 9;
    int key = 70;

    int result = binarySearch(arr, n, key);

    if(result != -1)
       cout << "Found at index " << result;
    else
       cout << "Not found";

    return 0;
}
