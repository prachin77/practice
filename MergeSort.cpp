#include<iostream>
using namespace std;

void merge(int arr[],int start,int end){
    int mid=(start+end)/2;

    int leftlen = mid-start+1;
    int rightlen = end-mid;

    int *leftarr = new int[leftlen];
    int *rightarr = new int[rightlen];
}

void mergesort(int arr[],int start,int end){
    if(start>end){
        return;
    }
    mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end);
    
}

int main(){
    int n=5;
    int arr[]={5,4,3,2,1};
    int start=0;
    int end=n-1;
    mergesort(arr,start,end);
}