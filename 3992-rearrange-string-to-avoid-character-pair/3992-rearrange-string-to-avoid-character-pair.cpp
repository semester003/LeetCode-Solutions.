class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size() ;
        int L = 0 ;
        string t = s ;
        
        for( int R = 0 ; R < n ; R++){
            if( t[R] == x ) continue ;
            else{
                swap( t[L] , t[R]) ;
                L++ ;
            }
            
        }
        return t ;
        
    }
};