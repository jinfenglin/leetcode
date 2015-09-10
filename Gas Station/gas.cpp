#include <iostream>
#include <vector>
using namespace std;


class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int size=gas.size();
			vector<int> dif;
			int gas_amount=0;
			for(int i=0;i<size;i++)
			{
				dif.push_back(gas[i]-cost[i]);
				gas_amount+=gas[i]-cost[i];
			}
			if(gas_amount<0)
				return -1;
			int tank=0;
			int start=0;
			for(int i=0;i<size;i++){
				tank+=dif[i];
				if(tank<0){
					tank=0;
					start=i+1;
				}
				
			}			
			return start;
		}
};
int main(){
	Solution *sol=new Solution;
	//vector<int> gas={6,0,1,3,2};
	//vector<int> cost={4,5,2,5,5};
	//vector<int> gas={4};
	//vector<int> cost={5};
	//vector<int> gas={99,98,97,100};
	//vector<int> cost={100,100,100,97};
	vector<int> gas={1,2};
	vector<int> cost={2,1};
	cout<<sol->canCompleteCircuit(gas,cost)<<endl;
}
