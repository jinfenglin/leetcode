#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:

		vector<vector<int>> combine(int n, int k) {
			//cout<<n<<" "<<k<<endl;
			if(n<k or k==0)
				return vector<vector<int>>();
			vector<vector<int>> result;
			for(int i=n;i>=k;i--){
				vector<vector<int>> tmp=combine(i-1,k-1);
				if(!tmp.empty())
					for(vector<int> &vec: tmp){
						vec.push_back(i);
						result.push_back(vec);
					}
				else
					result.push_back(vector<int>(1,i));
			}
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	auto result=sol->combine(4,3);
	for(vector<int> v:result){
		for(int s:v){
			cout<<s<<" ";
		}
		cout<<endl;
	}
}
