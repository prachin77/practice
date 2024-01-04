#include<iostream>
#include<string>
using namespace std;
typedef class Node{
    public:
        int a;
        Node* prev;
        Node* next;
}node;

void start(node* head,int startData){
    node* p = new node;
    p->next=head;
    p->a=startData;
    head=p;
    node* q = new node;
    q=head;
    while(q!=NULL){
        cout<<q->a<<" ";
        q=q->next;
    }
}

void sort(node* head){
    node* p = new node;
    node* q = new node;
    node* tmp = new node;
    for(p=head;p!=NULL;p=p->next){
        for(q=head;q->next!=NULL;q=q->next){
            if(q->a > q->next->a){
                tmp->a = q->a;
                q->a=q->next->a;
                q->next->a=tmp->a;
            }
        }
    }
    p=head;
    while(p!=NULL){
        cout<<p->a<<" ";
        p=p->next;
    }
}

void del(node* head){
    node * p = new node;
    node * q = new node;
    p=head;
    q=head->next;
    cout<<"1. delete from start\n";
    cout<<"2. delete from middle\n";
    cout<<"3. delete from end\n";

    int n;
    cout<<"enter number = ";
    cin>>n;
    switch (n)
    {
        case 1:{
            p=q;
            // head=head->next;
            // free(p);
            while(p!=NULL){
                cout<<p->a<<" ";
                p=p->next;
            }
            break;
        }
        case 2:{
            int sNum;
            cout<<"number that you wanna delete = ";
            cin>>sNum;
            while(q->a!=sNum && q!=NULL){
                p=p->next;
                q=q->next;                
            }
            if(q->a==sNum){
                p->next=q->next;                    
                free(q);
            }
            p=head;
            while(p!=NULL){
                cout<<p->a<<" ";
                p=p->next;
            }
            break;
        }
        case 3:{
            while(q!=NULL){
                p=p->next; 
                q=q->next;      
                if(q->next==NULL){
                    p->next=NULL;
                    free(q);
                    break;
                }          
            }
            p=head;
            while(p!=NULL){
                cout<<p->a<<" ";
                p=p->next;
            }
            break;
        }
        default:
            break;
    }
}

void tra(node* head){
    node * p = new node;
    p=head;
    while(p!=NULL){
        cout<<p->a<<" ";
        p=p->next;
    }

}


void insert(){
    int n,i;
    node* head=NULL;
    node* tail=NULL;

    cout<<"no of nodes : ";
    cin>>n;

    for(i=1;i<=n;i++){
        int num;
        cout<<"enter number = ";
        cin>>num;
        node* nn=new node;
        nn->prev=NULL;
        nn->a=num;
        nn->next=NULL;

        if(head==NULL){
            head=nn;
            tail=nn;
        }
        else{
            tail->next=nn;
            nn->prev=tail;
            tail=nn;
        }
    }

    cout<<"1 FOR TRAVERSE\n";
    cout<<"2 FOR DELETE\n";
    cout<<"3 FOR SORTING\n";
    cout<<"4 FOR INSERT AT START\n";

    int choice;
    cout<<"enter number : ";
    cin>>choice;
    switch(choice){
        case 1:{
            tra(head);
            break;
        }
        case 2:{
            del(head);
            break;
        }
        case 3:{
            sort(head);
            break;
        }
        case 4:{
            int startData;
            cout<<"data that you wanna enter at start = ";
            cin>>startData;
            start(head,startData);
            break;
        }
        default:{
            cout<<"wrong choice : ";
            break;
        }
    }
}

int main(){
    int n;
    cout<<"1 FOR INSERT\n";

    cout<<"enter number : ";
    cin>>n;
    if(n==1){
        insert();
    }
    else{
        cout<<"wrong number";
    }

}