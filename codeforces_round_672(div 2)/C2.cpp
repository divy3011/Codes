#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
ll a[1000000];
ll solve(ll a[],int i,ll ans){
    if(i==0 || i==n+1) return ans;
    if(a[i]>a[i-1] && a[i]>a[i+1]) ans-=a[i];
    if(a[i]<a[i-1] && a[i]<a[i+1]) ans+=a[i];
    return ans;
}
ll solve2(ll a[],int i,ll ans){
    if(i==0 || i==n+1) return ans;
    if(a[i]>a[i-1] && a[i]>a[i+1]) ans+=a[i];
    if(a[i]<a[i-1] && a[i]<a[i+1]) ans-=a[i];
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ll ans =0 ;
        a[0]=a[n+1]=-1;
        int flip=0;
        for(int i=1;i<=n;i++){
            if(!flip){
                if(a[i]>a[i+1] && a[i]>a[i-1]){
                    ans+=a[i];
                    flip=1;
                }
            }
            else{
                if(a[i]<a[i+1] && a[i]<a[i-1]){
                    ans-=a[i];
                    flip=0;
                }
            }
        }
        cout<<ans<<endl;
        while(q--){
            int l,r;
            cin>>l>>r;
            ans = solve(a,l-1,ans);
            ans = solve(a,l,ans);
            ans = solve(a,l+1,ans);
            if(r!=l){
                if(r-1!=l && r-1!=l+1) ans=solve(a,r-1,ans);
                if(r!=l+1) ans=solve(a,r,ans);
                ans=solve(a,r+1,ans);
            }
            ll temp=a[l];
            a[l]=a[r];
            a[r]=temp;
            ans=solve2(a,l-1,ans);
            ans=solve2(a,l,ans);
            ans=solve2(a,l+1,ans);
            if(l!=r){
                if(r-1!=l && r-1!=l+1) ans=solve2(a,r-1,ans);
                if(r!=l+1) ans=solve2(a,r,ans);
                ans=solve2(a,r+1,ans);
            }
            cout<<ans<<endl;
        }
    }
}