#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
	unordered_map<string,vector<string> > Adjacent;
	bool is_candidate(string w1,string w2){
		int count=0;
		int length=w1.size();
		if(w1==w2)
			return false;

		for(int i=0;i<length;i++)
			if(w1[i]!=w2[i])
				{
					count++;
					if(count>1)
						return false;
				}
		return true;
	}

	/*vector<string> candidates_words(string word, unordered_set<string> &dict)
	{//return all possible word as a vector		
		return Adjacent[word];
	}*/
	vector<string> candidates_words(string word ,unordered_set<string> dict)
	{
		vector<string> res;
		for(int i=0;i<word.size();i++)
		{
			char tmp=word[i];
			for(char c='a';c<='z';c++)
			{
				if(c==tmp)
					continue;
				word[i]=c;
				//cout<<word<<endl;
				if(dict.find(word)!=dict.end())
					res.push_back(word);
			}
			word[i]=tmp;
		}
		return res;
	}


	vector<vector<string> > DFS(vector<string> vec,string end,unordered_set<string> dict,int limit){
		vector<vector<string> > res;
		/*if(vec.size()>limit)
		{
			cout<<vec.size()<<" "<<limit<<endl;
			return res;
		}*/
		
		string word=vec.back();
		vector<string> candidates=candidates_words(word,dict);
		for(string x: candidates){
			vec.push_back(x);
			dict.erase(x);
			if(is_candidate(x,end)) //find the result
			{	
				vec.push_back(end);
				res.push_back(vec);
			}
			else
			{
				auto sub_result=DFS(vec,end,dict,limit);
				res.insert(res.end(),sub_result.begin(),sub_result.end());
			}
			vec.pop_back();
			dict.insert(x);

		}
		return res;



	}
	int BFS(string start,string end,unordered_set<string> &dict){
		deque< vector<string> > search_queue;
		vector<string> init;
		init.push_back(start);
		search_queue.push_back(init);
		while(!search_queue.empty()){
			vector<string> vec=search_queue.front();
			string word=vec.back();
			search_queue.pop_front();
			vector<string> candidates=candidates_words(word,dict);
			for(auto x: candidates){
				if(is_candidate(x,end)){
					return vec.size();
				}
				else{
					vec.push_back(x);
					search_queue.push_back(vec);
					vec.pop_back();
				}
			}

		}


	}
	vector<vector<string> > findLadders2(string start,string end,unordered_set<string> &dict){
		vector<string > init;
		init.push_back(start);
		int limit=BFS(start,end,dict);
		//cout<<limit<<endl;
		return DFS(init,end,dict,limit);

	}

	void Build_Map(unordered_set<string> dict,string start,string end){
		dict.insert(start);
		dict.insert(end);
		for(auto x : dict)
			for(auto y:dict){
				if(is_candidate(x,y))
					Adjacent[x].push_back(y);
			}
	}
		
	
	vector<vector<string> > findLadders1(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> >  res;
		deque< vector<string> > search_queue;
		vector<string> init;
		init.push_back(start);
		search_queue.push_back(init);
		int found_length=99999999;
				
		while(!search_queue.empty()){
			vector<string> first_element=search_queue.front();
			search_queue.pop_front();
			if(first_element.size()>=found_length+2)
				break;
			string word=first_element.back();
			vector<string> candidates=candidates_words(word,dict);
			/*cout<<"cand"<<endl;
			for(string x: candidates){
				cout<<x<<" ";
			}
			cout<<endl;*/
			for(auto cand_word: candidates){
				vector<string> new_element=first_element;
				new_element.push_back(cand_word);
				/*for(auto x: new_element)
					cout<<x<<" ";
				cout<<endl;*/
				if(is_candidate(cand_word,end))
				{
					
					if (new_element.size()<found_length)
					{
						//cout<<"yes"<<found_length<<endl;
						new_element.push_back(end);
						res.push_back(new_element);
						found_length=new_element.size();
					}
					
				}else
				{
					if(new_element.size()<found_length)
						search_queue.push_back(new_element);
				}
			}
		}
		return res;
	}


};

int main()
{
	Solution *sol= new Solution;
	//string init[]={"hot","dot","dog","lot","log"};
	string start = "hot";
	string end = "dog";
	unordered_set<string> dict({"hot","dog","dog"});
	auto result=sol->findLadders1(start,end,dict);
	for(auto x:result){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}
}
