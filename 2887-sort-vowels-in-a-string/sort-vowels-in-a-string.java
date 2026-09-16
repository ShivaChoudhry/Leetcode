import java.util.*;

class Solution {
    public String sortVowels(String s) {

        ArrayList<Character> vowels = new ArrayList<>();

        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                vowels.add(ch);
            }
        }

        Collections.sort(vowels);

        char[] array = s.toCharArray();

        int j = 0;

        for (int i = 0; i < array.length; i++) {

            if (isVowel(array[i])) {
                array[i] = vowels.get(j);
                j++;
            }
        }

        return new String(array);
    }

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }
}