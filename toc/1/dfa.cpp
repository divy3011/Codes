#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=2;//number of input symbols
    int m1=3;//number of productions for each symbol
    int m2=2;
    int m=max(m1,m2);
    map<string,pair<int,int>> mp;
    mp["1"]={0,m1};
    mp["0"]={1,m2};
    vector<vector<vector<string>>> v(n,vector<vector<string>> (m,vector<string> (3,"\0")));
    v[0][0]={"1","q0","q1"};
    v[0][1]={"1","q1","q1"};
    v[0][1]={"1","q2","q1"};
    v[1][0]={"0","q1","q2"};
    v[1][1]={"0","q2","q2"};
    set<string> se;
    se.insert("q2");
    string s;
    cout<<"Please, Enter the input String: ";
    cin>>s;
    string input_symbol,initial_top_of_stack,from_state,to_state,top_of_stack_now,operation,move;
    cout<<"Transition Table is: "<<endl;
    cout<<"input symbol\tfrom state\tto state\n";
    from_state="q0";
    int flag;
    for(int i=0;i<s.size();i++){
        input_symbol=s[i];
        int j=mp[input_symbol].first;
        int iter_m=mp[input_symbol].second;
        flag=0;
        for(int k=0;k<iter_m;k++){
            if(from_state==v[j][k][1]){
                flag=1;
                to_state=v[j][k][2];
                break;
            }
        }
        if(!flag){
            cout<<"string is not accepted by the DFA"<<endl;
            return 0;
        }
        cout<<"\t"<<input_symbol;
        cout<<"\t"<<from_state<<"\t\t";
        cout<<to_state<<endl;
        initial_top_of_stack=top_of_stack_now;
        from_state=to_state;
    }
    if(se.find(from_state)!=se.end()){
        cout<<"string is accepted by the DFA"<<endl;
    }
    else{
        cout<<"string is not accepted by the DFA"<<endl;
    }
    return 0;
}