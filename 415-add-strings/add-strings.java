class Solution {
    public String addStrings(String num1, String num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;

        int carry=0;
        StringBuilder st=new StringBuilder();
        while(i>=0 || j>=0 ||carry != 0){
            int digit1 = (i >= 0) ? num1.charAt(i) - '0' : 0;
            int digit2 = (j >= 0) ? num2.charAt(j) - '0' : 0;


            int result=digit1+digit2+carry;
            st.append(result%10);
            carry=result/10;
            i--;
            j--;
        }

        return st.reverse().toString();
    }
}