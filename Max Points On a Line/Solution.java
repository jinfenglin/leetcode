import java.util.*;
class Point {
	int x;
	int y;
	Point() { x = 0; y = 0; }
	Point(int a, int b) { x = a; y = b; }
}
public class Solution {
	private Float slop_degree(Point a,Point b){
		if(a.y==b.y)
			return (float)0;
		if(a.x==b.x)
			return Float.POSITIVE_INFINITY;
		return (a.y-b.y)/(float)(a.x-b.x);
	}
	public int maxPoints(Point[] points) {
		int max=0;
		int len=points.length;
		if(len==0)
			return 0;
		for(int i=0;i<len;i++){
			Map<Float,Integer> map=new HashMap<Float,Integer>();
			int weight=0;
			for(int j=0;j<len;j++){
				if(points[i].x==points[j].x & points[i].y==points[j].y)
					weight++;
			}
			for(int j=0;j<len;j++){		
				if(points[i].x==points[j].x & points[i].y==points[j].y){
					if(max<weight)
						max=weight;
					continue;
				}
				float k_value=slop_degree(points[i],points[j]);
				if(map.containsKey(k_value)){
					int val=map.get(k_value)+1;
					if(val+weight>max)
						max=val+weight;
					map.put(k_value,val);
				}else{
					if(max<weight+1)
						max=weight+1;
					map.put(k_value,1);
				}
				
			}
		}
		return max;

	}
}
