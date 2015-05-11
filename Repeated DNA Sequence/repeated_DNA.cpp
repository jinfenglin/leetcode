#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		int hash_fn(string str){
			int result=0;
			for(int i=0;i<str.length();i++)
			{
				int value=0;
				switch(str[i]){
				case 'A':value=0;break;
				case 'C':value=1;break;
				case 'T':value=2;break;
				case 'G':value=3;break;}
				
				result=(result<<2) | value;
			}
			return result;
		}
		vector<string> findRepeatedDnaSequences(string s) {
			unordered_map<int,int> mp;
			//hash<string> hash_fn;
			if (s.length()<10)
				return vector<string>();
			vector<string> result;
			for(int i=0;i<s.length()-9;i++)
			{
				cout<<s.length()<<endl;
				string substring=s.substr(i,10);
				int hash_value=hash_fn(substring);
				mp[hash_value]+=1;
				if (mp[hash_value]==2)
				{
					result.push_back(substring);
				}
			}
			return result;
		}
};


int main()
{
	string str="AAAAAAAAAA";
	Solution *sol=new Solution;
	auto result=sol->findRepeatedDnaSequences(str);
	for(auto it=result.begin();it!=result.end();it++){
		cout<<*it<<endl;
	}
}

