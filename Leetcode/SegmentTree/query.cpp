/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
  public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
      if(start == root->start && end == root->end){
        return root->max;  
      }

      int mid = (root->start + root->end) / 2;
      int leftMost = INT_MIN, rightMost = INT_MIN;
      //left segment
      if(start <= mid){
        if(mid < end){
          leftMost = query(root->left, start, mid);
        }else{
          leftMost = query(root->left, start, end);
        }
      }
      //right segment
      if(mid < end){
        if(start <= mid){
          rightMost = query(root->right, mid + 1, end);
        }else{
          rightMost = query(root->right, start, end);
        }
      }
      return max(leftMost, rightMost);
    }

};
