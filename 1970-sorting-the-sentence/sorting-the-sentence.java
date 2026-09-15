import java.util.ArrayList;

class Solution {
    public String sortSentence(String s) {

        ArrayList<String> st = new ArrayList<>();


        for (int i = 0; i < 9; i++) {
            st.add("");
        }

        StringBuilder temp = new StringBuilder();

        for (char ch : s.toCharArray()) {

            if (ch != ' ') {
                temp.append(ch);
            } 
            else {
                int index = temp.charAt(temp.length() - 1) - '1';


                String word = temp.substring(0, temp.length() - 1);


                st.set(index, word);
                temp.setLength(0);
            }
        }

        // Process the last word
        int index = temp.charAt(temp.length() - 1) - '1';
        String word = temp.substring(0, temp.length() - 1);
        st.set(index, word);


        StringBuilder ans = new StringBuilder();

        for (String str : st) {
            if (!str.equals("")) {
                if (ans.length() > 0) {
                    ans.append(" ");
                }

                ans.append(str);
            }
        }

        return ans.toString();
    }
}