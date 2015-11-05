#include <iostream>
#include <vector>
using namespace std;
class MedianFinder {
	public:
		priority_queue<int,vector<int>,greater<int>> min_heap;
		priority_queue<int,vector<int>,less<int>> max_heap;

		// Adds a number into the data structure.
		void addNum(int num) {
			if(min_heap.size()==0 or min_heap.top()<=num)
				min_heap.push(num);
			else
				max_heap.push(num);

			if(min_heap.size()>max_heap.size()+1){
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			else if(max_heap.size()>min_heap.size()){
				min_heap.push(max_heap.top());
				max_heap.pop();
			}		
			cout<<min_heap.top()<<" "<<max_heap.top()<<endl;
			
			/*void addNum(int num) { return element if max_heap is larger
				minH.push(num);
				int n = minH.top();
				minH.pop();
				maxH.push(n);
				int len1 = maxH.size();
				int len2 = minH.size();
				if (len1 > len2)
				{
					n = maxH.top();
					maxH.pop();
					minH.push(n);
				}
			}*/
		}

		// Returns the median of current data stream
		double findMedian() {
			if(min_heap.size()==max_heap.size())
				return (min_heap.top()+max_heap.top())*0.5;
			else
				return min_heap.top();

		}
};

int main(){
}
