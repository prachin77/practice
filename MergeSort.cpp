#include<iostream>
#include<list>
using namespace std;

void merge(int arr[],int start,int end){
    int arr[n];
    list<int> l;
    l.insert(arr[start]);
    l.sort();
    return l;
}

int mergesort(int arr[],int start,int end,int n){
    int mid;
    if(start==end){
        merge(arr,start,end,n);
        return;
    }
    mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    
}

int main(){
    int n=5;
    int arr[]={5,4,3,2,1};
    int start=0;
    int end=n-1;
    mergesort(arr,start,end,n);
}