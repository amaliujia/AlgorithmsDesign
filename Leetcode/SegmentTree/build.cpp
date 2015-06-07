/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(end < start){
            return NULL;
        }
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        recursiveBuild(root);
        return root;
    }
    
private:
    void recursiveBuild(SegmentTreeNode *parent){
        if (parent->start == parent->end) {
            return;
        }
     		 
        SegmentTreeNode *left = new SegmentTreeNode(parent->start, 
                                                    (parent->start + parent->end) / 2);
        SegmentTreeNode *right = new SegmentTreeNode((parent->start + parent->end) / 2 + 1,
                                                        parent->end);
                                                        
        parent->left = left;
        parent->right = right;
        recursiveBuild(parent->left);
        recursiveBuild(parent->right);
    }
};
