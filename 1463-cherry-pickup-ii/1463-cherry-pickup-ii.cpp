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
        int maxi = 0 ;
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

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp( m , vector<vector<int>> ( n , vector<int> ( n , -1))) ;

        int ans = f( 0 , 0 , n-1 , grid , n , m , dp ) ;
        return ans ;

        
    }
};