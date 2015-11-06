#include <iostream>
#include <priority_queue>
#include <multiset>
using namespace std;
class Solution {
	public:
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			vector<pair<int,int>> build_vec;		
			for(vector<int> building:buildings){
				int start=building[0];
				int end=building[1];
				int height=building[2];
				build_vec.push_back( pair<int,int>(start,height));
				build_vec.push_back( pair<int,int>(end,-height));
			}
			vector<pair<int,int>> res;
			int bar=0,cur=0;
			sort(build_vec.begin(),build_vec.end());
			multiset<int> ms;
			ms.insert(0);
			for(pair<int,int> point:build_vec){
				int height=point.second;
				int index=point.first;
				if(height<0)
					ms.erase(-height);
				else
					ms.insert(height);
				int cur= *ms.rbegin();
				cout<<bar<<" "<<cur<<endl;
				if(bar!= cur){
					res.push_back(pair<int,int>(index,cur));
					bar=cur;
				}

			}
			return res;


		}
};
int main(){
}
