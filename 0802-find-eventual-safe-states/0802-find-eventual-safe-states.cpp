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
    /* vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
        int V = graph.size() ; 
        vector<int> vis( V , 0 ) ;
        vector<int> pathVis( V , 0 ) ;
        vector<int> safe ;
        vector<int> check(V , 0) ;   // if we use check , there will be no need to sort the safe vector at the last 
        
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

        
    } */

    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        // reversing the graph 
        int V = graph.size() ;
        vector<int> indegree(V) ;
        vector<vector<int>> revGraph(V) ;
        for( int i = 0 ; i < V ; i++ ){
            for( auto it : graph[i] ){
                indegree[i]++ ;
                revGraph[it].push_back(i) ;
            }
        }
        queue<int> q ;
        for(int i = 0 ; i < V ; i++ ){
            if( indegree[i] == 0 ) q.push(i) ;    // element with indegree zero will be the safe node, cause we have reversed te he graph
        }

        vector<int> check (V ,0) ;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            check[node] = 1 ;

            for( auto neigh : revGraph[node]){
                indegree[neigh]-- ;
                if( indegree[neigh] == 0 ) q.push(neigh) ;
            }

        }
        vector<int> safe ;
        for( int i = 0 ; i < V ; i++ ){
            if( check[i] == 1) safe.push_back(i) ;
        }
        return safe  ;


    }
};




















