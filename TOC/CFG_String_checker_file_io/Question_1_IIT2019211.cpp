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
    cout<<"\n\tS should be your start symbol"<<endl;
    cout<<"\tname of file containing grammar should be input.txt"<<endl;
    cout<<"\tinput.txt should be in same folder as the code"<<endl<<endl;
    set<char> non_ter,terminal;
    int fd=open("input.txt",O_RDONLY);
    if(fd>=0){
        int endOfFile=1;
        int h=0;
        char buffer,start_buffer;
        string s1;
        int space=0;
        while((endOfFile=read(fd,&buffer,1))>=0){
            if(h==0){
                if(buffer!='\n')
                    non_ter.insert(buffer);
                start_buffer=buffer;
                h++;
            }
            if(h==1){
                h++;
                continue;
            }
            if(h==2){
                if(buffer=='\n' || endOfFile==0){
                    space=0;
                    ter[start_buffer-65].push_back(s1);
                    s1.clear();
                    h=0;
                }
                else{
                    if(space!=0){
                        // cout<<buffer<<endl;
                        if(buffer>=65 && buffer<=90);
                        else
                            terminal.insert(buffer);
                        s1.push_back(buffer);
                    }
                    else
                        space++;                    
                }
            }
            if(endOfFile==0){
                break;
            }
        }
    }
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
		if((ter[18][i][0]>=65 && ter[18][i][0]<=90) || ter[18][i][0]==s[0])
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
		cout<<endl<<"\tstring "<<s<<" is not acceptable by CFG"<<endl<<endl;
	}
    else{
        cout<<endl<<"\tstring "<<s<<" is acceptable by CFG"<<endl<<endl;
    }
    return 0;
}