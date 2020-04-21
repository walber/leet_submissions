
class Solution {
public:
    int getSum(int a, int b) {
        bool res_comp1 = false;
	unsigned int carry, temp, result, one_comp1;

        if (a < 0 || b < 0) {
            res_comp1 = true;
            temp = (a < 0) ? a : b;
            b = (temp == a) ? b : a;

            one_comp1 = 1 ^ -1;
            a = temp ^ one_comp1;
            carry = temp & one_comp1;
            carry <<= 1;
        
            while (carry != 0) {
                temp = a ^ carry;
                carry = a & carry;
                carry <<= 1;
                a = temp;
	    }
            
            temp = a ^ 1;
            carry = a & 1;
            carry <<= 1;
            a = temp;

            while (carry != 0) {
                temp = a ^ carry;
                carry = a & carry;
                carry <<= 1;
                a = temp;
	    }
	}

        result = a ^ b;
        carry = a & b;
        carry <<= 1;

        while (carry != 0) {
            temp = result ^ carry;
            carry = result & carry;
            carry <<= 1;
            result = temp;
        }

        if (res_comp1) {
            temp = result ^ 1;
            carry = result & 1;
            carry <<= 1;
            result = temp;
              
            while (carry != 0) {
                temp = result ^ carry;
                carry = result & carry;
                carry <<= 1;
                result = temp;
	    }
	}

        return result;
    }
};
