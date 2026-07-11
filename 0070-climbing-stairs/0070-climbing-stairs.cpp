class Solution {
private:
    int f(int ind , vector<int>& dp){
        if(ind == 0) return 1 ;
        if(ind == 1) return 1 ;  // this for the sake of edge case , ie: i = 1 ,  f(i-2) = f(-1) -> runtime error 

        if(dp[ind] != -1) return dp[ind] ; // memoization

        // two ways , one step at a time 
        int left = f(ind - 1 , dp) ;
        dp[ind - 1] = left ;
        // two steps at a time 
        int right = f(ind - 2 , dp) ;
        dp[ind - 2] = right ;

        return left+right ;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1) ;
        int ans  = f(n , dp) ;
        return ans ;
        

        //tabulation 
        // dp[0] = 1  , dp[1] = 1 ;
        // for( int i = 2 ; i <= n ; i++){
        //     dp[i] = dp[i-1] + dp[i-2] ;
        // }

        // return dp[n] ;
    }
};