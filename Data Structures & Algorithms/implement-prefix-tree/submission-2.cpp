class PrefixTree {
private:
    struct TrieChar{
        char val;
        unordered_map<char,TrieChar*> next;
        bool isEndOfWord = false;
    };
    TrieChar* root;
public:
    PrefixTree() {
        root = new TrieChar();
    }
    
    void insert(string word) {
        TrieChar *trav = root;
        for(auto& c:word){
            if (trav->next.count(c) == 0) {
                TrieChar* n = new TrieChar();
                n->val = c;
                trav->next[c] = n;
            }
            trav = trav->next[c];
        }
        trav->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieChar *trav= root;
        for(char c:word){
            if(!trav) return false;
            if(trav->next.count(c)==0){
                return false;
            }
            trav=trav->next[c];
        }
        return trav->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieChar *trav= root;
        for(char c:prefix){
            if(!trav) return false;
            if(trav->next.count(c)==0){
                return false;
            }
            trav=trav->next[c];
        }
        return true;
    }
};
