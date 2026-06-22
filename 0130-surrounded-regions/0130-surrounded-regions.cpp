class Solution {
private:
    int drow[4] = { -1 , 0 , 1 , 0 } ; 
    int dcol[4] = { 0 , 1 , 0 , -1 } ;

    void dfs( int row , int col , vector<vector<int>>& vis , int m , int n ,vector<vector<char>>& board ){
        
        vis[row][col] = 1 ;

        // left, up, right , down 
        for(int i = 0 ; i < 4 ; i++) {
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;

            if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && !vis[nrow][ncol] && board[nrow][ncol] == 'O' ){

                    dfs( nrow , ncol , vis , m , n , board) ;
                }
            
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size() ;
        int n = board[0].size() ;

        vector<vector<int>> vis(m , vector<int> (n , 0)) ;

        for(int j = 0 ; j < n ; j++ ){
            // first row
            if( !vis[0][j] && board[0][j] == 'O' ){
                dfs( 0 , j , vis , m , n , board) ;
            }
            // last row
            if( !vis[m-1][j] && board[m-1][j] == 'O' ){
                dfs( m-1 , j , vis , m , n , board ) ;
            }

        }
        
        for(int i = 0 ; i < m ; i++ ){  
            //first col 
            if( !vis[i][0] && board[i][0] == 'O' ){
                dfs( i , 0 , vis , m , n , board) ;
            }
            // last col 
            if( !vis[i][n-1] &&  board[i][n-1] == 'O' ){
                dfs( i , n-1 , vis , m , n , board ) ;
            }

        }
        for(int i = 1 ; i < m-1 ; i++){
            for(int j = 1 ; j < n-1 ; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X' ;
                }
            }
        }

        


        
    }
};