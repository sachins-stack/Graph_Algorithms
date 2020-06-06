//This Algo is to find the shortest path from u to V vetices with 
// fixed length K. Time Complexity of this is O(pow()V,K).
// this algo can be optimized by DP with  Time Complexity of O(pow(V,3)*K).

#include<iostream>
#include<limits.h>
using namespace std;
#define V 4
#define INF INT_MAX

int shortestPath(int g[V][V],int u,int v,int k){
    if(k==0) return 0;
    if(k==1 && g[u][v]!=INF) return g[u][v];
    if(k<=0) return INF;
    int res=INF;
    for(int i=0;i<V;i++){
        if(u!=i && v!=i && g[u][i]!= INF ){
            int path=shortestPath(g,i,v,k-1);
            if(path!=INF){
                res=min(res,g[u][i]+path);
            }
        }
    }
    return res;
}


int main() 
{ 
    /* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 1, 3, 2}, 
                        {INF, 0, INF, 7}, 
                        {INF, INF, 0, 6}, 
                        {INF, INF, INF, 0} 
                      }; 
    int u = 0, v = 3, k = 2; 
    cout << "Weight of the shortest path is " << 
          shortestPath(graph, u, v, k); 
    return 0; 
} 