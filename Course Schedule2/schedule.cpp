#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<int>> BuildGraph(int numCourses, vector<pair<int, int>>& prerequisites){
			vector<vector<int>> res(numCourses,vector<int>());
			for(pair<int,int> p:prerequisites){
				res[p.first].push_back(p.second); //second is pre
			}
			return res;
		}
		bool DFS(int course, vector<vector<int>> &graph,vector<bool> &visited,vector<bool> &loop_checker,vector<int> &res){
			vector<int> links=graph[course];
			visited[course]=true;
			for(int next:links){
				if(loop_checker[next]){
					res=vector<int>();
					return false;
				}else if(visited[next]){
					continue;
				}
				loop_checker[course]=true;
				//if not accessed before
				bool able_flag=DFS(next,graph,visited,loop_checker,res);
				if(!able_flag){//has loop
					res=vector<int>();
					return false;
				}
			}
			loop_checker[course]=false;
			res.push_back(course);
			return true;
		}
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<vector<int>> graph=BuildGraph(numCourses,prerequisites);//
			vector<bool> visited(numCourses,false),loop_checker(numCourses,false);
			vector<int> res;
			for(int i=0;i<numCourses;i++){
				if(visited[i])
					continue;
				bool flag=DFS(i,graph,visited,loop_checker,res);
				if(!flag)
					break;
			}
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<pair<int,int>> pre;
	pair<int,int> p1(0,1);
	//pair<int,int> p2(1,0);
	pre.push_back(p1);
	//pre.push_back(p2);
        auto res=sol->findOrder(2,pre);
	for(int r:res)
		cout<<r<<endl;
}
