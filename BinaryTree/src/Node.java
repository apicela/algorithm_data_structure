public class Node {
    int data;
    Node left, right, parent;
    public Node(int data, Node parent) {
        this.data = data;
        this.parent = parent;
    }
    public Node(int data) {
        this.data = data;
    }
    public String printNode() {
        if (this != null) {
           return ("Node: " + this.data +
                    " | parent: " + (this.parent != null ? this.parent.data : " ") +
                    " | left: " + (this.left != null ? this.left.data : " ") +
                    " | right: " + (this.right != null ? this.right.data : " "));
        }
        return "";
    }
}
