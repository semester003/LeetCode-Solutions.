class Solution {
private:
    int f( int i , int j , vector<vector<int>>& matrix , int n , vector<vector<int>>& dp ){

        // base cases 
        // incase a coordinate go out of bound
        if( j < 0 || j > n-1 ) return 1e9 ;
        if( i == n-1 ) return matrix[n-1][j] ;

        // memoization
        if( dp[i][j] != 1e9 ) return dp[i][j] ;

        // all stuffs
        int down = matrix[i][j] + f( i+1 , j , matrix , n , dp) ;
        // left and right can go out of bound , runtime error    
        int left = matrix[i][j] + f( i+1 , j-1 , matrix , n , dp) ;
        int right = matrix[i][j] + f( i+1 , j+1 , matrix , n , dp) ;

        return dp[i][j] =  min( down , min(left , right) ) ;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        vector<vector<int>> dp( n , vector<int>(n , 1e9 )) ;
        int ans = INT_MAX ;
        for( int j = 0 ; j <= n-1 ; j++){
            int path_sum = f( 0 , j , matrix  , n , dp ) ;
            ans = min( ans , path_sum ) ;
        }

        return ans ;
        
    }
};