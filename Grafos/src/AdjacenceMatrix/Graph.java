package AdjacenceMatrix;

public class Graph {

    int[][] matrix;
    Node[] nodes;
    int numberOfNodes = 0;

    Graph(int size){
        this.matrix = new int[size][size];
        this.nodes = new Node[5];
    }

    public void addEdge(int origin, int destination){
        // matrix bidirectional
        matrix[origin][destination] = 1;
        matrix[destination][origin] = 1;
        System.out.println("New edge: " + nodes[origin].data + " -> " + nodes[destination].data);
    }

    public void getNodesAndPositions(){
        for (int i = 0; i < nodes.length; i++) {
            Node node = nodes[i];
            System.out.println(node.data + " position: " + i);
        }
        System.out.println();
    }

    public void addNode(Node v){
        nodes[numberOfNodes] = v;
        numberOfNodes++;
    }

    public void checkEdge(int origin, int destination){
         if(matrix[origin][destination] == 1){
             System.out.println(nodes[origin].data + " faz divisa com " + nodes[destination].data);
         } else {
             System.out.println(nodes[origin].data + " não faz divisa com " + nodes[destination].data);
         }
    }

    public int getNumberOfNodes(){
        return numberOfNodes;
    }

    public void printMatrix(){
        System.out.print("    ");
        for(Node node : nodes){
            System.out.print(node.data + " ");
        }
        System.out.println();
        for(int i = 0; i < matrix.length; i++){
            System.out.print(nodes[i].data + " ");
            for(int j = 0; j < matrix.length;j++){
                System.out.print(" " + matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
