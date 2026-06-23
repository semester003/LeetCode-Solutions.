class Solution {
private:
    int drow[4] = { -1 , 0 , 1 , 0 } ; 
    int dcol[4] = { 0 , 1 , 0 , -1 } ;

    void dfs( int row , int col , vector<vector<int>>& vis , int m , int n ,vector<vector<int>>& grid ){
        
        vis[row][col] = 1 ;

        // left, up, right , down 
        for(int i = 0 ; i < 4 ; i++) {
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;

            if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ){

                    dfs( nrow , ncol , vis , m , n , grid) ;
                }
            
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> vis(m , vector<int> (n , 0)) ;

        for(int j = 0 ; j < n ; j++ ){
            // first row
            if( !vis[0][j] && grid[0][j] == 1 ){
                dfs( 0 , j , vis , m , n , grid) ;
            }
            // last row
            if( !vis[m-1][j] && grid[m-1][j] == 1 ){
                dfs( m-1 , j , vis , m , n , grid ) ;
            }

        }
        
        for(int i = 0 ; i < m ; i++ ){  
            //first col 
            if( !vis[i][0] && grid[i][0] == 1 ){
                dfs( i , 0 , vis , m , n , grid) ;
            }
            // last col 
            if( !vis[i][n-1] &&  grid[i][n-1] == 1 ){
                dfs( i , n-1 , vis , m , n , grid ) ;
            }

        }

        int cnt = 0 ;
        for(int i = 1 ; i < m-1 ; i++){
            for(int j = 1 ; j < n-1 ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++ ;
                }
            }
        }
        return cnt ;
        
    }
};