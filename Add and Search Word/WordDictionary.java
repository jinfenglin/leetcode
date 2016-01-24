import java.util.*;
class MyNode{
	//public char val;
	public MyNode[] link;
	public MyNode( ){
		link=new MyNode[27];
	}
}
public class WordDictionary {
	private MyNode head;
	public WordDictionary(){
		head= new MyNode();
	}
	// Adds a word into the data structure.
	public void addWord(String word) {
		MyNode cur=head;
		for(int i=0;i<word.length();i++){
			int index=word.charAt(i)-'a';
			System.out.println(index);
			if(cur.link[index]==null)
				cur.link[index]= new MyNode();
			cur=cur.link[index];
		}
		cur.link[26]= new MyNode();

	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	public boolean search(String word) {
		return DFS(word,0,head);
	}
	private boolean DFS(String word,int i,MyNode head){
		if(i==word.length()){
			if(head.link[26]!=null)
				return true;
			else
				return false;
		}
		for(;i<word.length();i++){
			int index=word.charAt(i)-'a';
			if(word.charAt(i)=='.'){
				for(int j=0;j<26;j++){
					if(head.link[j]==null)
						continue;
					if(DFS(word,i+1,head.link[j]))
						return true;
				}
				return false;
			}else{
				if(head.link[index]==null)
					return false;
				return DFS(word,i+1,head.link[index]);
			}	
		}
		return false;
	}

	public static void main(String[] args){
		WordDictionary sol=new WordDictionary();	
		sol.addWord("a");
		//sol.addWord("dad");
		//sol.addWord("mad");
		System.out.println(sol.search(""));
		//System.out.println(sol.search("d.d"));
		//System.out.println(sol.search("made"));
	}
}
