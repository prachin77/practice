// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// hello guys


#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
};


void leafnode(node* root, list<node*>& l, int& ans){
    if (!root) {
        return;
    }

    // list<node*> l;
    list<node*> :: iterator it;
    l.push_back(root);
    string s="";

    if(!root->left && !root->right){
        for(it=l.begin();it!=l.end();it++){
            s += to_string((*it)->data);
        }
        ans=ans+stoi(s);
        l.pop_back();
        return ;
    }

    if(root->left){
        leafnode(root->left,l,ans);
    }

    if(root->right){
        leafnode(root->right,l,ans);
    }

    l.pop_back();
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
    
    return nn;
}

int main(){
    node* root = tree();
    list<node*> l;
    int ans = 0;
    leafnode(root, l, ans);
    cout << ans << endl;

    return 0;
}