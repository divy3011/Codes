#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int j=k;
        for(int i=n-2;i>=0,j!=0;i--,j--){
            a[n-1]=a[n-1]+a[i];
            a[i]-=a[i];
        }
        ll max_int=-1e18,min_int=1e18;
        for(int i=0;i<n;i++){
            min_int=min(min_int,a[i]);
            max_int=max(max_int,a[i]);
        }
        cout<<max_int-min_int<<endl;
    }
}