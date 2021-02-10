#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
string s,temp;
int i;
vector<string> str,transition;
vector<string> ter{"aSa","bSb","cSc","a","b","c","aa","bb","cc"};
bool solve(string test,string s){
    if(test.size()>s.size()){
        return false;
    }
    if(test==s){
        transition.push_back(test);
        return true;
    }
    for(int i=0;i<test.size();i++){
        if(test[i]>=65 && test[i]<=90){
            string exam,pre,post;
            for(int u=0;u<i;u++){
                pre.push_back(test[u]);
            }
            for(int u=i+1;u<test.size();u++){
                post.push_back(test[u]);
            }
            for(int j=0;j<ter.size();j++){
                exam=pre+ter[j]+post;
                bool flag=solve(exam,s);
                if(flag){
                    transition.push_back(test);
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    cout<<endl;
    set<char> non_ter {'S'};
    set<char> terminal {'a','b','c'};
    cout<<"\tnon-terminal symbols are: ";
    for(auto it=non_ter.begin();it!=non_ter.end();it++){
        auto is=it;
        is++;
        if(is!=non_ter.end()){
            cout<<(*it)<<", ";
        }
        else{
            cout<<(*it)<<endl;
        }
    }
    cout<<"\tterminal symbols are: {";
    for(auto it=terminal.begin();it!=terminal.end();it++){
        auto is=it;
        is++;
        if(is!=terminal.end()){
            cout<<(*it)<<", ";
        }
        else{
            cout<<(*it);
        }
    }
    cout<<"}"<<endl<<endl;
    cout<<"\tGrammar is: "<<endl;
    for(i=0;i<ter.size();i++){
        cout<<"\tS ---> "<<ter[i]<<endl;
    }
    cout<<"\tenter the length of palindrome: ";
    int n;
    cin>>n;
	queue<string> q;
	for(i=0;i<ter.size();i++){
		q.push(ter[i]);
	}
    cout<<endl<<"\ttransitions for generating all palindromes of length "<<n<<" are: "<<endl;
	while(!q.empty()){
        int flag=0;
		temp=q.front();
		q.pop();
		if(temp.size()>n+1){
            continue;
        }
        if(temp.size()==n){
            for(i=0;i<temp.size();i++){
                if(temp[i]>=65 && temp[i]<=90){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                str.push_back(temp);
            }
        }
        if(temp.size()!=n || flag){
            for(int i=0;i<temp.size();i++){
                if(temp[i]>=65 && temp[i]<=90){
                    string exam,pre,post;
                    for(int u=0;u<i;u++)
                        pre.push_back(temp[u]);
                    for(int u=i+1;u<temp.size();u++)
                        post.push_back(temp[u]);
                    for(int j=0;j<ter.size();j++){
                        exam=pre+ter[j]+post;
                        if(exam.size()<n+2)
                            q.push(exam);
                    }
                    break;
                }
            }
        }
	}
    // set<string> ans;
    for(int j=0;j<str.size();j++){
        // ans.insert(str[i]);
        queue<string> qstr;
	    for(i=0;i<ter.size();i++){
		    qstr.push(ter[i]);
	    }
	    bool flag;
        int fl=0;
	    while(!qstr.empty()){
		    temp=qstr.front();
		    qstr.pop();
		    flag=solve(temp,str[j]);
            if(flag){
                fl=1;
                break;
            }
	    }
        if(fl==1){
            cout<<"\ttransitions is: ";
            cout<<"S ==> ";
            for(int k=transition.size()-1;k>=0;k--){
                cout<<transition[k]<<" ";
                if(k!=0){
                    cout<<"==> ";
                }
            }
            cout<<endl;
        }
        transition.clear();
    }
    cout<<endl;
    cout<<"\tthus, all palindromes of length "<<n<<" are: ";
    cout<<"{";
    for(int i=0;i<str.size();i++){
        cout<<str[i];
        if(i!=str.size()-1){
            cout<<", ";
        }
    }
    cout<<"}"<<endl<<endl;
    return 0;
}