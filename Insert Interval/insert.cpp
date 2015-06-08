#include <iostream>
#include <vector>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
	public:
		Interval merge(Interval i1,Interval i2){
			Interval new_it;
			new_it.start=min(i1.start,i2.start);
			new_it.end=max(i1.end,i2.end);
			return new_it;	
		}
		bool overlap(Interval it,Interval target){
			if(target.start>=it.start and target.start<=it.end)
				return true;
			if(target.end>=it.start and target.end<it.end)
				return true;
			if(target.start<it.start and target.end>it.end)
				return true;
			return false;
		}
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> result;
			int start=0;
			for(int i=0;i<intervals.size();i++){
				
				if(overlap(intervals[i],newInterval))
				{
					start=i;
					break;
				}
				result.push_back(intervals[i]);
				
			}
			int i=start;
			for(;i<intervals.size();i++){
				start=i;
				if(overlap(intervals[i],newInterval))
					newInterval=merge(newInterval,intervals[i]);
				else
					break;
			}
			start=i;		
			result.push_back(newInterval);
			for(int i=start;i<intervals.size();i++)
				result.push_back(intervals[i]);
			
			return result;
		}
};
int main(){
	Interval it1(1,2);
	Interval it2(3,4);
	Interval it3(5,7);
	Interval it4(8,10);
	Interval it5(12,16);


	Interval target(4,9);

	vector<Interval> init={it1,it2,it3};
	Solution *sol=new Solution;
	auto result=sol->insert(init,target);
	for(int i=0;i<result.size();i++){
		cout<<result[i].start<<" "<<result[i].end<<endl;
	}
}
