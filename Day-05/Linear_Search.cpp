#include<iostream>
using namespace std;
    
int linearSearch(int arr[],int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,25,30,45,60};
    int n=5;
    int key=45;

    int result = linearSearch(arr,n,key);

    if(result != -1)
       cout << "Found at index " << result;
    else
       cout << "Not found";

    return 0;   
 
}