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
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> dp( m , vector<int> ( n , -1)) ;

        int ans = f( m-1 , n-1 , grid , dp ) ;
        return ans ;
        
    }
};