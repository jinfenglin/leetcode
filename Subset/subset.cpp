#include<iostream>
#include<vector>
using namespace std;

static void display_vec(vector<vector<int> > result){
	cout<<"vec in vec"<<endl;
	for(vector<vector<int> >::iterator it=result.begin();it!=result.end();it++){
		for(vector<int>::iterator sub_it=(*it).begin();sub_it!=(*it).end();sub_it++)
		{
			cout<<*sub_it<<" ";
		}
		cout<<endl;
	}
}
static  void display_vec(vector<int> result){
	cout<<"-----------------"<<endl;
	for(vector<int>::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
class Solution{
	public:
		vector<vector<int> > subsets(vector<int>& nums) {
			if (nums.size()==0)
				return vector< vector<int> >(1,vector<int>());
			int first=nums.front();			
			nums.erase(nums.begin());
			vector<vector<int> > combin=subsets(nums);
			vector<vector<int> > temp;
			for(vector<vector<int> >::iterator it=combin.begin();it!=combin.end();it++){
				vector<int> one_combin=*it;
				one_combin.insert(one_combin.begin(),first);
				temp.push_back(one_combin);
			}
			for(vector<vector<int> >::iterator it=temp.begin();it!=temp.end();it++)
			{
				combin.push_back(*it);
			}
			for(vector<vector<int> >::iterator it=combin.begin();it!=combin.end();it++)
			{
				sort((*it).begin(),(*it).end());
			}
		
			return combin;
		}
};

int main()
{
	const int array[]={4,1,0};
	vector<int> init(array,array+sizeof(array)/sizeof(int));
	Solution *sol= new Solution();
	vector<vector<int> > result=sol->subsets(init);
	//display_vec(result);
	return 0;
}
