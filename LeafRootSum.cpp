// https://leetcode.com/problems/sum-root-to-leaf-numbers/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
};

void tra(){
    queue<node*> q;
    
}

void leafnode(node* root){
	// cout<<"\n\nleaf node search\n";
	queue<node*> q;
	q.push(root);

    queue<int> q1;
	while(!q.empty()){
		node* tmp=q.front();
		q.pop();	
//		cout<<tmp->a<<endl;
		if(tmp->left==NULL && tmp->right==NULL){
			cout<<tmp->data<<" is leaf node\n";
		}
		else{
			if(tmp->left){
			q.push(tmp->left);
			}
			if(tmp->right){
				q.push(tmp->right);
			}	
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
    leafnode(root);
}