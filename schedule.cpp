#include <iostream>
#include <list>
using namespace std;
class Solution {
	public:
		list<int> *BuildGraph(int num,vector<pair<int, int>>& prerequisites){
			list<int> res[num];
			for(int i=0;i<num;i++){
				res[i]=list<int>();
			}
			for(pair<int,int> p:prerequisites){
				int pre=p.second;
				int course=p.first;
				res[course].push_back(pre);
			}
			return res;
		}
		bool DFS(int course,list<int> *graph,set<int> &record){
			if(record.find(course!=record.end())
					return false;
			record.insert(course);
			list<int> pres=graph[course];
			for(int pre:pres){
				bool branch_res=DFS(pre,graph,record)
				if(!branch_res){
				        record.remove(course);
					return false;
				}
			}
			return true;
		}
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			list<int> *g=BuildGraph(numCourses,prerequisites);
			for(int i=0;i<n;i++){
				bool tmp=DFS(i,g,set<int>());
				if(tmp==false)
					return false;
			}
			return true;

		}
};
int main(){
}
