// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0


#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string s;
    cout<<"enter string = ";
    cin>>s;
    int i,j;
    stack<char> st;
    // int c=0;
    string paran="";
    // )()())
    // (()()(
    int c=0;
    for(char ch : s){
        if(ch==s.size()){
            break;
        }
        if(ch=='[' || ch=='(' || ch=='{'){
            st.push(ch);
        }
        else{
            if(st.empty()){
                // cout<<"empty\n";
                // return 0;
                continue;
            }
            char top = st.top();
            for(int j=i;j<s.size();j++){
                if((s[j] == ')' && top == '(') || (s[j] == ']' && top == '[') || (s[j] == '}' && top == '{')){
                    st.pop();
                    c++;
                    break;
                }
            }
           
        }
    }
    if(c!=0){
        cout<<c<<endl;
    }
    else{
        cout<<c<<endl;
    }
}                                               