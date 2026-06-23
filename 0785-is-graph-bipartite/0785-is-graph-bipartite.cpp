class Solution {
private:
    bool check(int i , vector<vector<int>>& graph , int n , vector<int>& color ){

        color[i] = 0 ;   // color very first node with 0 

        queue<int> q ;
        q.push(i) ;

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;

            for( auto adjacentNode : graph[node] ){
                // adjacentNode is not colored
                // then color it and push into q
                if(color[adjacentNode] == -1){   
                    color[adjacentNode] = 1-color[node] ;
                    q.push(adjacentNode) ;
                }
                // adjacentNode is colored
                // check if it's color 
                else{
                    if( color[adjacentNode] == color[node]) return false ;
                }
            }


        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size() ;
        vector<int> color( n , -1) ;   // non colored 

        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if( check( i , graph , n , color ) == false )    return false ;
            }
        }
        return true ;
        
    }
};