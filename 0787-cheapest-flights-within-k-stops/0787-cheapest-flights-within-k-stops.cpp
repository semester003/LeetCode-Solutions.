class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // making graph
        vector<vector<pair<int,int>>> adj(n) ;
        for( auto it  : flights ){
            int u = it[0] ;
            int v = it[1] ;
            int c = it[2] ;  // dist

            adj[u].push_back({v , c}) ;
        }
        // array to keep track of dist 
        vector<int> dist(n  , 1e9) ;
        dist[src] = 0 ;  // dist to reach source is 0

        queue<pair< int , pair< int , int >>> q ;
        q.push({ 0 , { src , 0 }}) ;

        while(!q.empty()){
            auto it = q.front() ;
            q.pop() ;
            int stops = it.first ;
            int node = it.second.first ;
            int dis = it.second.second ;

            if( stops > k )   continue ;  // no need to go further in this iteration

            for( auto it : adj[node]){
                int neigh = it.first ;
                int edgewt = it.second ;

                if( dis + edgewt < dist[neigh] ) {
                    dist[neigh] = dis + edgewt ;
                    q.push( { stops + 1 , { neigh , dist[neigh] } } ) ;
                }

            }
        }
        if( dist[dst] == 1e9) return -1 ;
        return dist[dst] ;
        



        
    }
};