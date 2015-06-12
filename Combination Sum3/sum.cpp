#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    	void combine(int k, int n,vector<int> &solution,vector<vector<int> > &result,int start) {   
		if(n==0 and k==0)
			result.push_back(solution);
		else if(n==0 or k<0)
			return;
		for(int i=start;i<10;i++){
			solution.push_back(i);
			combine(k-1,n-i,solution,result,i+1);
			solution.pop_back();
		}	
    	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> solution;
		vector<vector<int> > result;
		combine(k,n,solution,result,1);
		return result;
        
    	}

};
int main(){
	Solution *sol=new Solution;
	auto result=sol->combinationSum3(3,7);
	for(auto x:result)
	{
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}
	cout<<endl;
	result=sol->combinationSum3(3,9);
	for(auto x:result)
	{
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}

}
