import java.util.*;
class UndirectedGraphNode {
	int label;
	List<UndirectedGraphNode> neighbors;
	UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
};
public class Solution {
	UndirectedGraphNode DFS(UndirectedGraphNode node,Map<UndirectedGraphNode,UndirectedGraphNode> visited){
		UndirectedGraphNode newNode=new UndirectedGraphNode(node.label);
		visited.put(node,newNode);
		for(UndirectedGraphNode iter:node.neighbors){
			UndirectedGraphNode next;
			if(!visited.containsKey(iter))
				next=DFS(iter,visited);
			else
				next=visited.get(iter);

			newNode.neighbors.add(next);

		}
		return newNode;

	}
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
	    if(node==null)
	        return null;
		Map<UndirectedGraphNode,UndirectedGraphNode> visited=new HashMap<UndirectedGraphNode,UndirectedGraphNode>();
		return DFS(node,visited);

	}
}
