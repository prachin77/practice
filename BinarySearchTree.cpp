#include<iostream>
#include<queue>
using namespace std;

// almost done 

class node{
    public:
        node* left;
        node* right;
        int data;
};

// 5,4,6,null,null,3,7

bool isValidBST(node* root) {
    bool flag = false;
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        flag=true;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(tmp->left && tmp->left->data >= tmp->data){
            cout<<"false\n";
            return flag;
            break;
        }
        if(tmp->right && tmp->right->data <= tmp->data){
            cout<<"false\n";
            return flag;
            break;
        }
        // else{
            if(tmp->left){
                flag = true;
                q.push(tmp->left);
            }
            if(tmp->right){
                flag = true;
                q.push(tmp->right);
            }
        // }
    }
    if(flag!=false){
        cout<<"flag is true ";
        return  flag;
    }
    else{
        cout<<"flag is false ";
        return flag ;
    }
    // return flag;
}


// 2 1 3

// void tra(node* root){
//     queue<node*> q;
//     q.push(root);
//     while(!q.empty()){
//         node* tmp = q.front();
//         q.pop();
//         cout<<tmp->data<<" ";
//         if(tmp->left){
//             q.push(tmp->left);
//         }
//         if(tmp->right){
//             q.push(tmp->right);
//         }
//     }
// }

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
    // tra(root);
    isValidBST(root);
}