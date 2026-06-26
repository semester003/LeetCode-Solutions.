class Solution {
private:
    bool dfs( int node , vector<int>& vis , vector<int>& pathVis , vector<vector<int>>& graph , int V , vector<int>& safe
                , vector<int>& check ){
        
        vis[node] = 1 ;
        pathVis[node] = 1 ; 
        
        // traverse for graphacent node 
        for( auto it : graph[node]){
            // if not visited then visit it
            if( !vis[it] ){
                if( dfs( it , vis , pathVis, graph , V , safe , check ) == true ){
                    check[it] = 0 ;  // that cant be a safe node 
                    return true ;
                } 
            } 
            // if node has been previoulsy visited 
            // check if it has been visited on the same path 
            else if(pathVis[it] ){
                check[it] = 0 ;
                return true ;

            }
            
        }
        // if recusrion is completed for a node and couldn't find the cycle then 
        // before returning
        //safe.push_back(node) ;
        check[node] = 1 ;
        pathVis[node] = 0 ;
        return false ;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
        int V = graph.size() ; 
        vector<int> vis( V , 0 ) ;
        vector<int> pathVis( V , 0 ) ;
        vector<int> safe ;
        vector<int> check(V , 0) ;
        
        for( int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , vis , pathVis , graph , V , safe ,check ) ;
            }
        }
        for(int i = 0 ; i<V ; i++){
            if(check[i] == 1 ) safe.push_back(i) ;
        }
        // sort(safe.begin() , safe.end()) ;
        return safe ;

        
    }
};