class Solution {
private:
    int drow[4] = { -1 , 0 , 1 , 0 } ;
    int dcol[4] = { 0 , 1 , 0 , -1 } ;

    void dfs(int sr , int sc , vector<vector<int>>& image , int iniColor , int color , int m, int n  ){

        image[sr][sc] = color ;

        for( int i = 0 ; i < 4 ; i++ ){    // looping forue times cause need to seach for four direction
            int nrow = sr + drow[i] ;      // new row
            int ncol = sc + dcol[i] ;      // new col

            if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && image[nrow][ncol] == iniColor ){

                    dfs( nrow , ncol , image , iniColor , color , m , n ) ;
                }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // row and coloum 
        int m = image.size() ;
        int n = image[0].size() ;
        int iniColor = image[sr][sc] ;  // initial color

        if( iniColor == color ) return image ;

        dfs( sr , sc , image , iniColor , color , m , n ) ;
    
        return image ;
        
    } 
};