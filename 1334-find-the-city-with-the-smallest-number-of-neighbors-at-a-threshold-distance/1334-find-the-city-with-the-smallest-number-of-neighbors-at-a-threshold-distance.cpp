class Solution {
private:
    vector<int> dijkstra(int src,vector<vector<pair<int,int>>>& adj , int n){

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;

        vector<int> dist(n,1e9);

        dist[src]=0;

        pq.push({0,src});

        while(!pq.empty()){
            auto it = pq.top() ;
            int node = it.second ;
            int dis = it.first ;
            pq.pop() ;

            for( auto neigh : adj[node]){
                int neighNode = neigh.first ;
                int edgewt =  neigh.second ;
                if( dis + edgewt < dist[neighNode] ){
                    dist[neighNode] = dis + edgewt ;
                    pq.push( { dist[neighNode] , neighNode}) ;
                }
            }

    
        }

        return dist ;
    }

public:
    /* int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> cost( n , vector<int> ( n , 1e9));
        // initial cost costrix 
        for( auto edge : edges ){    //SC  O(NxN)
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;

            cost[u][v] = wt ;
            cost[v][u] = wt ;

        }
        for( int i=0 ; i<n ; i++){
                cost[i][i] = 0 ;
        }
        

        // computing ultimate matrix
        for( int k = 0  ; k < n ; k++){        // O(NxNxN)
            for( int i = 0 ;  i < n ; i++){
                for( int j = 0 ;  j < n ; j++ ){
                    if( cost[i][k] != 1e9 && cost[k][j] ){
                        cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j]) ;
                    }
                    
                }
            }
        }
        int ans = -1 ;
        int noOfReachableCities = n-1 ;

        for(int i = 0 ; i < n ; i++){   //O(NxN)
            int cnt = 0 ;
            for( int j = 0 ; j<n ; j++){
                if( i != j && cost[i][j] <= distanceThreshold  ){
                    cnt++ ;
                }
            }
            if( cnt <= noOfReachableCities ){
                ans = i ;
                noOfReachableCities = cnt ;
            }
        }

        return ans ;

    // TC O(NxNxN)
    // SC O(NxN)   
    } */

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){

        vector<vector<pair<int,int>>> adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int ans = -1 ;
        int noOfReachableCities = n-1 ;

        for(int src=0; src<n; src++){    // caliing dijkstra for each node

            vector<int> dist = dijkstra(src , adj , n);

            int cnt = 0;

            for(int j=0;j<n;j++){
                if(j!=src && dist[j] <= distanceThreshold)
                    cnt++;
            }

            if( cnt <= noOfReachableCities ){
                ans = src ;
                noOfReachableCities = cnt ;
            }
        }

        return ans ;

    }
};




























