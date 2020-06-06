//for finding the no. of paths of fixed k length going from u to v vertices 
//you have to multiply the adjacent matrix 
// by k times. it will take O(pow(G,k)) time complexity but
//by using binary exponentiation it will take O(pow(n,3)*log K);  


#include<iostream>

using namespace std;
#define N 3

void Multiply(int a[N][N],int b[N][N],int res[N][N]){
    int mul[N][N];
    cout<<"enter Multiply";
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                mul[i][j]=0;
                for(int k=0;k<N;k++)
                    mul[i][j]+=a[i][k]*b[k][j];
            }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            res[i][j]=mul[i][j];
    }
    
    // for (int i = 0; i < N; i++) { 
    //     for (int j = 0; j < N; j++) 
    //         cout << res[i][j] << " "; 
    //     cout << "\n"; 
    // } 

}

void power(int G[N][N],int res[N][N],int k){
    if(k==1){
        cout<<"enter Power";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                res[i][j]=G[i][j];
        }
        return;
    }
    power(G,res,k/2);
    Multiply(G,G,res);
    if(k%2==0) Multiply(G,G,res);
    else Multiply(res,G,res);

}

int main(){
    int G[N][N]={ { 1, 1, 1 }, 
                  { 0, 0, 1 }, 
                  { 0, 1, 0 }};
    int k=2,res[N][N];
    power(G,res,k);
    cout<<endl;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << res[i][j] << " "; 
        cout << "\n"; 
    } 
    return 0;
}