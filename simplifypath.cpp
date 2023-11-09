// Given a string path, which is an absolute path (starting with a slash '/') to
//  a file or directory in a Unix-style file system, convert it to the simplified 
// canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, a
//  double period '..' refers to the directory up a level, and any multiple 
// consecutive slashes (i.e. '//') are treated as a single slash '/'. 
// For this problem, any other format of periods such as '...' are treated as 
// file/directory names.

// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to
//  the target file or directory (i.e., no period '.' or double period '..')
// Return the simplified canonical path.

 

// Example 1:

// Input: path = "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.
// Example 2:

// Input: path = "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op
// , as the root level is the highest level you can go.
// Example 3:

// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

// path = "/a/./b/../../c/"
// /a/b/c 
// Use Testcase
// Output
// "/a////b//////c"
// Expected
// "/c"

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string simplifypath(string s){
    int i,j=0;
    stack<char> st;
    st.push('/');
    int c=0;
    for(i=1;i<s.size();i++){
        if(s[i]=='/'){
            if(i==s.size()-1){
                break;
            }
            if(s[i-1]=='/'){
                i=i;
            }
            else{
                st.push(s[i]);
            }
        }
        else if(s[i]=='.'){
            if(s[i+1]=='.'){
                // while(st.top()!='/'){
                //     st.pop();
                // }
                 
            }
            else{
                i=i;
            }
        }
        else{
            st.push(s[i]);
        }
    }
    
    while(!st.empty()){
        char ch = st.top();
        cout<<ch;
        st.pop();
    }
}

int main(){
    string s="/a/./b/../../c/"; // -> /a/b/.. -> /a/. -> "empty stack" -> /c
    // string s="/home///////foo//////sdfsd";
    // string s="/../";
    simplifypath(s);
    
}