class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjacency list 
        vector<vector<int>> adjLs(numCourses) ;
        vector<int> indegree(numCourses , 0) ;
        // building graph
        for( auto edge : prerequisites ){
            int u = edge[0] ;
            int v = edge[1] ;
            
            adjLs[v].push_back(u) ;
            indegree[u]++;
              
        }
        
        queue<int> q ;
        
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i) ;
        }

        int topoSort = 0 ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            topoSort++ ;
            
            for( auto adjacentNode : adjLs[node]){
                indegree[adjacentNode]-- ;
                if( indegree[adjacentNode] == 0) q.push(adjacentNode) ;
            }
        }
        
        if(topoSort == numCourses) return true ;
        else return false ;

    }
        
};