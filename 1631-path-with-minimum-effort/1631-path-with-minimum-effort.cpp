class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ;
        int m = heights[0].size() ;
        // Min-Heap
        priority_queue<
            pair<int,pair<int , int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // Distance array
        vector<vector<int>> dist(n , vector<int> ( m , 1e9)) ;
        dist[0][0] = 0;  // mark source as 0 
        //{ diff { row ,col }}
        pq.push({0, { 0 , 0 }});

        int drow[4] = { -1 , 0 , 1 , 0 } ;
        int dcol[4] = { 0 , 1 , 0 , -1 } ;

        while(!pq.empty()) {
            auto it = pq.top() ;
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            // check for destination when taking it out of pq not while inserting it 
            if( row == n-1 && col == m-1) return diff ;

            for( int i = 0 ; i < 4 ; i++){
                int nrow = row + drow[i] ;
                int ncol = col + dcol[i] ;

                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ){
                    // neweffort = max(current node - neibhour node , previous max diff we had on this path )
                    int newEffort = max( abs(heights[row][col] - heights[nrow][ncol]) , diff ) ;
                    if( newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort ;
                        pq.push({ newEffort , { nrow ,ncol} }) ;
                    }
                }
            }
  
        }

        return -1 ;

        
    }
};