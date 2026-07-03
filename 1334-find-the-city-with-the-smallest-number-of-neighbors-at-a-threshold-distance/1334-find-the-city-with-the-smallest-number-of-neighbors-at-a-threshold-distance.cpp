class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> cost( n , vector<int> ( n , 1e9));
        // initial cost costrix 
        for( auto edge : edges ){
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;

            cost[u][v] = wt ;
            cost[v][u] = wt ;

        }
        for( int i=0 ; i<n ; i++){
            for( int j=0 ; j<n ; j++){
                if( i == j){
                    cost[i][j] = 0 ;
                }
            }
        }

        // computing ultimate matrix
        for( int k = 0  ; k < n ; k++){
            for( int i = 0 ;  i < n ; i++){
                for( int j = 0 ;  j < n ; j++ ){
                    cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j]) ;
                }
            }
        }

        vector<vector<int>> cities(n) ;
        for(int i = 0 ; i < n ; i++){
            for( int j = 0 ; j<n ; j++){
                if( i != j && cost[i][j] <= distanceThreshold  ){
                    cities[i].push_back(j) ;
                }
            }
        }
        int ans = -1 ;
        int no = n-1 ;

        for( int i = 0 ; i < n ; i++){
            
            if( cities[i].size() <= no ){
                no = cities[i].size() ;
                ans = i ;
            }
        }
        return ans ;








        
    }
};