#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        map<ll,ll> fre;
        set<ll> st;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            a[i]=x;
            // st.insert(x);
            // fre[x]++;
        }
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" ";
        //     cout<<endl;
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
            ll x=log2(a[i])+1;
            // cout<<x<<" ";
            mp[x]++;
        }
        // cout<<endl;
        ll ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if((*it).second>=2){
                ll x = (*it).second;
                ans=ans+((x*(x-1))/2);
            }
        }
        // for(auto it=fre.begin();it!=fre.end();it++){
        //     if((*it).second>=2){
        //         ans=ans+(*it).second;
        //     }
        // }
        cout<<ans<<endl;
    }
}
// 2 2 2 3 3 3