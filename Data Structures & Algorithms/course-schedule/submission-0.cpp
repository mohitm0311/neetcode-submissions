class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(n);
        vector<int> indegree(n,0);
        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][0];
            int v =prerequisites[i][1];
            adjList[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto neigh: adjList[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return (topo.size()==n);
    }
};
