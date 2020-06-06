#include<iostream>
using namespace std;


// recursive approach
long long mpow(long long a,long long b){
    if(b==0) return 1;
    if(b==1) return a;
    long long res=mpow(a,b/2);
    if(b%2==0) return res*res;
    else return res*res*a;
}

//iterative approach
long long mpow(long long a,long long b){
    long long res=1;
    while(b>0){
        if(b & 1) res*=a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    long long a,b;
     cin>>a>>b;
     cout<<mpow(a,b);
     return 0;
 }

