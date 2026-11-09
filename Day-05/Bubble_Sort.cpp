#include<iostream>
using namespace std;

int main(){
    int arr[] = {4,2,7,1};
    int n=4;

    for(int pass=0; pass<n-1; pass++){
        for(int i=0; i<n-1-pass; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}