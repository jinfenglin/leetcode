#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;
//need to keep record of visted node to accelerate
class Solution {
	public:
		list<int> **BuildGraph(int num,vector<pair<int, int>>& prerequisites){
			list<int> **res;
			res=(list<int> **)malloc(sizeof(list<int>*)*num);
			for(int i=0;i<num;i++){
				res[i]=new list<int>();
			}
			for(pair<int,int> p:prerequisites){
				int pre=p.second;
				int course=p.first;
				(*res[course]).push_back(pre);
			}
			return res;
		}
		bool DFS(int course,list<int> **graph,unordered_set<int> &record,vector<bool> &visited){
			visited[course]=true;
			if(record.find(course)!=record.end())
					    return false;
					    
			record.insert(course);
			list<int> pres=*(graph[course]);
			for(int pre:pres){
				bool branch_res=DFS(pre,graph,record,visited);
				if(!branch_res){
					record.erase(course);
					return false;
				}
			}
			record.erase(course);
			return true;
		}
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			list<int> **g=BuildGraph(numCourses,prerequisites);
			vector<bool> visited(numCourses,false);
			for(int i=0;i<numCourses;i++){
				if(visited[i])
					continue;
				unordered_set<int> st;
				bool tmp=DFS(i,g,st,visited);
				if(tmp==false)
					return false;
			}
			return true;

		}
};
int main(){
	Solution *sol=new Solution;
	vector<pair<int,int>> vec;
	cout<<sol->canFinish(1,vec)<<endl;
}
