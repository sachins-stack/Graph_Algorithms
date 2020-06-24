/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites,
 for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs,
is it possible for you to finish all courses?

*/

class Solution {
public:
    //bool dfs(vector<vector<int>>& v,int n,)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<int> result;
        stack<int> dfs;
        int n=prerequisites.size();
        //unordered_set<int> s;
        for(auto a:prerequisites){
            v[a[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(v[i]==0) dfs.push(i); 
        }
        int count =0;
        while(!dfs.empty()){
            int temp=dfs.top();dfs.pop();
            cout<<temp;
            count++;
            for(int i=0;i<n;i++){
                if(prerequisites[i][1] == temp){
                    v[prerequisites[i][0]]--;
                    if(v[prerequisites[i][0]]==0){
                                                  dfs.push(prerequisites[i][0]);}
                }
            }
            result.push_back(temp);
        }
        for(int i=0;i<numCourses;i++) cout<<result[i];
        return count==numCourses;
    }
};