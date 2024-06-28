import java.util.Arrays;

public class Main {
    /*
        Given the root of a binary tree and the value of a target node target,
        and an integer K, return a list of the values of all nodes that have a distance of K
        from the target Node.

        Ex: target = 5, K = 2

                              3
                           /    \
                         5        1
                       /  \    /   \
                      6    2   0     8
                          / \
                         7   4
         expected output = [1,7,4]

     */
    public static void main(String[] args) {
        var binaryTree = new BinaryTree(new Node(3));
        binaryTree.insertNode(3, 5, 1);
        binaryTree.insertNode(5, 6, 2);
        binaryTree.insertNode(2, 7, 4);
        binaryTree.insertNode(1, 0, 8);
//        binaryTree.print();
        int[] elementsKdistance = binaryTree.elementsFromKdistance(5,3);
        System.out.println(Arrays.toString(elementsKdistance));
    }
}