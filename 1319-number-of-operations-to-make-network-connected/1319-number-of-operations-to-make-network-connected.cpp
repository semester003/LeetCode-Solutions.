class DisjointSet{
public:
    vector<int> rank, parent , size ;
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds( n ) ;
        int extraEdge = 0 ; 

        for( auto edge : connections ){
            int u = edge[0] ;
            int v = edge[1] ;

            if( ds.findUPar(u) == ds.findUPar(v)){
                extraEdge++ ;
            }

            else{
                ds.unionBySize( u , v ) ;
            }
        }

        // counting no of connected components 
        int conC = 0 ;
        for( int i = 0 ; i < n ; i++){
            if( i == ds.parent[i]){
                conC++ ;
            }
        }

        int ans = conC - 1 ;

        if( extraEdge >= ans){
            return ans ;
        }
        else return -1 ;


    }
};





















