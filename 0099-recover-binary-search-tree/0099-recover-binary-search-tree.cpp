/**
 * Definition https://leetcode.com/problems/recover-binary-search-tree/$0for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first  ;
    TreeNode* middle  ;
    TreeNode* last   ;
    TreeNode* prev  ;
private:
    void inorder( TreeNode* root){
        if( root == NULL ) return ;

        inorder( root -> left) ;

        if( prev != NULL && (root -> val < prev -> val) ){
            //it means this is the first violation
            if( first == NULL ){
                first = prev ;
                middle = root ;
            }
            // it means this is the second violation
            else{
                last = root ;
            }
        }
        prev = root ;
        inorder( root -> right) ;

    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL ;
        prev = new TreeNode(INT_MIN) ;
        inorder(root) ;
        // two violation , swapped nodes are not adjacent 
        if(first != NULL && last != NULL ) swap( first -> val  , last -> val ) ;
        // only one violation , adjacent nodes are swappwd 
        else{
            swap( first -> val , middle -> val ) ;
        }
    }
};