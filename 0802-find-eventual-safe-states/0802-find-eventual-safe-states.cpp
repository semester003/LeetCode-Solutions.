class Solution {
private:
    bool dfs( int node , vector<int>& vis , vector<int>& pathVis , vector<vector<int>>& graph , int V , vector<int>& safe ){
        
        vis[node] = 1 ;
        pathVis[node] = 1 ; 
        
        // traverse for graphacent node 
        for( auto it : graph[node]){
            // if not visited then visit it
            if( !vis[it] ){
                if( dfs( it , vis , pathVis, graph , V , safe ) == true ) return true  ;
            } 
            // if node has been previoulsy visited 
            // check if it has been visited on the same path 
            else if(pathVis[it] ) return true ;
            
        }
        // if recusrion is completed for a node and couldn't find the cycle then 
        // before returning
        safe.push_back(node) ;
        pathVis[node] = 0 ;
        return false ;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
        int V = graph.size() ; 
        vector<int> vis( V , 0 ) ;
        vector<int> pathVis( V , 0 ) ;
        vector<int> safe ;
        int check = 0 ;
        
        for( int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , vis , pathVis , graph , V , safe ) ;
            }
        }
        sort(safe.begin() , safe.end()) ;
        return safe ;

        
    }
};