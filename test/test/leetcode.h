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

	//125. Valid Palindrome
	/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

	For example,
	"A man, a plan, a canal: Panama" is a palindrome.
	"race a car" is not a palindrome.*/
	bool isPalindrome(string s);


	//234. Palindrome Linked List
	//Given a singly linked list, determine if it is a palindrome.
	bool isPalindrome(ListNode* head);
};

//#include "leetcode.cpp"

#endif