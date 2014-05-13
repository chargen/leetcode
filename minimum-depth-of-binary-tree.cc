class Solution {
public:
  static const int INF = 0x3f3f3f3f;
  int minDepthD(TreeNode *node){
    int depthL = INF, depthR = INF;
    if(node->left == NULL && node->right == NULL)
      return 1;
    if(node->left !=NULL )
      depthL = minDepthD(node->left);
    if(node->right !=NULL )
      depthR = minDepthD(node->right);
    return min(depthL, depthR) + 1;
  }
    int minDepth(TreeNode *root) {
      return (root == NULL) ? 0 : minDepthD(root);
    }
};