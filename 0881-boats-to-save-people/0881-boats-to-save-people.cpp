class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin() , people.end()) ;

        int n = people.size() ;

        int L = 0 ;
        int R = n-1 ;

        int k = 0 ;  // no of the boats 

        while( L <= R){

            if( people[L] + people[R] > limit ){
                k++ ;
                R-- ;
            }
            else{
                k++ ;
                R-- ;
                L++ ;
            }
        }

        return k ;
        
    }
};