#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        ll a[n+2];
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
    }
}