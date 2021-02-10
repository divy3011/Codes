#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int main(){
    int n=3;//number of input symbols
    int m1=2;//number of productions for each symbol
    int m2=3;
    int m3=1;
    int m=max(m1,max(m2,m3));
    map<string,pair<int,int>> mp;
    mp["a"]={0,m1};
    mp["b"]={1,m2};
    mp["e"]={2,m3};
    cout<<endl<<"Program for PDA that accepts string of the form {a^nb^2n|n>=1}"<<endl;
    vector<vector<vector<string>>> v(n,vector<vector<string>> (m,vector<string> (7,"\0")));
    v[0][0]={"a","z","q0","q0","push","(a,z/az)","az"};
    v[0][1]={"a","a","q0","q0","push","(a,a/aa)","aa"};
    v[1][0]={"b","a","q0","q1","None","(b,a/a)","a"};
    v[1][1]={"b","a","q1","q2","pop","(b,a/\u03B5)","\u03B5"};
    v[1][2]={"b","a","q2","q1","None","(b,a/a)","a"};
    v[2][0]={"\u03B5","z","q2","qf","None","(\u03B5,z/z)","z"};
    set<string> se;
    se.insert("qf");
    string s1,s;
    cout<<"Please, Enter the input String: ";
    cin>>s;
    s1=s;
    s+="e";
    stack<char> st;
    st.push('z');
    string input_symbol,initial_top_of_stack,from_state,to_state,top_of_stack_now,operation,move;
    cout<<"Transition Table is: "<<endl;
    cout<<"input symbol\tinitial top of stack\tfrom state\tto state\ttop of stack now\toperation\tmove\n";
    initial_top_of_stack='z';
    from_state="q0";
    int flag;
    for(int i=0;i<s.size();i++){
        input_symbol=s[i];
        int j=mp[input_symbol].first;
        int iter_m=mp[input_symbol].second;
        flag=0;
        for(int k=0;k<iter_m;k++){
            if(initial_top_of_stack==v[j][k][1] && from_state==v[j][k][2]){
                flag=1;
                to_state=v[j][k][3];
                operation=v[j][k][4];
                if(operation=="push"){
                    if(v[j][k][6].size()!=1 && v[j][k][6]!="\u03B5"){
                        int count=v[j][k][6].size()-1;
                        while(count--){
                            st.push(s[i]);
                            top_of_stack_now=st.top();
                        }
                    }
                }
                if(operation=="pop"){
                    st.pop();
                    top_of_stack_now=st.top();
                }
                if(operation=="None"){
                    top_of_stack_now=st.top();
                }
                move=v[j][k][5];
                break;
            }
        }
        if(!flag){
            cout<<"string "<<s1<<" is not accepted by the PDA"<<endl<<endl;
            return 0;
        }
        if(s[i]=='e'){
            cout<<"\t\u03B5";
        }
        else{
            cout<<"\t"<<input_symbol;
        }
        cout<<"\t\t"<<initial_top_of_stack<<"\t\t"<<from_state<<"\t\t";
        cout<<to_state<<"\t\t\t"<<top_of_stack_now<<"\t\t"<<operation<<"\t\t"<<move<<endl;
        initial_top_of_stack=top_of_stack_now;
        from_state=to_state;
    }
    if(se.find(from_state)!=se.end()){
        cout<<"string "<<s1<<" is accepted by the PDA"<<endl;
    }
    else{
        cout<<"string "<<s1<<" is not accepted by the PDA"<<endl;
    }
    cout<<endl;
    return 0;
}