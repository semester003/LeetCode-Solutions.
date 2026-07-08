class DisjointSet{
    vector<int> rank, parent , size ;
public:
    DisjointSet( int n){
        rank.resize( n+1 , 0) ;
        size.resize( n+1 , 0) ;
        parent.resize( n+1) ;
        for( int i = 0 ; i<=n ; i++){
            parent[i] = i ;
        }
         
    }

    int findUPar( int node ) {
        if( parent[node] == node)
            return node ;

            // this is where path compression comes in 
            return parent[node] = findUPar( parent[node] ) ;
            
    }

    void unionByRank( int u ,int v){
        int ult_u = findUPar(u) ;
        int ult_v = findUPar(v) ;
        if( ult_u == ult_v) return ;  // that means both belong to same componet
        if( rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u ;
        }
        else if( rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v ;
        }
        // if both have same rank , attach anyone to anyone 
        else{
            parent [ult_v] = ult_u ;
            rank[ult_u]++ ;
        }

    }

    void unionBySize( int u ,int v){
        int ult_u = findUPar(u) ;
        int ult_v = findUPar(v) ;
        if( ult_u == ult_v) return ;  // that means both belong to same componet
        if( size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u ;
            size[ult_u] += size[ult_v] ;
        }

        else if( size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v ;
            size[ult_v] += size[ult_u] ;
        }
        // if both have same rank , attach anyone to anyone 
        else{
            parent [ult_v] = ult_u ;
            size[ult_u] += size[ult_v] ;
        }

    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;
        int maxRow = 0 ;
        int maxCol = 0 ;

        for ( auto it : stones){
            maxRow = max(maxRow , it[0]) ;
            maxCol = max(maxCol , it[1]) ;
            
        }
        //see notebook    4    +    3  + ?               but it should be declare for 9 
        DisjointSet ds( maxRow + maxCol + 2) ; 

        // to keep track of which nodeRow or nodeCol carry stone 
        unordered_map<int ,int> stoneNodes ;    // store unique 

        for( auto it  : stones){
            int nodeRow = it[0] ;
            int nodeCol = it[1] + maxRow + 1 ;

            ds.unionBySize( nodeRow ,nodeCol ) ;

            stoneNodes[nodeRow] = 1 ;
            stoneNodes[nodeCol] = 1 ;
        }

        int connectedComponents  = 0 ;
        for( auto it : stoneNodes){
            if( ds.findUPar(it.first) == it.first ){
                connectedComponents++ ;
            }
        }

        return n - connectedComponents ;


        
        
    }
};

































