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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        // cant initialize dp with -1 this time cause triangle contain negatives as well ,
        vector<vector<int>> dp( n , vector<int>  ( n , INT_MAX)) ;   

        int ans = f( 0 , 0 , triangle , n , dp ) ;
        return ans ;
    }
};