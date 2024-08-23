class Solution {
private:
    int GCD(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;

        if(a == b) return a;

        if(a > b) return gcd(a - b, b);
        return gcd(a, b - a);
    }
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1;

        int i = 0, n = expression.size();
        while(i < n){
            int currNum = 0;
            int currDen = 0;

            bool isNeg = (expression[i] == '-') ? true : false;

            if(expression[i] == '+' || expression[i] == '-') i++;

            while(i < n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currNum = currNum*10 + val;
                i++;
            }

            i++;//skiping divisor

            if(isNeg == true) currNum *= -1;

            while(i < n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currDen = currDen*10 + val;
                i++;
            }

            num = num * currDen + den * currNum;
            den = den * currDen;
        }

        int gcd = abs(GCD(num, den));
        num /= gcd;
        den /= gcd;

        return to_string(num) + "/" + to_string(den);
    }
};