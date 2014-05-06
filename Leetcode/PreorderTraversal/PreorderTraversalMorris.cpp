/*
	O(n) time
	O(1) space
*/
class solution{
	public:
		vector<int> preorderMorris(TreeNode *root){
			vector<int> result;
			Node *curr;
			curr = root;

			while(curr != NULL){
				if(curr->left == NULL){
					result.push_back(curr->val);
					curr = curr->right;
				}else{
					TreeNode *node = curr->left;
					while(node->right != NULL && node->right != curr){
						node = node->right;
					}
					if(node->right == NULL){
						result.push_back(curr->val);
						node->right = curr;
					}else{
						node->right = NULL;
						curr = curr->right;
					}	
				}
			}
			return result;	
		}
};
