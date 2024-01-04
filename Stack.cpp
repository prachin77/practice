#include<iostream>
using namespace std;
class Stack{
    public:
        int* arr;
        int top;
        int size;
        Stack(int stackSize){
            stackSize = size;
            arr = new int[size];
            top = -1;
        }
        void push(int data){
            if(top==size-1){
                cout<<"stack full \n";
                return;
            }
            top++;
            arr[top]=data;
        }
        void pop(){
            if(top == -1){
                cout<<"Stack empty \n";
                return;
            }
            int data = arr[top];
            top--;
        }
        int stackTop(){
            if(top == -1){
                cout<<"stack empty \n";
                return -1;
            }
            return arr[top];
        }
};
int main(){
    int n;
    int data;
    Stack stk = Stack(5);
    do
    {
        cout<<"1. PUSH\n";
        cout<<"2. POP\n";
        cout<<"3. TOP\n";
        cout<<"enter number = ";
        cin>>n;
        switch(n){
            case 1:{
                cout<<"enter data : ";
                cin>>data;
                stk.push(data);
                break;
            }
            case 2:{
                stk.pop();
                cout<<"data popped\n";
                break;
            }
            case 3:{
                cout<<"Data = "<<stk.stackTop()<<"\n";
                break;
            }
            default:{
                cout<<"wrong number \n";
                break;
            }
        }
    } while (n != 4);
    
}