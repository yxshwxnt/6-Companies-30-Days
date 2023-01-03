// Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/ 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        for(auto x:tokens){
            if(x=="+" || x=="-" || x=="*" || x=="/"){
                int op2=st.top();  st.pop();   //uppar wala op2 hoga 
                int op1=st.top();  st.pop();   //neeche wala op1 hoga 

                if(x=="+"){
                    st.push(op1+op2); 
                }
                if(x=="-"){
                    st.push(op1-op2); 
                }
                if(x=="*"){
                    st.push(op1*op2); 
                }
                if(x=="/"){
                    st.push(op1/op2); 
                }
            }
            else{
                stringstream ss(x);    //to convert string to integer
                int data; 
                ss>>data;   //ss ki val -> data me 
                st.push(data); 
            }
        }
        return st.top(); 
    }
};