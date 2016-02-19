class Solution {
	public:
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			int start = 0, netGasSum = 0, curGasSum = 0;
			for(int i=0; i<cost.size(); i++) {
				netGasSum += gas[i] - cost[i];
				curGasSum += gas[i] - cost[i];
				if(curGasSum<0) {
					start = i+1;
					curGasSum = 0;
				}
			} 
			if(netGasSum < 0) return -1;
			return start;
		}
};
