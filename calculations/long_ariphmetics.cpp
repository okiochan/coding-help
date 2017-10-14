//from end
struct Number {
    static const int POW10 = 1000000000;
    vector <int> digits;

    Number(int value) : digits(1, value) {}
    Number(vector <int> digits) : digits(digits) {} //from end to begin

    void print() const { // without zeros
        printf("%d", digits.back());
        for (int i = digits.size() - 2; i >= 0; i--)
            printf("%09d", digits[i]);
    }

    const Number operator + (const Number &second) const {
        vector <int> result;
        int carry = 0, sizeFirst = digits.size(), sizeSecond = second.digits.size();

        for (int i = 0; i < sizeFirst || i < sizeSecond; i++) {

            int digit1;
            if (i < sizeFirst) digit1 = digits[i];
            else digit1 = 0;

            int digit2;
            if (i < sizeSecond) digit2 = second.digits[i];
            else digit2 = 0;

            carry += digit1 + digit2;
            result.push_back(carry % POW10);
            carry /= POW10;
        }

        if (carry > 0) result.push_back(carry);
        return Number(result);
    }

    const Number operator *(const Number &second)const {

        int sizeFirst = digits.size(), sizeSecond = second.digits.size();
        vector<int> result(sizeFirst + sizeSecond);

        for (int i = 0; i < sizeFirst; i++) {
            ll carry = 0;
            for (int j = 0; j < sizeSecond; j++) {

                carry += result[i + j] + (ll)digits[i] * second.digits[j];
                result[i + j] = carry%POW10;
                carry /= POW10;
            }
            result[i + sizeSecond] = (int)carry;
        }
        while (result.size() > 1 && result.back() == 0) result.pop_back();
        return Number(result);
    }
};
