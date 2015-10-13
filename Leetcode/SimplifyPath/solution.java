public class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<String>();
        String[] ps = path.split("/");

        for(int i = 0; i < ps.length; i++){
            if(ps[i].equals(".")){
                continue;
            }else if(ps[i].equals("..") ){
                if (s.size() > 0)
                    s.pop();
            }else if(ps[i].length() == 0){
                continue;
            }else{
                s.push(ps[i]);
            }
        }

        StringBuffer buffer = new StringBuffer();
        while (!s.isEmpty()){
            buffer.append(new StringBuffer(s.peek()).reverse().toString());
            s.pop();
            buffer.append('/');
        }
        buffer.reverse();
        if (buffer.length() == 0){
            buffer.append('/');
        }
        return buffer.toString();
    }
}
