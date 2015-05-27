#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef vector<vector<int>> double_vector;
class Solution {
	public:
		vector<vector<int> > subset(map<int,int> count_map){
			if(count_map.empty())
			{
				double_vector dummy_result;
				dummy_result.push_back(vector<int> () );
				return dummy_result;
			} 
			double_vector result;
			double_vector first_part;
			double_vector second_part;

			pair<int,int> first_entry=*(count_map.begin());
			count_map.erase(count_map.begin());

			//make first part
			for(int i=0;i<=first_entry.second;i++){
				vector<int> tmp(i,first_entry.first);
				first_part.push_back(tmp);
			}
			//get second part
			second_part=subset(count_map);
			//cout<<"2"<<endl;
			//join two part
			for(vector<int> x:second_part){
				for(vector<int> y:first_part)
				{
					vector<int> tmp(x.begin(),x.end());
					tmp.insert(tmp.begin(),y.begin(),y.end());
					result.push_back(tmp);
				}
			}
			return result;
		}
		
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			map<int,int> count_map;
			for(int x :nums){
				count_map[x]+=1;
			}
			return subset(count_map);

		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> init={1,2,2,3};
	auto result=sol->subsetsWithDup(init);
	for(auto x:result)
	{
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
