import java.util.ArrayList;

public class BinaryTree {
    private Node root, targettedNode;
    private final ArrayList<Integer> responseKdistance = new ArrayList<>();
    boolean[] visitedElements = new boolean[100];
    public BinaryTree(Node root){
        this.root = root;
    }

    public void insertNodeAt(int parentData, int data, String position){
        Node parent = search(parentData);
        if(parent != null) insert(parent, data, position);
    }

    public void insertNode(int parentData, int leftData, int rightData){
        Node parent = search(parentData);
        if(parent != null) insert(parent, leftData, rightData);
    }

    public void print(){
       dfs(root);
    }


    public int[] elementsFromKdistance(int target, int k){
        Node targettedNode = search(target);
        dfsKdistance(targettedNode, 0, k);
        int[] response =  responseKdistance.stream().mapToInt(Integer::intValue).toArray();
        responseKdistance.clear();
        return response;
    }

    private void dfsKdistance(Node node, int counter, int k){
        if(visitedElements[node.data]) return;
        visitedElements[node.data] = true;
        if (counter == k){
          responseKdistance.add(node.data);
        }
        if(node.parent != null && counter < k){
            dfsKdistance(node.parent, counter+1, k);
        }
        if(node.left != null && counter < k){
            dfsKdistance(node.left, counter+1, k);
        }
        if(node.right != null && counter < k){
            dfsKdistance(node.right, counter+1, k);
        }
    }

    private void insert(Node node, int data, String position){
        if(position.equals("left")){
            if(node.left == null){
                node.left = new Node(data, node);
            } else{
                System.out.println("Já possui elemento na posição `left` do Node");
            }
        }  else if(position.equals("right")){
            if(node.right == null){
                node.right = new Node(data, node);
            } else{
                System.out.println("Já possui elemento na posição `right` do Node");
            }
        }
    }

    private void insert(Node node, int leftData, int rightData){
//        System.out.println("insert called for: " + node.data + " || " + node.left + node.right);
        if(node.left == null && node.right == null){
            node.left = new Node(leftData, node);
            node.right = new Node(rightData, node);
        }
    }

    private Node search(int data){
//        System.out.println("Search called for: " + data);
        dfs(root, data);
        Node nodeToReturn = targettedNode;
//        System.out.println("Found: " + nodeToReturn.data);
        targettedNode = null;
        return nodeToReturn;
    }

    private void dfs(Node node, int target){
        if(node.data == target) {
            targettedNode = node;
            return;
        }
        else if(node == null) return;
         if(node.left != null){
            dfs(node.left, target);
        }
         if(node.right != null){
            dfs(node.right, target);
        }
    }


    private void dfs(Node node){
        if(node != null) {
            System.out.println("Node: " + node.data +
                    " | parent: " + (node.parent != null ? node.parent.data : " ") +
                    " | left: " + (node.left != null ? node.left.data : " ") +
                     " | right: " + (node.right != null ? node.right.data : " "));
        }
        if(node.left != null){
            dfs(node.left);
        }
        if(node.right != null){
            dfs(node.right);
        }
    }
}
