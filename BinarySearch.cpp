#include<iostream>
using namespace std;

void bsright(int search, int arr[],int left,int right);
void bsleft(int search, int arr[],int left,int right);

// 1 2 3 4 (5) 6 [7] 8 9 10 11 12 13

void bsleft(int search,int arr[],int left,int right){
    int mid=(left+right)/2;
    if(search==arr[mid]){
        cout<<"element found "<<search;
    }
    if(search>arr[mid]){
        left=mid+1;
        // mid=(left+right)/2;
        bsright(search,arr,left,right);
    }
    if(search<arr[mid]){
        right=mid-1;
        bsleft(search,arr, left, right);
    }
}

void bsright(int search,int arr[],int left,int right){
    int mid=(left+right)/2;
    if(search==arr[mid]){
        cout<<"element found "<<search;
    }
    if(search>arr[mid]){
        left=mid+1;
        bsright(search,arr,left,right);
    }
    if(search<arr[mid]){
        right=mid-1;
        bsleft(search,arr,left,right);
    }
}

int main(){
    int n=10;
    // cout<<"array size = ";
    // cin>>n;
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    // int i,j;
    // for(i=0;i<n;i++){
    //     int ele;
    //     cout<<"array element : ";
    //     cin>>ele;
    //     arr[i]=ele;
    // } 
    // int mid=(0+(n-1))/2;
    int search;
    cout<<"search element in array = ";
    cin>>search;
    int left=0,right=n-1;

    bsright(search,arr,left,right);
}