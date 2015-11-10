class Solution {
	private:
		struct bucket{
			int max;
			int min;
			bool empty;
			bucket(): empty(true),max(INT_MIN),min(INT_MAX){}
		};
	public:
		int maximumGap(vector<int>& nums) {
		    if(nums.size()<2)
		        return 0;
			int res=0;
			int min_val=INT_MAX,max_val=INT_MIN;
			for(int i:nums){
				max_val=max(max_val,i);
				min_val=min(min_val,i);
			}
			int interval=(max_val-min_val)/(nums.size()-1);
			if (interval==0)
			    interval=1;
			int buck_num=(max_val-min_val)/interval+1;
			vector<bucket> vec;
			for(int i=0;i<buck_num;i++)
				vec.push_back(bucket());
			for(int i:nums){
				int loc=(i-min_val)/interval;
				
				vec[loc].empty=false;
				vec[loc].max=max(vec[loc].max,i);
				vec[loc].min=min(vec[loc].min,i);
			}
			for(int i=0;i<vec.size();i++){
				bucket bt=vec[i];
				if(!bt.empty)
					for(int j=i+1;j<vec.size();j++){
						bucket b2=vec[j];
						if(!b2.empty){
							res=max(res,b2.min-bt.max);
							break;
						}
						
					}
			}
			return res;
		}
};

