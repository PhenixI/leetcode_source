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
	//20.Valid Parentheses
	//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	bool isValid(string s);

	//21. Merge Two Sorted Lists
	//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

	//22.Generate Parentheses
	//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
	//For example, given n = 3, a solution set is :
	//[
	//	"((()))",
	//	"(()())",
	//	"(())()",
	//	"()(())",
	//	"()()()"
	//]

	vector<string> generateParenthesis(int n);

	//24. Swap Nodes in Pairs
	/*Given a linked list, swap every two adjacent nodes and return its head.
	For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.
	Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.*/
	ListNode* swapPairs(ListNode* head);

	//26.Remove Duplicates from Sorted Array
	/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	For example,
	Given input array nums = [1, 1, 2],
	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length. */
	int removeDuplicates(vector<int>& nums);

	//27.Remove Element
	/*Given an array and a value, remove all instances of that value in place and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	The order of elements can be changed.It doesn't matter what you leave beyond the new length.
	Example:
	Given input array nums = [3, 2, 2, 3], val = 3
	Your function should return length = 2, with the first two elements of nums being 2.*/
	int removeElement(vector<int>& nums, int val);


	//28.Implement strStr()
	// Implement strStr().
	//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
	int strStr(string haystack, string needle);

	//29.Divide Two Integers
	/*Divide two integers without using multiplication, division and mod operator.
	If it is overflow, return MAX_INT.*/
	int divide(int dividend, int divisor);

	//39.Combination Sum
	//Given a set of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
	//The same repeated number may be chosen from C unlimited number of times.
	//Note:
	//All numbers(including target) will be positive integers.
	//The solution set must not contain duplicate combinations.
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);

	//40.Combination Sum2
	/*Given a collection of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
	Each number in C may only be used once in the combination.
	Note:
	All numbers(including target) will be positive integers.
	The solution set must not contain duplicate combinations.*/
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

	//46.Permutations
	//Given a collection of distinct numbers, return all possible permutations
	vector<vector<int>> permute(vector<int>& nums);
	vector<vector<int>> permute_2(vector<int>& nums);

	//47.PermutationsII
	//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
	vector<vector<int>> permuteUnique(vector<int>& nums);

	//62.Unique Paths
	/*A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
	  The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
	  How many possible unique paths are there ?
	*/
	int uniquePaths_recursive(int m, int n);
	int uniquePaths(int m, int n);

	//63.Unique Paths
	/*Follow up for "Unique Paths":
	Now consider if some obstacles are added to the grids.How many unique paths would there be ?
	An obstacle and empty space is marked as 1 and 0 respectively in the grid.*/
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	//78.Subsets
	//Given a set of distinct integers, nums, return all possible subsets.
	vector<vector<int>> subsets(vector<int>& nums);

	//88.Merge Sorted Array
	//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
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

	//203 Remove Linked List Elements
	/*
	Remove all elements from a linked list of integers that have value val.
	Example
	Given : 1 -- > 2 -- > 6 -- > 3 -- > 4 -- > 5 -- > 6, val = 6
	Return: 1 -- > 2 -- > 3 -- > 4 -- > 5
	*/
	ListNode* removeElements(ListNode* head, int val);

	//204.Count Primes
	//Count the number of prime numbers less than a non - negative number, n.
	int countPrimes(int n);

	//206.Reverse Linked List
	//Reverse a gingly linked list
	ListNode* reverseList(ListNode* head);
	ListNode* reverseList_recursive(ListNode* head);

	//221
	//Maximal Square
	//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area. 
	int maximalSquare(vector<vector<char>>& matrix);
	
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