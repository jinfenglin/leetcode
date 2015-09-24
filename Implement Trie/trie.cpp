#include <iostream>
using namespace std;

class TrieNode {
	public:
		char content;
		TrieNode *nexts[27];

		// Initialize your data structure here.
		TrieNode() {
			content=' ';
			for(int i=0;i<27;i++)
				nexts[i]=NULL;
		}
};
class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word) {
			cur=root;
			for(char c:word){
				int loc=c-'a';
				if(cur->nexts[loc]==NULL){
					cur->nexts[loc]=new TrieNode();
					cur=cur->nexts[loc];
					cur->content=c;
				}else
					cur=cur->nexts[loc];
			}
			if(cur->nexts[26]==NULL)
				cur->nexts[26]=new TrieNode();
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			cur=root;
			for(int i=0;i<word.size();i++){
				int loc= word[i]-'a';
				if(cur->nexts[loc]==NULL)
					return false;
				cur=cur->nexts[loc];
			}
			if(cur->nexts[26]==NULL)
				return false;
			return true;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			cur=root;
			for(int i=0;i<prefix.size();i++){
				int loc= prefix[i]-'a';
				if(cur->nexts[loc]==NULL)
					return false;
				cur=cur->nexts[loc];
			}
			if(cur->nexts[26]==NULL)
				return true;
			return false;
		}

	private:
		TrieNode* cur;
		TrieNode* root;
};
int main(){
	Trie *t=new Trie();
	t->insert("abc");
	cout<<t->search("abc")<<endl;
	cout<<t->search("ab")<<endl;
	cout<<t->startsWith("ab")<<endl;
}
