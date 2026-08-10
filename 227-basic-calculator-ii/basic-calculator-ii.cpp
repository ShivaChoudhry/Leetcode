class Solution {
public:


    int p(char op) {
        if (op == '+' || op == '-')
            return 1;

        if (op == '*' || op == '/')
            return 2;

        return 0;
    }

    void solve(stack<int>& value, stack<char>& operators) {

        int val2 = value.top();
        value.pop();

        int val1 = value.top();
        value.pop();

        char op = operators.top();
        operators.pop();

        if (op == '+')
            value.push(val1 + val2);

        else if (op == '-')
            value.push(val1 - val2);

        else if (op == '*')
            value.push(val1 * val2);

        else if (op == '/')
            value.push(val1 / val2);
    }

    int calculate(string s) {

        stack<int> value;
        stack<char> operators;

        for (int i = 0; i < s.size(); i++) {


            if (s[i] == ' ')
                continue;


            if (isdigit(s[i])) {

                int num = 0;


                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                value.push(num);


                i--;
            }

            // If it is an operator
            else {

                // Solve operators with higher or equal precedence
                while (!operators.empty() &&
                       p(operators.top()) >= p(s[i])) {

                    solve(value, operators);
                }

                // Push current operator
                operators.push(s[i]);
            }
        }

        // Solve remaining operators
        while (!operators.empty()) {
            solve(value, operators);
        }

        return value.top();
    }
};