#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
};

bool symmetry(node* root1,node* root2){
    bool flag = true;
    queue<node*> q1;
    q1.push(root1);
    queue<node*> q2;
    q2.push(root2);

    while(!q1.empty() && !q2.empty() && flag!=false){
        node* tmp1 = q1.front();
        node* tmp2 = q2.front();
        q1.pop();
        q2.pop();
        if(tmp1->left && tmp2->left){
            if(tmp1->left == tmp2->left){
                q1.push(tmp1->left);
                q2.push(tmp2->left);
            }
        }
        else if(tmp1->left && !tmp2->left){
            flag=false;
        }
        if(tmp1->right && tmp2->right){
            if(tmp1->right == tmp2->right){
                q1.push(tmp1->right);
                q2.push(tmp2->right);
            }
        }
        else if(tmp1->right && !tmp2->right){
            flag=false;
        }
    }
    return flag;
}

void tra1(node* root1){
    queue<node*> q1;
    q1.push(root1);
    while(!q1.empty()){
        node* tmp = q1.front();
        cout<<tmp->data<<" ";
        q1.pop();
        if(tmp->left){
            q1.push(tmp->left);
        }
        if(tmp->right){
            q1.push(tmp->right);
        }
    }
}
node* tree1(){
    
    int rootele;
    cout<<"enter data (-1 to exit) = ";
    cin>>rootele;
    if(rootele==-1){
        return NULL;
    }
    node* nn = new node;
    nn->data=rootele;
    cout<<"enter data at left "<<rootele<<endl;
    nn->left=tree1();
    cout<<"enter data at right of "<<rootele<<endl;
    nn->right=tree1();
}


void tra2(node* root2){
    queue<node*> q2;
    q2.push(root2);
    while(!q2.empty()){
        node* tmp = q2.front();
        cout<<tmp->data<<" ";
        q2.pop();
        if(tmp->left){
            q2.push(tmp->left);
        }
        if(tmp->right){
            q2.push(tmp->right);
        }
    }
}
node* tree2(){
    
    int rootele;
    cout<<"enter data (-1 to exit) = ";
    cin>>rootele;
    if(rootele==-1){
        return NULL;
    }
    node* nn = new node;
    nn->data=rootele;
    cout<<"enter data at left "<<rootele<<endl;
    nn->left=tree2();
    cout<<"enter data at right of "<<rootele<<endl;
    nn->right=tree2();
}


int main(){
    cout<<"TREE 1\n";
    node* root1 = tree1();
    tra1(root1);
    cout<<endl;

    cout<<"TREE 2\n";
    node* root2 = tree1();
    tra2(root2);
    cout<<endl;
    cout<<"flag = "<<symmetry(root1,root2);
}