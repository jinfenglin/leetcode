class Solution {
	public:
		int hIndex(vector<int>& citations) {
		    if(citations.size()==0)
		        return 0;
			sort(citations.begin(),citations.end(),greater<int>());
			int i=0;
			for(;i<citations.size();i++)
				if(citations[i]<i+1)
					break;
			return i;
		}
			
};
