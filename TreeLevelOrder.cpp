#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
};

void levelorder(node* root,int c){
    if(root==NULL){
        return;
    }
    cout<<"level "<<c<<" -> ";
    cout<<root->data<<" ";
    // map<int,list<int> > m;
    // if(root->left){
    //     c++;
    //     levelorder(root->left,c);
    // }
    // if(root->right){
    //     c++;
    //     levelorder(root->right,c);
    // } 
    if(root->left){
        c++;
        levelorder(root->left,c);
    }
    else if(!root->left){
        if(root->right){
            c++;
            levelorder(root->right,c);
        }
        else {
            return;
        }
    }
    
}

node* tree(){
    int rootele;
    cout<<"enter root element(-1 to exit) = ";
    cin>>rootele; 
    if(rootele==-1){
        return NULL;
    }

    node* nn = new node;
    nn->data = rootele;
    cout<<"element at left of root data "<<nn->data<<endl;
    nn->left=tree();
    cout<<"element at right of root data "<<nn->data<<endl;
    nn->right=tree();
 
}

int main(){
    node* root = tree();
    int c=1;
    levelorder(root,c);

}
