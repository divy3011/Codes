#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<pair<int,pair<int,int>>>> v(3,vector<pair<int,pair<int,int>>> (1001,{0,{0,0}}));
    v[0][3]={1,{0,0}};
    v[1][5]={0,{1,0}};
    v[2][7]={0,{0,1}};
    v[0][6]={2,{0,0}};
    pair<int,pair<int,int>> p = {0,{0,0}};
    for(int i=8;i<=1000;i++){
        if(v[0][i-3]!=p){
            v[0][i]=v[0][i-3];
            v[0][i].first=v[0][i].first+1;
        }
        else if(v[1][i-3]!=p){
            v[0][i]=v[1][i-3];
            v[0][i].first=v[0][i].first+1;
        }
        else if(v[2][i-3]!=p){
            v[0][i]=v[2][i-3];
            v[0][i].first=v[0][i].first+1;
        }
        if(v[0][i-5]!=p){
            v[0][i]=v[0][i-5];
            v[0][i].second.first=v[0][i].second.first+1;
        }
        else if(v[1][i-5]!=p){
            v[0][i]=v[1][i-5];
            v[0][i].second.first=v[0][i].second.first+1;
        }
        else if(v[2][i-5]!=p){
            v[0][i]=v[2][i-5];
            v[0][i].second.first=v[0][i].second.first+1;
        }
        if(v[0][i-7]!=p){
            v[0][i]=v[0][i-7];
            v[0][i].second.second=v[0][i].second.second+1;
        }
        else if(v[1][i-7]!=p){
            v[0][i]=v[1][i-7];
            v[0][i].second.second=v[0][i].second.second+1;
        }
        else if(v[2][i-7]!=p){
            v[0][i]=v[2][i-7];
            v[0][i].second.second=v[0][i].second.second+1;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(v[0][n]!=p){
            cout<<v[0][n].first<<" "<<v[0][n].second.first<<" "<<v[0][n].second.second<<endl;
        }
        else if(v[1][n]!=p){
            cout<<v[1][n].first<<" "<<v[1][n].second.first<<" "<<v[1][n].second.second<<endl;
        }
        else if(v[2][n]!=p){
            cout<<v[2][n].first<<" "<<v[2][n].second.first<<" "<<v[2][n].second.second<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}