import java.util.*;
public class Solution {
	private Set<Integer> record;
	private Map<Integer,List<Integer>> connection;
	private int count; 
	private boolean DFS(int numCourses,int[] res,int cur,boolean[] explored){	
		if(record.contains(cur))
			return false;
		List<Integer> next= connection.get(cur);
		record.add(cur);
		if(next==null)
			next=new ArrayList<Integer>();
		for(int num:next){
			if(explored[num])
				continue;
			if(!DFS(numCourses,res,num,explored))
				return false;
		}
		record.remove(cur);
		explored[cur]=true;
		res[count++]=cur;
		return true;
	}
	public int[] findOrder(int numCourses, int[][] prerequisites) {
		record= new HashSet<Integer>();
		connection=new HashMap<Integer,List<Integer>>();
		count=0;
		boolean[] explored= new boolean[numCourses];
		int[] res=new int[numCourses];
		for(int[] edge: prerequisites){
			if(connection.get(edge[0])==null)
				connection.put(edge[0],new ArrayList<Integer>());
			connection.get(edge[0]).add(edge[1]);
			
		}

		for(int i=0;i<numCourses;i++){
			if(!explored[i])
				DFS(numCourses,res,i,explored);
		}
		if(count==numCourses)
			return res;
		else
			return new int[0];
		
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		int numCourses=2;
		int[][] pre=new int[1][2];
		pre[0][0]=0;
		pre[0][1]=1;
		int[] ans=sol.findOrder(numCourses,pre);
		for(int i:ans){
			System.out.println(i);
		}
			
	}
}
