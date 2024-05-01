void preOrder(TreeNode *root, vector <int> &pre){
    if(root == NULL){
        return;
    }
    pre.push_back(root->data);
    preOrder(root->left,pre);
    preOrder(root->right,pre);
}
void inOrder(TreeNode *root, vector <int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}
void postOrder(TreeNode *root, vector <int> &post){
    if(root == NULL){
        return;
    }
    postOrder(root->left,post);
    postOrder(root->right,post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
   vector <int> pre;
   vector <int> in;
   vector <int> post;
   preOrder(root,pre);
   inOrder(root,in);
   postOrder(root,post);
   vector <vector<int>> ans;
   ans.push_back(in);
   ans.push_back(pre);
   ans.push_back(post);
   return ans;
}
