#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int searchInsert(vector<int>& nums, int target) {
            int size=nums.size();
            int ans = 0,c=0;
            vector<int> :: iterator it;
            for(it=nums.begin();it!=nums.end();it++){
                if(target == *it){
                    ans = c;
                    break;
                }
                if(target > *it){
                    ans=c+1;
                }
                c++;
            }
            return ans;
        }        
};
int main(){
    int size;
    cout<<"enter size = ";
    cin>>size;
    int i,j;
    vector<int> nums;
    vector<int> :: iterator it;
    vector<int> :: iterator it1;
    for(i=0;i<size;i++){
        int ele;
        cout<<"enter data : ";
        cin>>ele;
        nums.push_back(ele);
        nums.
    }
    int tmp=0;
    for(it=nums.begin();it!=nums.end();it++){
        for(it1=nums.begin();it1!=nums.end();it1++){
            if( *it1 > *it ){
                tmp = *it1;
                *it1 = *it;
                *it = tmp;
            }
        }
    }
    for(it=nums.begin();it!=nums.end();it++){
        cout<<*it<<" ";
    }
    int target;
    cout<<"\nenter target = ";
    cin>>target;
    Solution ob ;
    cout<<"result | position : "<<ob.searchInsert(nums,target);
}

