#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
typedef UndirectedGraphNode UG;
class Solution {
	private:
		map<UG *,UG *> mem;

	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if(!node)
				return NULL;
			UG *new_node=new UG(node->label);
			mem[node]=new_node;
			for(UG * neighbor: node->neighbors){
				if(mem.find(neighbor)==mem.end()){
					//cout<<"yes:"<<neighbor->label<<endl;
					UG* clone_nb=cloneGraph(neighbor);
					new_node->neighbors.push_back(clone_nb);
					
				}else{
					new_node->neighbors.push_back(mem[neighbor]);
					//cout<<"no"<<endl;
				}
			} 
			return new_node;
		}
		
};
int main(){
	UG n1(0);
	UG n2(0);
	UG n3(0);
	n1.neighbors.push_back(&n1);
	n1.neighbors.push_back(&n1);
	//n2.neighbors.push_back(&n3);
	Solution *sol=new Solution;
	cout<<sol->cloneGraph(&n1)->neighbors.size()<<endl;
}
