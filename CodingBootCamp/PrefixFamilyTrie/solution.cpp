struct TrieNode{
  string cur;
  vector<TrieNode *> children;
  TrieNode(string val):cur(val){}
};

TrieNode* buildPrefixFamilyTrie(vector<string> words){
  sort(words.begin(), words.end());
  words.insert(words.begin(), "a"); 
  return buildUtil(words); 
}

TrieNode* buildUtil(vector<stirng>& words){
  TrieNode *root = new TrieNode(words[0]);
  if(words.size() == 1){
    return root;
  }

  vector<string> buf;
  string cur = words[1];
  buf.push_back(cur); 
  for(int i = 2; i < words.size(); i++){
    if(words[i].find(cur) == string::npos){
      root->children.push_back(buildUtil(buf));
      buf.clear();
      cur = words[i];
      buf.push_back(cur); 
    }else{
      buf.push_back(words[i]);    
    }
  }

  if(buf.size() != 0){
      root->children.push_back(buildUtil(buf));
  }
  return root;
}
