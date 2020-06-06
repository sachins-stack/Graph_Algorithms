#include<iostream>
using namespace std;
//recursive approach
int mpow(long long a,long long b,long long m){
    if(b==0) return 1;
    if(b==1) return a;
    int res=mpow(a,b/2,m);
    if(b%2==0) return res*res%m;
    return res*res*a%m;
}

int mpow(long long a,long long b,long long m){
    long long res=1;
    while(b>0){
        if(b&1) res= (res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

int main(){
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<mpow(a,b,m);
}