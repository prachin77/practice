#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;
};


// void levelorder(node* root, int c,map<int, list<node*>>& m) {
//     bool flag = true ;
    
    // if (root == NULL) {
    //     c--;
    //     return;
    // }

    // m[c].push_back(root);

    // cout << "level " << c << " -> ";
    // cout << root->data << " ";
    // cout << endl;

    // if (root->left) {
    //     levelorder(root->left, c + 1,m);
    // }

    // if (root->right) {
    //     levelorder(root->right, c + 1,m);
    // }
// }


void levelorder(node* root, int c, map<int, list<node*>>& m) {
    bool flag = true;
    if(root==NULL){
        // return false;
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        flag;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty() || flag!=false){
        node* tmp = q.front();
        q.pop();
        if(tmp->left && tmp->left->data >= tmp->data){
            // cout<<"false\n";
            // return flag;
            flag=false;
            break;
        }
        if(tmp->right && tmp->right->data <= tmp->data){
            // cout<<"false\n";
            // return flag;
            flag=false;
            break;
        }
        m[c].push_back(root);
        cout << "level " << c << " -> ";
        cout << root->data << " ";
        cout << endl;

        if (root->left) {
            levelorder(root->left, c + 1,m);
        }

        if (root->right) {
            levelorder(root->right, c + 1,m);
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
    map<int, list<node*>> m;
    levelorder(root, c, m);
    for (map<int, list<node*>>::iterator mit = m.begin(); mit != m.end(); mit++) {
        cout << mit->first << " -> ";

        for (list<node*>::iterator lit = mit->second.begin(); lit != mit->second.end(); lit++) {
            cout << (*lit)->data << " ";
        }

        cout << endl;
    }
}
