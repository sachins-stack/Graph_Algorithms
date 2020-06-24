/*
Water can only flow in four directions 
(up, down, left, or right) from a cell to another one with height equal or lower.

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int i,int j,int pValue,vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>matrix.size()-1 || j>matrix[0].size()-1) return ;
        if(matrix[i][j] < pValue) return;
        if(ocean[i][j]==1) return;
        
        ocean[i][j]=1;
        
        dfs(matrix,i+1,j,matrix[i][j],ocean);
        dfs(matrix,i,j+1,matrix[i][j],ocean);
        dfs(matrix,i,j-1,matrix[i][j],ocean);
        dfs(matrix,i-1,j,matrix[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=m?matrix[0].size():0;
        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            dfs(matrix,i,0,INT_MIN,pacific);
            dfs(matrix,i,n-1,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(matrix,0,i,INT_MIN,pacific);
            dfs(matrix,m-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1) res.push_back({i,j});
            }
        }
        return res;
    }
};