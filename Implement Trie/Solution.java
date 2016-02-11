class TrieNode {
	// Initialize your data structure here.
	public TrieNode[] links;
	public boolean endFlag;
	public TrieNode() {
		links=new TrieNode[26];
		endFlag=false;
	}
}

public class Trie {
	private TrieNode root;

	public Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	public void insert(String word) {
		insert(word,0,root);
	}
	private void insert(String word,int pos,TrieNode cur){
		if(pos==word.length()){
		    cur.endFlag=true;
			return ;
		}
		int c=word.charAt(pos)-'a';
		if(cur.links[c]==null)
			cur.links[c]=new TrieNode();
		insert(word,pos+1,cur.links[c]);
	}

	// Returns if the word is in the trie.
	public boolean search(String word) {
		return search(word,0,root);
	}
	public boolean search(String word,int pos,TrieNode cur){
		if(pos==word.length())
			return cur.endFlag;
		int c=word.charAt(pos)-'a';
		if(cur.links[c]==null)
			return false;
		else
			return search(word,pos+1,cur.links[c]);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	public boolean startsWith(String prefix) {
		return startsWith(prefix,0,root);
	}
	public boolean startsWith(String prefix,int pos,TrieNode cur){
		if(pos==prefix.length())
			return true;
		int c=prefix.charAt(pos)-'a';
		if(cur.links[c]==null)
			return false;
		else
			return startsWith(prefix,pos+1,cur.links[c]);
	}
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");


