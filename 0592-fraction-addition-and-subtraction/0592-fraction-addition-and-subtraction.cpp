class Solution {
long gcd(long a, long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
pair<long, long>computeExp(char sign, long num1, long den1, long num2, long den2) {
	long den = den1 * den2, num = 0;

	if (sign == '+') {
		num = (den2 * num1) + (den1 * num2);
	}
	else {
		num = (den2 * num1) - (den1 * num2);
	}
	int GCD = gcd(num, den);

	return { num / GCD, den / GCD };
}
pair<int ,pair<long, long>> getNumber(int len, string exp, int index){
	string num = "", den = "";

	while (exp[index] != '/') {
		num.push_back(exp[index++]);
	}
	index++;
	while (index < len && exp[index] != '-' && exp[index] != '+') {
		den.push_back(exp[index++]);
	}
	return { index, {stol(num), stol(den)} };
}
public:
    string fractionAddition(string expression) {
        long num, den, index;
        int len = expression.size();

        if (expression[0] == '-') {
            pair<int, pair<long, long>>number = getNumber(len, expression, 1);
            num = number.second.first * -1;
            den = number.second.second;
            index = number.first;
        }
        else {
            pair<int, pair<long, long>>number = getNumber(len, expression, 0);
            num = number.second.first;
            den = number.second.second;
            index = number.first;
        }

        for (int i = index; i < len; i++) {
            char sign = expression[i];
            pair<int, pair<long, long>>number = getNumber(len, expression, i+1);

            long num2 = number.second.first;
            long den2 = number.second.second;
            i = number.first - 1;

            pair<long, long>res = computeExp(sign, num, den, num2, den2);
            num = res.first;
            den = res.second;
        }
        if (num < 0 && den < 0) {
            num = abs(num);
            den = abs(den);
        }
        else if (den < 0) {
            num *= -1;
            den = abs(den);
        }
        string res = to_string(num) + "/" + to_string(den);

        return res;
    }
};