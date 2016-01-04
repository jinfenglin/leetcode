#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
class Solution {
public: 
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto e: edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<int> degree(n, 0);
        for(int i=0; i<n; i++) degree[i]=graph[i].size();
        for(int i=0, j, remain=n; i<n && remain>2; i++){
            vector<int> del; // nodes to delete
            for(j=0; j<n; j++){
                if(degree[j]==1) {
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            }
            for(auto k: del){ //delete this node and all connected edges 
                for(auto neigh: graph[k]) degree[neigh]--;
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(degree[i]>=0) res.push_back(i);
        }
        return res;
    }
};
int main(){
	Solution *sol=new Solution;
	pair<int,int> p1(0,1);
	pair<int,int> p2(0,2);
	pair<int,int> p3(0,3);
	pair<int,int> p4(3,4);
	pair<int,int> p5(4,5);
	vector<pair<int,int>> edges={p1,p2,p3,p4,p5};
	sol->findMinHeightTrees(6,edges);
}
