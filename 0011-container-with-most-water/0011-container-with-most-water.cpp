class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size() ;
        int L = 0 ; 
        int R = n-1 ;
        int ans = 0 ;

        while ( L < R ){
            
            int area = min( height[L] , height[R] ) * (R-L) ;
            ans = max( ans , area ) ;

            if( height[L] < height[R] ) L++ ;
            else R-- ;
        }
        return ans ;      
    }
};