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

void Solution_Test::test_repeatedSubstringPattern(){
	string str = "abab";
	std::cout << solution.repeatedSubstringPattern(str) << endl;

	str = "abac";
	std::cout << solution.repeatedSubstringPattern(str) << endl;

	str = "bacbacbac";
	std::cout << solution.repeatedSubstringPattern(str) << endl;

	str = "czmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsvv";
	std::cout << solution.repeatedSubstringPattern(str) << endl;

	str = "abcabcabcabc";
	std::cout << solution.repeatedSubstringPattern(str) << endl;
}

void Solution_Test::test_ThreeSum(){
	vector<int> input;
	input.push_back(-1);
	input.push_back(0);
	input.push_back(1);
	input.push_back(2);
	input.push_back(-1);
	input.push_back(-4);

	vector<vector<int>> result = solution.threeSum(input);

	for (int j = 0; j < result.size(); j++){
		for (int i = 0; i < result[j].size(); i++){
			cout << result[j][i] << ' ';
		}
		cout << endl;
	}
}

void Solution_Test::test_threeSumClosest()
{
	vector<int> vec(4, 0);
	vec[0] = -1;
	vec[1] = 2;
	vec[2] = 1;
	vec[3] = -4;

	cout << solution.threeSumClosest(vec, 1) << endl;
}

void Solution_Test::test_letterCombinations()
{
	string d = "23";
	vector<string> str = solution.letterCombinations(d);
	for (int i = 0; i < str.size(); i++){
		cout << str[i] << endl;
	}

	d = "";
	str = solution.letterCombinations(d);
	for (int i = 0; i < str.size(); i++){
		cout << str[i] << endl;
	}
}

void Solution_Test::test_fourSum(){
	vector<int> input;
	input.push_back(1);
	input.push_back(0);
	input.push_back(-1);
	input.push_back(0);
	input.push_back(-2);
	input.push_back(2);

	//vector<vector<int>> result = solution.fourSum(input,0);
	vector<vector<int>> result = solution.fourSum_unorderedmap(input, 0);

	for (int j = 0; j < result.size(); j++){
		for (int i = 0; i < result[j].size(); i++){
			cout << result[j][i] << ' ';
		}
		cout << endl;
	}

	input.resize(0);
	input.push_back(0);
	input.push_back(0);
	input.push_back(0);
	input.push_back(0);

	//vector<vector<int>> result = solution.fourSum(input,0);
	result = solution.fourSum_unorderedmap(input, 0);

	for (int j = 0; j < result.size(); j++){
		for (int i = 0; i < result[j].size(); i++){
			cout << result[j][i] << ' ';
		}
		cout << endl;
	}
}

void Solution_Test::test_fourSumCount()
{
	vector<int> A, B, C, D;
	A.push_back(1);
	A.push_back(2);
	B.push_back(-2);
	B.push_back(-1);
	C.push_back(-1);
	C.push_back(2);
	D.push_back(0);
	D.push_back(2);

	cout << solution.fourSumCount(A, B, C, D) << endl;

}

void Solution_Test::test_removeNthFromEnd(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode f(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &f;

	ListNode* p = solution.removeNthFromEnd(&a, 2);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}

	ListNode g(1);

	p = solution.removeNthFromEnd(&g, 1);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}
}

void Solution_Test::test_reverseList_iterative()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode f(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &f;

	//ListNode* p = solution.reverseList(&a);
	ListNode* p = solution.reverseList_recursive(&a);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}
}

void Solution_Test::test_reverseBetween()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode f(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &f;

	//ListNode* p = solution.reverseList(&a);
	ListNode* p = solution.reverseBetween(&a,2,4);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}

	ListNode g(5);
	p = solution.reverseBetween(&g, 1, 1);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}
}

void Solution_Test::test_removeElements()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(6);
	ListNode* d = new ListNode(3);
	ListNode* f = new ListNode(4);
	ListNode* g = new ListNode(5);
	ListNode* h = new ListNode(6);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = f;
	f->next = g;
	g->next = h;

	ListNode* p = solution.removeElements(a, 6);
	while (p){
		cout << p->val << ' ';
		p = p->next;
	}

}

void Solution_Test::test_RemoveElement()
{
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(2);
	num.push_back(3);

	int len = solution.removeElement(num, 3);
	for (int i = 0; i < len; i++){
		cout << num[i] << ' ';
	}
	cout << endl;

	num.resize(1);
	num[0] = 1;
	len = solution.removeElement(num, 1);
	for (int i = 0; i < len; i++){
		cout << num[i] << ' ';
	}
	cout << endl;

}

void Solution_Test::test_removeDuplicates()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);

	int len = solution.removeDuplicates(num);
	cout << "len: " << len << endl;
	for (int i = 0; i < len; i++){
		cout << num[i] << ' ';
	}
	cout << endl;
}

void Solution_Test::test_uniquePaths()
{
	int m = 3, n = 7;
	cout << solution.uniquePaths(m, n) << endl;

	m = 23, n = 12;
	cout << solution.uniquePaths(m, n) << endl;
}

void Solution_Test::test_uniquePathsWithObstacles()
{
	vector<vector<int>> a = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	cout << solution.uniquePathsWithObstacles(a);
	cout << endl;
	a[1][1] = 1;
	cout << solution.uniquePathsWithObstacles(a);
	cout << endl;
}

void Solution_Test::test_maximalSquare()
{
	vector<vector<char>> a = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	cout << solution.maximalSquare(a) << endl;
}