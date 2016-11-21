#include "leetcode_test.h"
#include <iostream>
//7.
void Solution_Test::test_reverse1(){
	int x = 123;
	int y = solution.reverse1(x);

	printf("y:%d\n", y);
	x = -123;
	y = solution.reverse1(x);

	printf("y:%d\n", y);

	x = 1534236469;
	y = solution.reverse1(x);
	printf("y:%d\n", y);

}

void Solution_Test::test_reverse2(){
	int x = 123;
	int y = solution.reverse2(x);

	printf("y:%d\n", y);
	x = -123;
	y = solution.reverse2(x);

	printf("y:%d\n", y);

	x = 1534236469;
	y = solution.reverse2(x);
	printf("y:%d\n", y);

}

void Solution_Test::test_myAtoi(){
	int x = solution.myAtoi("-1");

	printf("%d\n", x);

	x = solution.myAtoi("1");

	printf("%d\n", x);

	x = solution.myAtoi("010");

	printf("%d\n", x);

	x = solution.myAtoi("   010");

	printf("%d\n", x);

	x = solution.myAtoi("   -0010ab");

	printf("%d\n", x);

	x = solution.myAtoi("-2147483648");

	printf("%d\n", x);

	x = solution.myAtoi("2147483648");

	printf("%d\n", x);

	x = solution.myAtoi("   -1123u3761867");

	printf("%d\n", x);
}

void Solution_Test::test_myAtoi2(){
	int x = solution.myAtoi2("-1");

	printf("%d\n", x);

	x = solution.myAtoi2("1");

	printf("%d\n", x);

	x = solution.myAtoi2("010");

	printf("%d\n", x);

	x = solution.myAtoi2("   010");

	printf("%d\n", x);

	x = solution.myAtoi2("   -0010ab");

	printf("%d\n", x);

	x = solution.myAtoi2("-2147483648");

	printf("%d\n", x);

	x = solution.myAtoi2("2147483648");

	printf("%d\n", x);

	x = solution.myAtoi2("   -1123u3761867");

	printf("%d\n", x);
}

void Solution_Test::test_isPalindrome(){

	int x = 10;

	printf("%d \n", solution.isPalindrome(x));

	 x = 787;

	printf("%d \n", solution.isPalindrome(x));

	x = -2147483648;

	printf("%d \n", solution.isPalindrome(x));

}

void Solution_Test::test_list_isPalindrome(){
	ListNode a(10);
	ListNode b(8);
	ListNode c(10);

	a.next = &b;
	b.next = &c;

	printf("%d \n", solution.isPalindrome(&a));

	printf("%d \n", solution.isPalindrome((ListNode*)NULL));
}

void Solution_Test::test_string_isPalindrome(){
	string s = "A man, a plan, a canal: Panama";
	printf("%d \n", solution.isPalindrome(s));

	s = "race a car";
	printf("%d \n", solution.isPalindrome(s));

	s = "!!!";
	printf("%d \n", solution.isPalindrome(s));
}

void Solution_Test::test_maxArea(){
	vector<int> a(2);
	a[0] = 1;
	a[1] = 1;
	printf("%d \n", solution.maxArea(a));

	a.resize(3);
	for (int i = 0; i < 3; i++){
		a[i] = i+1;
	}

	printf("%d \n", solution.maxArea(a));

	a.resize(7);
	a[0] = 2; a[1] = 3;
	a[2] = 4; a[3] = 5;
	a[4] = 18; a[5] = 17;
	a[6] = 6;

	printf("%d \n", solution.maxArea(a));
}

void Solution_Test::test_numSquares(){
	int n = 12;
	printf("n: %d\n", solution.numSquares(n));

	n = 13;
	printf("n: %d\n", solution.numSquares(n));
}

void Solution_Test::test_countPrimes(){
	int n = 13;
	printf("num of prime: %d\n", solution.countPrimes(n));

	n = 101;
	printf("num of prime: %d\n", solution.countPrimes(n));
}

void Solution_Test::test_longestCommonPrefix(){
	string str = "abab";
	string str1 = "aba";
	string str2 = "abc";
	vector<string> strs;
	strs.push_back(str);
	strs.push_back(str1);
	strs.push_back(str2);
	//std::cout << solution.longestCommonPrefix(strs) << endl;
	std::cout << solution.longestCommonPrefixVertical(strs) << endl;
	//printf("common prefix: %s\n", solution.longestCommonPrefix(strs));
}

void Solution_Test::test_strStr(){
	string str_hay = "abcdef";
	string str_needle = "de";

	std::cout << solution.strStr(str_hay, str_needle) << endl;
}