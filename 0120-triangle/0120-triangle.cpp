class Solution {
private:
    int f( int i , int j , vector<vector<int>>& triangle  , int n , vector<vector<int>>& dp ){
        
        // base case 
        if( i == n-1 ) return triangle[n-1][j] ;
        // memoization
        if( dp[i][j] != INT_MAX ) return dp[i][j] ;

        // all stuffs
        int down = triangle[i][j] + f( i+1 , j , triangle , n , dp) ;
        int diag = triangle[i][j] + f( i+1 , j+1 , triangle , n , dp) ;

        return dp[i][j] = min( down , diag ) ;

    }

    int tabulation(vector<vector<int>>& triangle , int n ){  

        vector<vector<int>> dp( n , vector<int> ( n , INT_MAX)) ;
        // base case 
        for( int j = 0 ; j <= n-1 ; j++ ){
            dp[n-1][j] = triangle[n-1][j] ;
        }

        for( int i = n-2 ; i >= 0 ; i--){
            for( int j = i ; j >= 0 ; j--){

                int down = triangle[i][j] + dp[i+1][j] ;
                int diag = triangle[i][j] + dp[i+1][j+1] ;

                dp[i][j] = min( down , diag ) ;
            }
        }

        return dp[0][0] ;   // always return the the index where you started your recursion from 

    }

    int space_optimisation(vector<vector<int>>& triangle , int n ){  

        vector<int> prev( n , INT_MAX) ;
        // base case 
        for( int j = 0 ; j <= n-1 ; j++ ){
            prev[j] = triangle[n-1][j] ;
        }

        for( int i = n-2 ; i >= 0 ; i--){
            vector<int> temp ( n , 0 ) ;
            for( int j = i ; j >= 0 ; j--){

                int down = triangle[i][j] + prev[j] ;
                int diag = triangle[i][j] + prev[j+1] ;

                temp[j] = min( down , diag ) ;
            }
            prev = temp ;
        }

        return prev[0] ; 

    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        // cant initialize dp with -1 this time cause triangle contain negatives as well ,
        //vector<vector<int>> dp( n , vector<int>  ( n , INT_MAX)) ;   

        //int ans = f( 0 , 0 , triangle , n , dp ) ;
        int ans = space_optimisation( triangle , n ) ;
        return ans ;
    }
};