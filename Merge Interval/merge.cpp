#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	void print(){
		cout<<start<<" "<<end<<endl;
	}
};

class Solution {
	public:
		static bool myfunc(Interval v1,Interval v2){
			if(v1.start<v2.start)
				return true;
			else if(v1.start==v2.start)
				return v1.start<v2.end;
			else
				return false;
		}
		bool overlap(Interval v1,Interval v2){
			if(v1.start>=v2.end or v1.end<=v2.start)
				return false;
			return true;
		}
		Interval Interval_merge(Interval v1,Interval v2){
			Interval new_v;
			if(overlap(v1,v2)){
				new_v.start=min(v1.start,v2.start);
				new_v.end=max(v1.end,v2.end);
			}
			return new_v;

		}
		vector<Interval> merge(vector<Interval>& intervals) {
			sort(intervals.begin(),intervals.end(),myfunc);
			//int size=intervals.size();
			for(int i=0;i<intervals.size();i++){
				for(int j=0;j<i;j++){
					//cout<<"i:"<<i<<" j:"<<j<<endl;
					Interval v1=intervals[i];
					Interval v2=intervals[j];
					//v1.print();
					//v2.print();
					
					if(overlap(v1,v2) and v2.end!=0){
						Interval new_v=Interval_merge(v1,v2);
						intervals.erase(intervals.begin()+j,intervals.begin()+i+1);			
						intervals.insert(intervals.begin()+j,new_v);
						i=j;
						break;
					}
				}
			}
			return intervals;
		}
};

int main(){
	Solution *sol=new Solution;
	Interval iv1(1,6);
	Interval iv2(2,7);
	Interval iv3(8,8);
	Interval iv4(18,20);
	vector<Interval> init={iv1,iv2,iv3,iv4};
	auto result=sol->merge(init);
	//cout<<"final"<<result.size()<<endl;
	for(Interval x:result){
		x.print();
	}

}
