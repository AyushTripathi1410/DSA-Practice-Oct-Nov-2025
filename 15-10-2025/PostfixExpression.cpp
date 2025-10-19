class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        for (auto &token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                long long res = 0;

                if (token == "+") res = b + a;
                else if (token == "-") res = b - a;
                else if (token == "*") res = b * a;
                else if (token == "/") {
                    if ((b < 0) ^ (a < 0)) {
                        if (b % a != 0) res = (b / a) - 1;
                        else res = b / a;
                    } else {
                        res = b / a;
                    }
                }
                else if (token == "^") {
                   
                    res = pow(b, a);
                }

                st.push(res);
            } else {
                st.push(stoll(token));
            }
        }
        return st.top();
    }
};
