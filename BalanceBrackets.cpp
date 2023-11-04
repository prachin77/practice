#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main(){
    string s;
    cout<<"enter string = ";
    cin>>s;
    stack<char> st;
    int i;
    // for(i=0;i<s.size();i++){
    //     if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
    //         st.push(s[i]);
    //     }
    // }

    // for(i=0;i<s.size();i++){
    //     if( (s[i]==')' && st.top()=='(') ||  (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{')){
    //         // if(st.top()==s[i]){
    //         //     st.pop();
    //         // }
    //         st.pop();
    //     }
    // }
    
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
            } 
            else {
                cout << "Not valid parenthesis" << endl;
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"valid parenthesis\n";
    }
    else{
        cout<<"not valid parenthesis\n";
    }
}