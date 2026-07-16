class Solution {
private:
    int f( int row , int col , vector<vector<int>>& grid , vector<vector<int>>& dp ){

        if( row == 0 && col == 0 ){
            return grid[0][0] ;
        }
        // check if the cordinates are valid or not
        if( row < 0 || col < 0 ){ 
            return INT_MAX ;
        }
        // memoization
        if( dp[row][col] != -1)  return dp[row][col] ;

        long long up   = grid[row][col] + 1LL * f( row-1 , col , grid , dp ) ;
        long long left = grid[row][col] + 1LL * f( row , col-1 , grid , dp ) ;

        return dp[row][col] = min( up , left ) ;        
    }

    int tabulation( int m , int n , vector<vector<int>>& grid ){
        vector<vector<int>> dp( m , vector<int> ( n , 0)) ;
        // base case or first cell initialization
        dp[0][0] = grid[0][0] ;

        for( int row = 0 ; row <= m-1 ; row++){
            for( int col = 0 ; col <= n-1 ; col++){
                if( row == 0 &&  col == 0 ) continue ;
                else{
                    int up = INT_MAX ;
                    int left = INT_MAX ;
                    if( row > 0 ) up = grid[row][col] + 1LL * dp[row-1][col] ;
                    if( col > 0 ) left = grid[row][col] + 1LL * dp[row][col-1] ;

                    dp[row][col] = min( up , left ) ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        //vector<vector<int>> dp( m , vector<int> ( n , -1)) ;

        int ans = tabulation( m, n, grid ) ;
        return ans ;
        
    }
};