import java.util.*;
public class Solution {
	public boolean canFinish(int numCourses, int[][] prerequisites) {
		Map<Integer,List<Integer>> connection = new HashMap<Integer,List<Integer>>();
		Set<Integer> visited= new HashSet<Integer>();
		for(int[] edge:prerequisites){
			int source=edge[0];
			int target=edge[1];
			if(connection.get(source)==null){
				connection.put(source,new ArrayList<Integer>());
			}else{
				connection.get(source).add(target);
			}

		}	
		boolean[] explored= new boolean[numCourses];
		for(int i=0;i<numCourses;i++){
			if(explored[i])
				continue;
			if(!DFS(connection,visited,explored,i))
				return false;
		}
		return true;
	}
	private boolean DFS(Map<Integer,List<Integer>> connection, Set<Integer> visited,boolean[] explored,int cur){
			if(visited.contains(cur))
				return false;
			visited.add(cur);
			explored[cur]=true;
			List<Integer> next=connection.get(cur);
			for(int node:next){
				if(explored[node])
					continue;
				if(!DFS(connection,visited,explored,node))
					return false;
			}
			visited.remove(cur);
			return true;
	}
}
