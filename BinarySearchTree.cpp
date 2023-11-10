#include<iostream>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
}

node* tree(){
    int rootele;
    cout<<"enter root element(-1 to exit) = ";
    cin>>rootele; 
    if(rootele==-1){
        return NULL;
    }

    node* nn = new node;
    nn->

}

int main(){
    node* root = tree();
}