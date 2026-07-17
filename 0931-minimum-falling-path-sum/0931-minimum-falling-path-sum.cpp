class Solution {
private:
    int f( int i , int j , vector<vector<int>>& matrix , int n , vector<vector<int>>& dp ){

        // base cases 
        // incase a coordinate go out of bound
        if( j < 0 || j > n-1 ) return 1e9 ;    // why this base case is before the second one ?
        // reach the last row 
        if( i == 0 ) return matrix[0][j] ;

        // memoization
        if( dp[i][j] != 1e9 ) return dp[i][j] ;

        // all stuffs
        int down = matrix[i][j] + f( i-1 , j , matrix , n , dp) ; 
        int left = matrix[i][j] + f( i-1 , j-1 , matrix , n , dp) ;
        int right = matrix[i][j] + f( i-1 , j+1 , matrix , n , dp) ;

        return dp[i][j] =  min( down , min(left , right) ) ;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        vector<vector<int>> dp( n , vector<int>(n , 1e9 )) ;

        int ans = INT_MAX ;
        // will be calling the recurstion from each element of the last row 
        for( int j = 0 ; j <= n-1 ; j++){
            int path_sum = f( n-1 , j , matrix  , n , dp ) ;
            ans = min( ans , path_sum ) ;
        }

        return ans ;
        
    }
};