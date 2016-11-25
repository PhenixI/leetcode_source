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

	//15.3Sum
	//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
	//For example, given array S = [-1, 0, 1, 2, -1, -4],
	//	A solution set is :
	//[
	//	[-1, 0, 1],
	//	[-1, -1, 2]
	//]

	vector<vector<int>> threeSum(vector<int>& nums);

	//16.3Sum Closest
	//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
	//Return the sum of the three integers.
	//You may assume that each input would have exactly one solution.
	int threeSumClosest(vector<int>& nums, int target);

	//17. Letter Combinations of a Phone Number
	//Given a digit string, return all possible letter combinations that the number could represent.
    //Input:Digit string "23"
    //Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	vector<string> letterCombinations(string digits);
	vector<string> letterCombinations_backtracking(string digits);

	//18.4Sum
	//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
	//Find all unique quadruplets in the array which gives the sum of target.
	vector<vector<int>> fourSum(vector<int>& nums, int target);
	vector<vector<int>> fourSum_unorderedmap(vector<int>& nums, int target);

	//19.Remove Nth Node From End of List
	//Given a linked list, remove the nth node from the end of list and return its head.
	ListNode* removeNthFromEnd(ListNode* head, int n);


	//28.Implement strStr()
	// Implement strStr().
	//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
	int strStr(string haystack, string needle);
	//92.Reverse Linked List II
	/*Reverse a linked list from position m to n.Do it in - place and in one - pass.
	For example :
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 	return 1->4->3->2->5->NULL.*/
	ListNode* reverseBetween(ListNode* head, int m, int n);


	//125. Valid Palindrome
	/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

	For example,
	"A man, a plan, a canal: Panama" is a palindrome.
	"race a car" is not a palindrome.*/
	bool isPalindrome(string s);

	//204.Count Primes
	//Count the number of prime numbers less than a non - negative number, n.
	int countPrimes(int n);

	//206.Reverse Linked List
	//Reverse a gingly linked list
	ListNode* reverseList(ListNode* head);
	ListNode* reverseList_recursive(ListNode* head);

	//234. Palindrome Linked List
	//Given a singly linked list, determine if it is a palindrome.
	bool isPalindrome(ListNode* head);

	//279. Perfect Squares
	//Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
	//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
	int numSquares(int n);
	//454.4SUM II
	/*
	Given four lists A, B, C, D of integer values, compute how many tuples(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
	To make problem a bit easier, all A, B, C, D have same length of N where 0 ¡Ü N ¡Ü 500. All integers are in the range of - 228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
	*/
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);

	//459. Repeated Substring Pattern
	//Given a non - empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
	//You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
	bool repeatedSubstringPattern(string str);
};

//#include "leetcode.cpp"

#endif