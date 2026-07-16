class Solution {
private:
    int f(int row , int col , int m , int n  , vector<vector<int>>& dp ){
        // base case
        if(row == 0 && col == 0){
            return  1 ;
        }
        if( row <0  || col < 0) return 0 ;

        // memoization
        if( dp[row][col] != -1) return dp[row][col] ;
            
        int left = f( row , col-1 , m , n , dp );
        
        int up =  f( row-1 , col , m , n , dp );
        

        return dp[row][col] = left + up  ; 


    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m , vector<int> ( n , -1 )) ;
        int ans  = f( m-1 , n-1 , m , n , dp  ) ;
        return ans ;
    }
};