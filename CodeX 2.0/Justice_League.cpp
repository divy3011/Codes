#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define mp make_pair
const int MOD = 1e9 + 7;
void cos(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
inline int add(int a, int b){
    a += b;
    if(a >= MOD)a -= MOD;
    return a;
}
inline int sub(int a, int b){
    a -= b;
    if(a < 0)a += MOD;
    return a;
}
inline int mul(int a, int b){
    return (int)((long long) a * b %MOD);
}
inline int binpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1)res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}
inline int inv(int a){
    return binpow(a, MOD - 2);
}
ll fastexp(ll base,ll exp){
    ll oddc=1,store=base;
    while(exp>0){
        if(exp%2==1)
        oddc=oddc*base%MOD;
        store=store*store%MOD;
        exp/=2;
    }
    return oddc;
}
int main(){
    cos();
	int t; cin>>t;
	while(t--){
		int n,m,s;
        cin>>n>>m>>s;
        int rem1=m%n;
        if(rem1==0){
            rem1=n;
        }
        int rem2=(rem1+s-1)%n;
        if(rem2==0){
            rem2=n;
        }
        cout<<rem2<<endl;
	}

    return 0;
}