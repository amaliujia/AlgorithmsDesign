class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        memset(this->nodes, 0, sizeof(this->nodes));
        count = 0;
        ifExit = false;
    }
    
    TrieNode* nodes[26];
    int count;
    bool ifExit;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
	// Inserts a word into the trie.
    void insert(string s) {
        TrieNode *n = this->root;
        for(int i = 0; i < s.length(); i++){
            if(!n->nodes[s[i] - 'a']){
                n->nodes[s[i] - 'a'] = new TrieNode();
            }
            n = n->nodes[s[i] - 'a'];
            n->count++;
        }
        n->ifExit = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *n = this->root;
        for(int i = 0; i < key.length(); i++){
            if(!n->nodes[key[i] - 'a']){
                return false;
            }
            n = n->nodes[key[i] - 'a'];
        }
        return n->ifExit;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *n = this->root;
        for(int i = 0; i < prefix.length(); i++){
            if(!n->nodes[prefix[i] - 'a']){
                return false;
            }
            n = n->nodes[prefix[i] - 'a'];
        }
        return n->count > 0;
    }

private:
    TrieNode* root;
};
