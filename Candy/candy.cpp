#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
	public:
		int candy(vector<int>& ratings) {
			int sum=0;
			vector<int> res(ratings.size(),1);
			for(int i=1;i<ratings.size();i++){
				if(ratings[i]>ratings[i-1])
					res[i]=res[i-1]+1;
				else
					res[i]=1;
			}
			for(int i=ratings.size()-2;i>=0;i--)
				if(ratings[i]>ratings[i+1] and res[i]<=res[i+1])
					res[i]=res[i+1]+1;
			for(int num:res)
			{
				sum+=num;
				cout<<num<<" ";
			}
			cout<<endl;
			return sum;
		}
};
int main(){
	vector<int> vec={1,2};//1,2,4,4,3
	Solution *sol=new Solution;
	cout<<sol->candy(vec)<<endl;
}
