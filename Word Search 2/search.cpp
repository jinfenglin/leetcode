#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode {
	public:
		string letter;
		std::vector<TrieNode*> next;

		// Initialize your data structure here.
		TrieNode() {
			letter = "";
			next = {};
		}

		TrieNode* find(char c) {
			for(int i = 0; i < next.size(); i++)
			{
				if (next[i]->letter[0] == c)
					return next[i];
			}
			return NULL;
		}

};

class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word) {
			TrieNode* node = root;
			for(int i = 0; i < word.length(); i++)
			{
				TrieNode* nextNode = node->find(word[i]);

				if(!nextNode)
				{
					TrieNode* newNode =  new TrieNode();
					newNode->letter = word[i];
					node->next.push_back(newNode);
					nextNode = newNode;
				}

				node = nextNode;
			}

			TrieNode* newNode =  new TrieNode();
			newNode->letter = '\0';
			node->next.push_back(newNode);
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			TrieNode* node = root;
			for(int i = 0; i < word.length(); i++)
			{
				TrieNode* nextNode = node->find(word[i]);
				if(!nextNode)
					return false;
				node = nextNode;
			}

			TrieNode* finalNode = node->find('\0');
			if(finalNode)
				return true;
			else
				return false;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			TrieNode* node = root;
			for(int i = 0; i < prefix.length(); i++)
			{
				TrieNode* nextNode = node->find(prefix[i]);
				if(!nextNode)
					return false;
				node = nextNode;
			}
			return true;
		}

	private:
		TrieNode* root;
};

class Solution {
	public:
		Trie *prefix;
		vector<vector<bool>> visited;
		vector<string> res;
		unordered_set<string> replication;
		Solution(){
			prefix=new Trie;
			
		}
		void DFS(vector<vector<char>>& board,int x,int y,string sol){
			int x_len=board.size();
			int y_len=x_len? board[0].size():0;
			if(x<0 or x>=x_len or y<0 or y>=y_len)
				return ;	
			if(visited[x][y])
				return ;

			sol+=board[x][y];
			
			if(prefix->search(sol) and replication.find(sol)!=replication.end()){
				res.push_back(sol);
				replication.erase(sol);
			}
			if(!prefix->startsWith(sol)) return ;
						
			visited[x][y]=true;
			DFS(board,x+1,y,sol);
			DFS(board,x-1,y,sol);
			DFS(board,x,y+1,sol);
			DFS(board,x,y-1,sol);
			visited[x][y]=false;

		}
		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			
			string sol;
			int x_len,y_len;
			x_len=board.size();
			y_len=x_len? board[0].size():0;
			for(int i=0;i<x_len;i++)
				visited.push_back( vector<bool>(y_len,false));

			for(string word:words){
				prefix->insert(word);
				replication.insert(word);
			}
		

			
			for(int i=0;i<x_len;i++)
				for(int j=0;j<y_len;j++)
					DFS(board,i,j,sol);
			return res;

		}
};

int main(){
	Solution *sol=new Solution;
	vector<vector<char>>  board;
	vector<char> v1={'o','a','a','n'};
	vector<char> v2={'e','t','a','e'};
	vector<char> v3={'i','h','k','r'};
	vector<char> v4={'i','f','l','v'};
	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	vector<vector<char>> b2;
	b2.push_back(vector<char>(2,'a'));
	vector<string>  words={"a"};
	vector<string> res=sol->findWords(b2,words);
	for(string s:res)
		cout<<s<<endl;
}
