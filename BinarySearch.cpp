#include<iostream>
using namespace std;

int mergesort(int n){
    int arr[n];
    int i,j;
    for(i=0;i<n;i++){
        int ele;
        cout<<"array element : ";
        cin>>ele;
        arr[i]=ele;
    }
    int mid=(0+(n-1))/2;
}

int main(){
    int n;
    cout<<"array size = ";
    cin>>n;
    mergesort(n);    
}