#include <iostream>
#include <vector>
using namespace std;
class NumArray {
	public:
		vector<int> bit;
		vector<int> nums;
		NumArray(vector<int> &nums) {
			this->nums=nums;
			bit.resize(nums.size());
			for(int i=0;i<nums.size();i++)
				bit[i]=0;
			build();
		}
		int lowbit(int i){
			i+=1;
			return i&(-i);
		}
		void build(){
			vector<int> back=nums;
			for(int i=0;i<nums.size();i++)
				update(i,2*nums[i]);
			nums=back;
		}
		void update(int i, int val) {
			int delt=val-nums[i];
			nums[i]=val;
			while(i<bit.size()){
				bit[i]+=delt;
				i+=lowbit(i);
			}
		}
		int getSum(int i){
			int sum=0;
			while(i>=0){
				sum+=bit[i];
				i-=lowbit(i);
			}
			return sum;
		}
		int sumRange(int i, int j) {
			return getSum(j)-getSum(i)+nums[i];

		}
};
int main(){
	vector<int> nums={7,2,7,2,0};
	NumArray *na=new NumArray(nums);
	na->update(4,6);
	na->update(0,2);
	na->update(0,9);
	cout<<na->sumRange(4,4)<<endl;
	na->update(3,8);
	cout<<na->sumRange(0,4)<<endl;

	cout<<endl;	
	for(int i=0;i<nums.size();i++)
		cout<<na->nums[i]<<endl;

	na->update(4,1);
	cout<<na->sumRange(0,3)<<endl;
	cout<<na->sumRange(0,4)<<endl;
	na->update(0,4);
	cout<<na->sumRange(0,1)<<endl;
	
}
