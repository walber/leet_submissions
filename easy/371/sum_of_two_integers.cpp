/*
	*
	* @file sum_of_two_integers.cpp
	* @author https://github.com/walber
	*
	* If both parameters 'a' and 'b' are positive, perform the following procedure:
	* 
	*     result = a XOR b
	*     carry = a AND b
	*     carry = carry LEFT SHIFT OF 1 BIT
	*
	*     WHILE carry is not 0, DO
	*         temp = result XOR carry
	*         carry = result AND carry
	*         carry = carry LEFT SHIFT OF 1 BIT
	*         result = temp
	*     END WHILE
	*
	* If at least one of the parameters 'a' or 'b' is negative, perform the following procedure:
	*     
	*     1. select one negative parameter.
	*
	*     2. put it in the ONE'S COMPLEMENT representation (numbers are represented in the two's complement by default).
	*        in practice n in the one's complement is: n + (-1 in the one's complement form) + 1
	*        (1 XOR -1) is minus one in the one's complement form.
	*
	*     3. with one parameter now in the one's complement form, perform the sum procedure when both numbers are positive.
	*        the result will be represented in the one's complement form.
	*
	*     4. put the result in the two's complement form (just add 1 to it).
*/

class Solution {
public:
	int bitwiseSum(int a, int b) {
		unsigned int result, carry, temp;

		result = a ^ b;
		carry = a & b;
		carry <<= 1;

		while (carry != 0) {
			temp = result ^ carry;
			carry = result & carry;
			carry <<= 1;
			result = temp;
		}

		return result;
	}

	int getSum(int a, int b) {
		bool res_comp1 = false;
		unsigned int carry, result, temp;

		if (a < 0 || b < 0) {
			res_comp1 = true;
			temp = (a < 0) ? a : b;
			b = (temp == a) ? b : a;
			a = bitwiseSum(temp, 1 ^ -1);
			a = bitwiseSum(a, 1);
		}

		result = bitwiseSum(a, b);

		if (res_comp1) {
			result = bitwiseSum(result, 1);
		}

		return result;
	}
};
