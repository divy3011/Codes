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
vector<vector<string> > ter(26);
vector<string> transition;
bool contain_non_terminal(string test){
    for(int i=0;i<test.size();i++){
        if(test[i]>=65 && test[i]<=90)
            return true;
    }
    return false;
}
bool solve(string test){
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
            for(int j=0;j<ter[test[i]-65].size();j++){
                exam=pre+ter[test[i]-65][j]+post;
                bool flag=solve(exam);
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
    cout<<"\n";
    set<char> non_ter{'S','E'};
    set<char> terminal{'0','1','(',')','+'};
    ter['S'-65].push_back("(E)");
    ter['S'-65].push_back("E+E");
    ter['E'-65].push_back("S");
    ter['E'-65].push_back("1");
    ter['E'-65].push_back("0");
    cout<<"\tnon-terminal symbols are: ";
    int t=non_ter.size()-1;
    for(auto it=non_ter.begin();it!=non_ter.end();it++){
        cout<<(*it);
        if(t){
            cout<<", ";
            t--;
        }
    }
    cout<<endl;
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
    for(i=0;i<ter[18].size();i++){
        cout<<"\tS ---> "<<ter[18][i]<<endl;
    }
    for(i=0;i<26;i++){
        if(i==18 || ter[i].size()==0){
            continue;
        }
        else{
            for(int j=0;j<ter[i].size();j++){
                cout<<"\t"<<char(i+65)<<" ---> "<<ter[i][j]<<endl;
            }
        }
    }
	cout<<"\n\tEnter the string- ";
	cin>>s;
	queue<string> q;
	for(i=0;i<ter[18].size();i++){
		q.push(ter[18][i]);
	}
	bool flag;
    int fl=0;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		flag=solve(temp);
        if(flag){
            fl=1;
            break;
        }
	}
    if(fl==1){
        cout<<"\n\ttransitions are: ";
        cout<<"S ==> ";
        for(int j=transition.size()-1;j>=0;j--){
            cout<<transition[j]<<" ";
            if(j!=0){
                cout<<"==> ";
            }
        }
        cout<<endl;
    }
	if(fl==0){
		cout<<endl<<"\tNO"<<endl<<endl;
	}
    else{
        cout<<endl<<"\tYES"<<endl<<endl;
    }
    return 0;
}