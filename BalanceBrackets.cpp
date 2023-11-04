#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main(){
    string s;
    cout<<"enter string = ";
    cin>>s;
    stack<char> st;
    // int c;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } 
        // []{}
        // ({[]})
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                cout << "Not valid parenthesis" << endl;
                return 0;
            }

            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                st.pop();
                // c=c*2;
            } 
            else {
                cout << "Not valid parenthesis" << endl;
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"valid parenthesis\n";
        // cout<<c;
    }
    else{
        cout<<"not valid parenthesis\n";
    }
}