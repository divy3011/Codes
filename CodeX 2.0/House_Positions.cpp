#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        cpp_int n,m;
        cin>>n>>m;
        cpp_int u;
        m--;
        n--;
        if(m<=n){
            u=(m*(m+1)*(2*n*m+4*n+2-m*m-m))/12;
        }
        else{
            cpp_int temp=m;
            m=n;
            n=temp;
            u=(m*(m+1)*(2*n*m+4*n+2-m*m-m))/12;
        }
        std::cout << u%1000000007 << std::endl;
    }
	// your code goes here
	return 0;
}