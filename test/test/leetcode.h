#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include <queue>
#include <string>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

	//7. Reverse Integer

	//Reverse digits of an integer.

	//Example1 : x = 123, return 321
	//Example2 : x = -123, return -321
	int reverse1(int x);
	int reverse2(int x);

	//8. String to Integer(atoi)
	//Implement atoi to convert a string to an integer.
	int myAtoi(std::string str);
	int myAtoi2(std::string str);

	//9. Palindrome Number
	//Determine whether an integer is a palindrome.Do this without extra space.
	bool isPalindrome(int x);

	//11. Container With Most Water
	//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
	//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).
	//Find two lines, which together with x - axis forms a container, such that the container contains the most water.
	int maxArea(vector<int>& height);

	//12. Integer to Roman
	/*Given an integer, convert it to a roman numeral.
	Input is guaranteed to be within the range from 1 to 3999.*/
	string intToRoman(int num);
	//13. Roman to Integer
	/*Given a roman numeral, convert it to an integer.
	Input is guaranteed to be within the range from 1 to 3999.*/
	int romanToInt(string s);

	//14. Longest Common Prefix
	//Write a function to find the longest common prefix string amongst an array of strings.
	string longestCommonPrefix(vector<string>& strs);
	string longestCommonPrefixVertical(vector<string>& strs);

	//28.Implement strStr()
	// Implement strStr().
	//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
	int strStr(string haystack, string needle);


	//125. Valid Palindrome
	/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

	For example,
	"A man, a plan, a canal: Panama" is a palindrome.
	"race a car" is not a palindrome.*/
	bool isPalindrome(string s);

	//204.Count Primes
	//Count the number of prime numbers less than a non - negative number, n.
	int countPrimes(int n);


	//234. Palindrome Linked List
	//Given a singly linked list, determine if it is a palindrome.
	bool isPalindrome(ListNode* head);

	//279. Perfect Squares
	//Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
	//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
	int numSquares(int n);
};

//#include "leetcode.cpp"

#endif