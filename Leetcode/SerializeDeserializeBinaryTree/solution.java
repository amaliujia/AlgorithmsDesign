/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private void serializeUtil(TreeNode root, StringBuffer buf){
        if(root == null){
            buf.append("N").append(',');
            return;
        }
        
        buf.append(root.val).append(',');
        serializeUtil(root.left, buf);
        serializeUtil(root.right, buf);
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuffer buf = new StringBuffer();
        serializeUtil(root, buf);
        String res = buf.toString();
        if(res.charAt(res.length() - 1) == ','){
            return res.substring(0, res.length() - 1);
        }
        return res;
    }

    private TreeNode deserializeUtil(Deque<String> que){
        if(que.isEmpty()){
            return null;
        }
        String s = que.remove();
        if(s.equals("N")){
            return null;
        }
        
        TreeNode node = new TreeNode(Integer.parseInt(s));
        node.left = deserializeUtil(que);
        node.right = deserializeUtil(que);
        return node;
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Deque<String> que = new LinkedList<String>();
        que.addAll(Arrays.asList(data.split(",")));
        return deserializeUtil(que);
    }
}
