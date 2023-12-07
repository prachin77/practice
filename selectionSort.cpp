#include<iostream>
using namespace std;
int main(){
    int arr[5]={5,4,3,2,1};
    int i,j;
    int tmp=0,tmp1=0;
    for(i=0;i<5;i++){
        tmp=i;
        for(j=i+1;j<5;j++){
            if(arr[j]<arr[tmp]){
                tmp=j;
            }
        }
        tmp1=arr[i];
        arr[i]=arr[tmp];
        arr[tmp]=tmp1;
    }
    for(i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}