class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;

        vector<vector<int>> vis( m , vector<int> ( n , 0 )) ;
        vector<vector<int>> distance = vis ;
        queue<pair<pair<int,int>,int>> q ;

        for(int i=0 ; i < m ; i++){
            for( int j=0 ; j<n ; j++){
                if( mat[i][j] == 0){
                    q.push({ {i,j} ,0 } ) ;
                    vis[i][j] = 1 ;
                }
                else{
                    vis[i][j] = 0 ;
                }
    
            }
        }

        int drow[4] = { -1 , 0 , 1 , 0 } ;
        int dcol[4] = { 0 , 1 , 0 , -1 } ;

        while( !q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int steps = q.front().second ;
            q.pop() ;
            distance[row][col] = steps ; 

            for( int i = 0 ; i < 4 ; i++ ){
                int nrow = row + drow[i] ;
                int ncol = col + dcol[i] ;

                if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                    && !vis[nrow][ncol]  ){
                        vis[nrow][ncol] = 1 ;
                        q.push( { {nrow,ncol} , steps+1}) ;
                    }
            }
        }
        return distance ;


        
    }
};