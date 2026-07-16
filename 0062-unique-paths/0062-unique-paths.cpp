class Solution {
private:
    int f(int row , int col , vector<vector<int>>& dp ){
        // base case
        if(row == 0 && col == 0){
            return  1 ;
        }
        if( row <0  || col < 0) return 0 ;

        // memoization
        if( dp[row][col] != -1) return dp[row][col] ;
            
        int left = f( row , col-1 , dp );
        
        int up =  f( row-1 , col , dp );
        

        return dp[row][col] = left + up  ; 


    }

    int tabulation(int m , int n ){
        // declare dp 
        vector<vector<int>> dp( m , vector<int> ( n , -1 )) ;
        // base case 
        dp[0][0] = 1 ;

        // express all states in for loop
        for( int row = 0 ; row <= m-1 ; row++){
            for(int col = 0 ; col <= n-1 ; col++){
                if(row == 0 && col == 0) dp[row][col] = 1 ;
                else{
                    int up = 0 ;
                    int left = 0 ;
                    if( row > 0 ) up = dp[row-1][col] ;
                    if( col > 0 ) left = dp[row][col-1] ;

                    dp[row][col] = up+left ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }

    int space_optimisation(int m , int n ){
        // declare dp or prev row 
        vector<int> dp(n , 0) ; // dp = [0,0,0,0,0,0]

        // express all states in for loop
        for( int row = 0 ; row <= m-1 ; row++){
            vector<int> temp(n , 0) ;
            for(int col = 0 ; col <= n-1 ; col++){
                if(row == 0 && col == 0) temp[col] = 1 ;  // we are filling the current row 
                else{
                    int up = 0 ;
                    int left = 0 ;
                    if( row > 0 ) up = dp[col] ; // value of 'col' from previous row
                    if( col > 0 ) left = temp[col-1] ;  // value of "col-1" from current row

                    temp[col] = up + left ;
                }
            }
            dp = temp ;  // after filling the current row , make it the previous row and go to next row
        }
        return dp[n-1] ;
    }

public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp( m , vector<int> ( n , -1 )) ;
        int ans  = space_optimisation( m, n ) ;
        return ans ;

    }
};
























