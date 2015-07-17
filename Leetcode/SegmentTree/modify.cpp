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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
      subModify(root, index, value);
    }
  private:
    int subModify(SegmentTreeNode *root, int index, int value){
      if(root == NULL){
        return INT_MIN;
      }

      if(root->start == index && root->end == index){
        root->max = value;
        return value;
      }   

      if(root->start == root->end){
        return root->max;
      }

      int l = subModify(root->left, index, value);
      int r = subModify(root->right, index, value);

      root->max = max(l, r);
      return root->max;
    }
};

