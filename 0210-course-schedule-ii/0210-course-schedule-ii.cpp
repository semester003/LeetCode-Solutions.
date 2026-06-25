class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> ans ;
        //if(prerequisites.size() == 0 ) return {0} ;
      
        vector<vector<int>> adjLs(numCourses) ;
        vector<int> indegree(numCourses , 0) ;

        for( const auto &edge : prerequisites ){
            int course = edge[0] ;
            int prereq = edge[1] ;

            adjLs[prereq].push_back(course) ;
            indegree[course]++ ;   // course indegree will be riased Kahn's algorithm always starts from nodes having indegree = 0.
        }

        queue<int> q ;
        
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i) ;
        }

        while( !q.empty() ){
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;

            for( auto neighbour : adjLs[node]){
                indegree[neighbour]-- ;
                if( indegree[neighbour] == 0 ) q.push(neighbour) ;
            }
        }

        if(ans.size() == numCourses ) return ans ;
        else return {} ;

    }

};