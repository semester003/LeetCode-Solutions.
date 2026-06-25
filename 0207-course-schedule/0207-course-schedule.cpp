class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjacency list 
        vector<vector<int>> adjLs(numCourses) ;
        for( auto edge : prerequisites ){
            int u = edge[0] ;
            int v = edge[1] ;
            
            adjLs[u].push_back(v) ;
              
        }
        
        vector<int> indegree(numCourses) ;
        for(auto edge : prerequisites ){
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }
        
        queue<int> q ;
        
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i) ;
        }
        
        vector<int> topoSort ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            topoSort.push_back(node) ;
            
            for( auto adjacentNode : adjLs[node]){
                indegree[adjacentNode]-- ;
                if( indegree[adjacentNode] == 0) q.push(adjacentNode) ;
            }
        }
        
        if(topoSort.size() == numCourses) return true ;
        else return false ;

    }
        
};