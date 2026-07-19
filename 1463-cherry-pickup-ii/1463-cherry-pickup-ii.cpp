class Solution {
private:
    int f(int i , int j1 , int j2 , vector<vector<int>>& grid , int n , int m , vector<vector<vector<int>>>& dp){
        //base cases
        if( j1 < 0 || j1 >= n || j2 < 0 || j2 >=n ) return -1e9 ;
        if( i == m-1 ){
            if(j1 == j2) return grid[m-1][j1] ;    // both are at same location
            else return grid[m-1][j1] + grid[m-1][j2] ;
        }
        // memoization
        if( dp[i][j1][j2] != -1 ) return dp[i][j1][j2] ;

        // explore all paths 
        int maxi = -1e9 ;
        for( int dj1 = -1 ; dj1 <= 1 ; dj1++ ){
            for( int dj2 = -1 ; dj2 <= 1 ; dj2++ ){

                if( j1 == j2 ) maxi = max( maxi , grid[i][j1] + f(i+1 , j1+dj1 , j2+dj2 , grid , n , m , dp ) ) ;
                else{
                    maxi = max( maxi , grid[i][j1] + grid[i][j2] + f(i+1 , j1+dj1 , j2+dj2 , grid , n , m , dp ) ) ;
                }
                
            }
        }
        return dp[i][j1][j2] =  maxi ;
    }

    int tabulation( vector<vector<int>>& grid , int m , int n ){
        vector<vector<vector<int>>> dp( m , vector<vector<int>> ( n , vector<int> ( n , -1))) ;

        // base case
        for( int j1 = 0 ; j1 < n ; j1++){
            for( int j2 = 0 ; j2 < n ; j2++){
                if(j1 == j2) dp[m-1][j1][j2] =  grid[m-1][j1] ; 
                else dp[m-1][j1][j2] =  grid[m-1][j1] + grid[m-1][j2] ; 
            }
        }

        // express every states in for loops 
        for( int i = m-2 ; i >= 0 ; i--){
            for( int j1 = 0 ; j1 <= n-1 ; j1++){
                for( int j2 = 0 ; j2 <= n-1 ; j2++){

                    int maxi = -1e9 ;
                    for( int dj1 = -1 ; dj1 <= 1 ; dj1++ ){
                        for( int dj2 = -1 ; dj2 <= 1 ; dj2++ ){
                            
                            if( j1+dj1 < 0 || j1+dj1 >= n || j2+dj2 < 0 || j2+dj2 >=n ) continue ;
                            if( j1 == j2 ) maxi = max( maxi , grid[i][j1] + dp[i+1][j1+dj1][j2+dj2] ) ;
                            else{
                                maxi = max( maxi , grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2] ) ;
                            }
                
                        }
                    }
                    dp[i][j1][j2] = maxi ;
                }
            }
        }
        return dp[0][0][n-1] ; // always return the state you strated in recursion with 
    }


public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<vector<int>>> dp( m , vector<vector<int>> ( n , vector<int> ( n , -1))) ;

        // int ans = f( 0 , 0 , n-1 , grid , n , m , dp ) ;
        // return ans ;

        int ans = tabulation(grid , m , n ) ;
        return ans ;

        
    }
};