public class Pair {
	Node node;
	int cost;
	public Pair(Node first, int cost) {
		super();
		node = first;
		this.cost = cost;
	}
	public Pair(Node first, Integer cost) {
		super();
		node = first;
		this.cost = cost;
	}
	public int getValue() {
		// TODO Auto-generated method stub
		return this.cost;
	}
	public Node getKey() {
		// TODO Auto-generated method stub
		return this.node;
	}
	
}
