#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			map<string,int> mp;
			vector<string> result;
			for(int i=0;i<s.length();i++)
			{
				cout<<s.length()<<endl;
				string substring=s.substr(i,10);
				mp[substring]+=1;
				if (mp[substring]==2)
				{
					result.push_back(substring);
				}
			}
			return result;
		}
};


int main()
{
	string str="";
	Solution *sol=new Solution;
	auto result=sol->findRepeatedDnaSequences(str);
	for(auto it=result.begin();it!=result.end();it++){
		cout<<*it<<endl;
	}
}
