#include "leetcode.h"
#include <math.h>
//7
int Solution::reverse1(int x) {

	int x_tmp = x<0? -x:x;
	std::queue<int> ori;
	while (x_tmp > 0){
		ori.push(x_tmp % 10);
		x_tmp = x_tmp / 10;
	}

	long long y = 0;
	int y_tmp = 0;
	while (!ori.empty()){
		y_tmp = ori.front();
		ori.pop();
		y = y * 10 + y_tmp;
	}

	if (y > INT_MAX){
		y = 0;
	}
	if (x < 0){
		y = -y;
	}
	return y;
}

int Solution::reverse2(int x) {

	long long res = 0;
	while (x){
		res = res * 10 + x % 10;
		x /= 10;
	}
	
	return ((res<INT_MIN || res>INT_MAX)?0:res);
}

int convertToi(std::string str,bool is_pos){
	//if (str.length() >= 11){
	//	return 0;
	//}

	int n = 0;
	long long res = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			res = res * 10 + str[i]-'0';
			n++;
			if (n >= 11)
				break;

		}
		else{
			break;
		}
	}

	if (is_pos)
		return res > INT_MAX ? INT_MAX : res;
	else
		return (-res < INT_MIN) ? INT_MIN : -res;

}
//1.discards as many whitespace characters as necessary 
//2.takes an optional initial plus or minus sign followed by as many numerical 
//digits as possible.interprets them as a numerical value
//3. non integral number or empty or whitespace only, return 0
//4.overflow: return INT_MAX or INT_MIN
int Solution::myAtoi(std::string str){
	int blankindex = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' '){
			blankindex++;
		}
		else{
			break;
		}
	}
	str = str.substr(blankindex, str.length());
	if (str.length() == 0){
		return 0;
	}
	char sign_item = str[0];
	bool is_pos = false;
	int begin_pos = 0;
	if (sign_item == '-')
	{
		is_pos = false;
		begin_pos = 1;
	}
	else if (sign_item == '+'){
		is_pos = true;
		begin_pos = 1;
	}
	else if (sign_item >= '0' && sign_item <= '9')
	{
		is_pos = true;
		begin_pos = 0;
	}
	else{
		return 0;
	}

	std::string sub_str = str.substr(begin_pos, str.length());
	int x = convertToi(sub_str,is_pos);

	//if (!is_pos)
	//	x = -x;

	return x;
}

int Solution::myAtoi2(std::string str){
	long long result = 0;
	//printf("%d\n",sizeof(long));
	int indicator = 1;
	int i = str.find_first_not_of(' ');
	if (str[i] == '-' || str[i] == '+'){
		indicator = (str[i++] == '-') ? -1 : 1;
	}
	while (isdigit(str[i]) && i<str.size()){
		result = result * 10 + (str[i++] - '0');
		if (result*indicator >= INT_MAX) 
			return INT_MAX;
		if (result*indicator <= INT_MIN) 
			return INT_MIN;
	}
	return indicator * result;
}

bool Solution::isPalindrome(int x){

	if (x < 0)return false;

	int numi = 10;
	int numj = 10;
	if (x / numj == 0){
		return true;
	}
	
	while (x / numj >= 10){
		numj *= 10;
	}

	while (numj >= numi){

		int j = (x / numj) % 10;
		int i = (x % (numi) / (numi/10));
		if (i != j){
			return false;
		}
		else{
			numj /= 10;
			numi *= 10;
		}
	}

	return true;
}
//1.reserve the later half of list
//2.compare from beginning

ListNode* reverseList(ListNode* head){
	ListNode* prev = NULL;
	ListNode* next = NULL;
	while (head){
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}

bool Solution::isPalindrome(ListNode* head){
	ListNode* next1, *next2;
	next1 = head;
	next2 = head;

	if (head == NULL && head->next == NULL)
		return true;
	while ( next2 && next2->next){
		next1 = next1->next;
		next2 = next2->next->next;
	}

	ListNode* p = reverseList(next1);
	ListNode* pre = head;
	while (p && pre){
		if (p->val != pre->val){
			return false;
		}
		else{
			p = p->next;
			pre = pre->next;
		}
	}
	return true;
}

bool Solution::isPalindrome(string s){
	int i = 0;
	int j = s.size()-1;

	while (i <= j){
		while (!isdigit(s[i]) && !isalpha(s[i]) && i<=j){
			i++;
		}
		while (!isdigit(s[j]) && !isalpha(s[j]) && i<=j){
			j--;
		}

		if (i <= j){
			if (tolower(s[i++]) != tolower(s[j--])){
				return false;
			}
		}

		//i++;
		//j--;
	}
	return true;
}
/*
设置两个指针i, j, 一头一尾, 相向而行. 假设i指向的挡板较低, j指向的挡板较高(height[i] < height[j]).
下一步移动哪个指针?
-- 若移动j, 无论height[j-1]是何种高度, 形成的面积都小于之前的面积.
-- 若移动i, 若height[i+1] <= height[i], 面积一定缩小; 但若height[i+1] > height[i], 面积则有可能增大.
综上, 应该移动指向较低挡板的那个指针.
*/
int Solution::maxArea(vector<int>& height){
	if (height.size() == 0)return 0;

	int i = 0;
	int j = height.size() - 1;
	int max_water = 0;
	while (i < j){
		max_water = max(max_water, (j - i)*min(height[i], height[j]));

		if (height[i] < height[j]){
			int k;
			for (k = i + 1; k < j && height[k] <= height[i]; ++k){}
			i = k;
		}
		else{
			int k;
			for (k = j - 1; k > i && height[k] <= height[j]; --k){}
			j = k;
		}
	}

	return max_water;

}
