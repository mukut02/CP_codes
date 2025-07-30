// Q link : 
// Implement Trie : (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* child[26];
    };

    trieNode* getNode(){
        trieNode* newNode= new trieNode();
        newNode->isEndOfWord = false;

        for(int i=0;i<26;++i){
            newNode->child[i]=NULL;
        }

        return newNode;
    }

    trieNode* root;
    // constructor
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;

        for(auto &ch : word){
            int indx=ch-'a';
            if(crawl->child[indx]==NULL){
                crawl->child[indx]=getNode();
            }
            crawl=crawl->child[indx];
        }
        crawl->isEndOfWord=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;

        for(auto &ch : word){
            int indx=ch-'a';
            if(crawl->child[indx]==NULL){
                return false;
            }
            crawl=crawl->child[indx];
        }
        return (crawl!=NULL && crawl->isEndOfWord)==true;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl= root;

        int ptr=0;
        for(auto &ch : prefix){
            int indx=ch-'a';
            if(crawl->child[indx]==NULL){
                return false;
            }
            ptr++;
            crawl=crawl->child[indx];
        }
        return ptr==prefix.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
