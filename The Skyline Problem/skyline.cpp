#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
	public:
		static bool func(vector<int> v1,vector<int> v2){
			if(v1[1]==v2[1])
			    return v1[2]>v2[2];
			return v1[1]> v2[1];
		}
		static bool func2(vector<int> v1,vector<int> v2){
		    if(v1[0]==v2[0])
		        return v1[2]>v2[2];
		    return v1[0]<v2[0];
		}
		vector<pair<int,int>> merge(vector<pair<int,int>> v1,vector<pair<int,int>> v2){
			v1.insert(v1.end(),v2.begin(),v2.end());
			sort(v1.begin(),v1.end());
			return v1;
			
		}
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			stack<pair<int,int>> bar_stack;
			vector<pair<int,int>> forth,back;
			sort(buildings.begin(),buildings.end(),func2);
			for(vector<int> building:buildings){
				int start=building[0];
				int end=building[1];
				int height=building[2];
				while(!bar_stack.empty() and bar_stack.top().second<start)
					bar_stack.pop();
				if(bar_stack.empty() or bar_stack.top().first<height){
					bar_stack.push(pair<int,int>(height,end));
					forth.push_back(pair<int,int>(start,height));
				}

			}
			bar_stack=*(new stack<pair<int,int>>());
			sort(buildings.begin(),buildings.end(),func);
			for(vector<int> building:buildings){
				int start=building[0];
				int end=building[1];
				int height=building[2];
				while(!bar_stack.empty() and bar_stack.top().second>end)
					bar_stack.pop();
				int pre_height= bar_stack.empty()? 0:bar_stack.top().first;
				
				
				
				if(bar_stack.empty() or bar_stack.top().first<height){
					//bar_stack.push(pair<int,int>(height,start));
					back.push_back(pair<int,int>(end,pre_height));
					//cout<<"height:"<<bar_stack.top().first<<"start:"<<bar_stack.top().second<<endl;
				}
				
				queue<pair<int,int>> tmp;
				while(!bar_stack.empty() and bar_stack.top().first>=height){
					tmp.push(bar_stack.top());
					bar_stack.pop();
				}
				bar_stack.push(pair<int,int>(height,start));
				while(!tmp.empty()){
					bar_stack.push(tmp.front());
					tmp.pop();
				}

			}
			//return back;
			return merge(forth,back);
			
		}
};
int main(){
	Solution *sol=new Solution;
}
