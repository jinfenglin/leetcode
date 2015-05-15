#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool is_candidate(string w1,string w2){
		int count=0;
		int length;
		if(w1==w2)
			return false;
		if(w1.size()-w2.size()>1)
		       return false;	
		else if(w1.size()<w2.size())
			length=w1.size();
		else
			length=w2.size();


		for(int i=0;i<length;i++)
			if(w1[i]!=w2[i])
				{
					count++;
					if(count>1)
						return false;
				}
		return true;
	}

	vector<string> candidates_words(string word, unordered_set<string> &dict)
	{//return all possible word as a vector
		vector<string> res;
		for(auto dict_word: dict)
		{
			if(is_candidate(dict_word,word))
				res.push_back(dict_word);

		}
		return res;
	}

	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
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

			for(auto cand_word: candidates){
				vector<string> new_element=first_element;
				new_element.push_back(cand_word);
				//for(auto x: new_element)
				//	cout<<x<<" ";
				//cout<<endl;
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
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict({"hot","dot","dog","lot","log"});
	auto result=sol->findLadders(start,end,dict);
	for(auto x:result){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}
}
