class Solution {
private:
    int f(int ind , vector<int>& dp){
        if(ind == 0) return 1 ;
        if(ind == 1) return 1 ;
        if(dp[ind] != -1) return dp[ind] ;

        int left = f(ind - 1 , dp) ;
        dp[ind - 1] = left ;
        int right = f(ind - 2 , dp) ;
        dp[ind - 2] = right ;

        return left+right ;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1) ;
        int ans  = f(n , dp) ;
        return ans ;
        
    }
};