class Solution {
public: 

    int p(char op) {
        if(op == '*' || op == '/') {
            return 2;
        }
        else {
            return 1;
        }
    }

    int solve(int val2, int val1, char op) {

        if(op == '+') {
            return val1 + val2;
        }
        else if(op == '-') {
            return val1 - val2;
        }
        else if(op == '*') {
            return val1 * val2;
        }
        else {
            return val1 / val2;
        }
    }

    int calculate(string s) {

        stack<int> value;
        stack<char> operators;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                continue;
            }
            else if(isdigit(s[i])) {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                value.push(num);
                i--;
            }
            else {

                if(operators.empty() || 
                   p(operators.top()) < p(s[i])) {

                    operators.push(s[i]);
                }

                else {

                    while(!operators.empty() &&
                          p(operators.top()) >= p(s[i])) {

                        int val2 = value.top();
                        value.pop();

                        int val1 = value.top();
                        value.pop();

                        char op = operators.top();
                        operators.pop();

                        int ans = solve(val2, val1, op);

                        value.push(ans);
                    }

                    operators.push(s[i]);
                }
            }
        }


        while(!operators.empty()) {

            int val2 = value.top();
            value.pop();

            int val1 = value.top();
            value.pop();

            char op = operators.top();
            operators.pop();

            int ans = solve(val2, val1, op);

            value.push(ans);
        }

        return value.top();
    }
};