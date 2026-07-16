class Solution {
private:
    int f(int row , int col , vector<vector<int>>& obstacleGrid ,  vector<vector<int>>& dp ){
        // base case
        if(row == 0 && col == 0){
            if( obstacleGrid[row][col] == 1 ) return 0 ;
            return  1 ;
        }
        if( row <0  || col < 0) return 0 ;
        // if there is the any obstacle then can't include this path
        if( obstacleGrid[row][col] == 1 ) return 0 ;

        // memoization
        if( dp[row][col] != -1) return dp[row][col] ;
            
        int left = f( row , col-1 , obstacleGrid , dp );
        
        int up =  f( row-1 , col , obstacleGrid , dp );
        

        return dp[row][col] = left + up  ; 


    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        vector<vector<int>> dp( m , vector<int> (n , -1)) ;

        int ans = f( m-1 , n-1 , obstacleGrid , dp ) ;

        return ans ;
        
    }
};













