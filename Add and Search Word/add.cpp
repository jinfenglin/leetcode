#include <iostream>
#include <vector>
using namespace std;
class WordDictionary {
	public:
		class TreeNode{
			public:
				char content;
				TreeNode* nexts[27];
				TreeNode(){
					content=' ';
					for(int i=0;i<27;i++){
						nexts[i]=NULL;
					}
				}
		};
		TreeNode *head;
		WordDictionary(){
			head=new TreeNode();

		}
		// Adds a word into the data structure.
		void addWord(string word) {
			TreeNode *cur=head;
			for(char c:word){
				int loc=c-'a';
				if(cur->nexts[loc]==NULL){
					cur->nexts[loc]=new TreeNode();
					cur->nexts[loc]->content=c;
				}
				cur=cur->nexts[loc];
			}
			cur->nexts[26]=new TreeNode();

		}

		// Returns if the word is in the data structure. A word could
		// contain the dot character '.' to represent any one letter.
		bool DFS(string &word,int start,TreeNode *cur){
			if(start==word.size() and cur->nexts[26]!=NULL)
				return true;
			for(int i=start;i<word.size();i++){
				if(word[i]=='.'){
					for(int j=0;j<26;j++){
						if(cur->nexts[j]!=NULL){
							bool flag=DFS(word,i+1,cur->nexts[j]);
							if(flag)
								return true;
						}
					}
					return false;

				}else{
					int loc=word[i]-'a';
					if(cur->nexts[loc]==NULL){
						return false;
					}else if(cur->nexts[loc]->content==word[i])
						cur=cur->nexts[loc];
					else
						return false;
				}
			}
			if(cur->nexts[26]!=NULL)
				return true;
			return false;

		}
		bool search(string word) {
			return DFS(word,0,head);

		}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("word");
	wordDictionary.addWord("a");
	cout<<wordDictionary.search("pattern")<<endl;
	cout<<wordDictionary.search(".")<<endl;
}
