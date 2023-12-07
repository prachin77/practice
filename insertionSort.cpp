#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int i,j;
    int tmp;
    int c=0;
    
    for(i=0;i<10-1;i++){
        j=i+1;
        while (j>0){
            if(arr[j]<arr[j-1]){
                tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
            }
            j--;
        }
        
    }

    for(i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}