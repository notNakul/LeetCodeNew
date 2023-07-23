class Solution {
private:
    bool bfs(int src,vector<vector<int>>& graph, vector<int>& vis){
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                    if(vis[it]==-1){
                        vis[it]=!vis[node];
                        q.push(it);
                    }
                    else if(vis[it]==vis[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(graph)
        //     }
        // }
        vector<int> vis(n,-1);
        for(auto it: graph){
            for(auto i:it){
                if(vis[i]==-1){
                    if(bfs(i,graph,vis)==false) return false;
                }
            }
        }
        return true;
    }
};