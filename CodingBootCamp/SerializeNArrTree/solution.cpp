string serialize(Node *root){
  if(root == NULL) return;
  
  string res = "" + root->val;
  for(int i = 0; i < N && root->child[i]; i++){
    res += serialize(root->child[i]);
  }

  res += ")";
  return res;
}

string deserialize(Node *& root, string s){
  if(s.length() == 0 || s[0] == ')'){
    return 1;
  }

  root = newNode(s[0]);
  int i; 
  for(i = 0; i < N; i++){
    if(deserialize(root->child[i], s.substr(i+1,-1)))
     break; 
  }
  return 0; 
}
