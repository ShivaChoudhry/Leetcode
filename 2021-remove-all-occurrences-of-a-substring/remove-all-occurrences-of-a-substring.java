class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder st=new StringBuilder();
        
        
        for(char ch: s.toCharArray()){
            st.append(ch);

            if(st.length() >= part.length()){
                int idx=0;
                idx=st.length()-part.length();
                if(st.substring(idx).equals(part)){
                    st.delete(idx,st.length());
                }
            }
        }
        return st.toString();
    }
}