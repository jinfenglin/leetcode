#include <iostream>
using namespace std;
class Solution {
	public:
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int area1=(C-A)*(D-B);	
			int area2=(G-E)*(H-F);

			int h1=max(A,E);
			int h2=min(C,G);
			int h=h2-h1;

			int v1=max(B,F);
			int v2=min(D,H);
			int v=h2-h1;

			int overlap=h*v<0? 0:h*v;
			return area1+area2-overlap;		
		}
};
int main(){
}
