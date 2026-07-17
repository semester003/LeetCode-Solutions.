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
        int up = matrix[i][j] + f( i-1 , j , matrix , n , dp) ; 
        int left = matrix[i][j] + f( i-1 , j-1 , matrix , n , dp) ;
        int right = matrix[i][j] + f( i-1 , j+1 , matrix , n , dp) ;

        return dp[i][j] =  min( up , min(left , right) ) ;
    }
    int tabulation( int n , vector<vector<int>>& matrix ){
        vector<vector<int>> dp( n , vector<int>(n , 1e9 )) ;
        // base cases 
        for(int j = 0 ; j <= n-1 ; j++){
            dp[0][j] = matrix[0][j] ;
        }

        for( int i = 1 ; i <= n-1 ; i++){
            for( int j = 0 ; j <= n-1 ; j++){
                int up = matrix[i][j] + dp[i-1][j] ;
                int left = 1e9 ;
                if( j > 0 ) left = matrix[i][j] + dp[i-1][j-1] ;
                int right = 1e9 ;
                if( j < n-1 ) right = matrix[i][j] + dp[i-1][j+1] ;

                dp[i][j] =  min( up , min(left , right) ) ;
            }
        }
        
        int ans = INT_MAX ;
        for( int j = 0 ; j <= n-1 ; j++){
            int path_sum = dp[n-1][j] ;
            ans = min( ans , path_sum ) ;
        }
        return ans ; 

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        vector<vector<int>> dp( n , vector<int>(n , 1e9 )) ;

        int ans = INT_MAX ;
        // will be calling the recurstion from each element of the last row 
        // for( int j = 0 ; j <= n-1 ; j++){
        //     int path_sum = f( n-1 , j , matrix  , n , dp ) ;
        //     ans = min( ans , path_sum ) ;
        // }

        

        return tabulation( n , matrix ) ;
        
    }
};