package AdjacenceMatrix;


public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph(5);

        graph.addNode(new Node("GO"));
        graph.addNode(new Node("MG"));
        graph.addNode(new Node("BA"));
        graph.addNode(new Node("TO"));
        graph.addNode(new Node("RJ"));

        graph.getNodesAndPositions();

        graph.addEdge(1,2);
        graph.addEdge(1, 0);
        graph.addEdge(1, 4);
        graph.checkEdge(1,2);
        graph.checkEdge(2,4);
        System.out.println();
        graph.printMatrix();
    }
}