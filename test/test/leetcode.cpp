#include "leetcode.h"
#include <math.h>
#include <map>
#include <unordered_map>
#include <stack>
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
string Solution::intToRoman(int num){
	char* str[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }
	};

	string val = "";
	val += str[3][num / 1000 % 10];
	val += str[2][num / 100 % 10];
	val += str[1][num / 10 % 10];
	val += str[0][num % 10];

	return val;
}
int Solution::romanToInt(string s){
	int tmp = 0, right = 0, left = 0;
	for (auto c = s.rbegin(); c != s.rend(); c++){
		switch (*c){
		case 'I':
			left = 1; 
			break;
		case 'V':
			left = 5;
			break;
		case 'X':
			left = 10;
			break;
		case 'L':
			left = 50;
			break;
		case 'C':
			left = 100;
			break;
		case 'D':
			left = 500;
			break;
		case 'M':
			left = 1000;
		default:
			break;
		}
		left >= tmp ? right += left : right -= left;
		tmp = left;
	}
	return right;
}
int Solution::numSquares(int n){
	static vector<int> dp{0};

	while (dp.size() <= n){
		int m = dp.size();
		int squares = INT_MAX;
		for (int i = 1; i*i <= m; ++i){
			squares = min(squares, dp[m - i*i] + 1);
		}
		dp.push_back(squares);
	}
	return dp[n];

}
int Solution::countPrimes(int n){
	//vector <bool> prime(n, true);
	bool *prime = new bool[n];
	for (int i = 2; i < n; i++){
		prime[i] = true;
	}
	for (int i = 2; i*i < n; i++){
		if (!prime[i])continue;
		for (int j = i*i; j < n; j += i){
			prime[j] = false;
		}
	}
	int count = 0;
	for (int i = 2; i < n; i++){
		if (prime[i]) count++;
	}

	return count;

}
string commonPrefix(string& pre, string& next){
	int str_size = pre.size() < next.size() ? pre.size() : next.size();

	string commonPre="";
	for (int j = 0; j < str_size; j++){
		if (pre[j] == next[j]){
			commonPre += pre[j];
		}
		else{
			return commonPre;
		}
	}
	return commonPre;
}
string Solution::longestCommonPrefix(vector<string>& strs){
	int strs_size = strs.size();
	string common_str;
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	common_str = strs[0];

	for (int i = 1; i < strs_size; i++){
		common_str = commonPrefix(common_str, strs[i]);
		if (common_str == ""){
			return "";
		}
	}

	return common_str;

}
string Solution::longestCommonPrefixVertical(vector<string>& strs){
	int strs_size = strs.size();
	if (strs.size() == 0)return "";
	string common_str = "";

	for (int i = 0; i < strs[0].size(); i++){
		char c = strs[0][i];
		for (int j = 0; j < strs_size; j++){
			if (i == strs[j].size() || strs[j][i] != c)
				return strs[0].substr(0, i);
		}
	}
	return strs[0];
}
int Solution::strStr(string haystack, string needle){
	int index = -1;
	int haystack_size = haystack.size();
	int needle_size = needle.size();

	if (needle_size == 0) return 0;

	if (haystack_size < needle_size){
		return -1;
	}
	string sub_str;
	for (int i = 0,j=0; i <= haystack_size - needle_size; i++,j=0){
		while (j < needle.size() && haystack[i] == needle[j]){ ++j; ++i; }
		if (j == needle_size) return i - needle_size;
		else i = i - j;
		//sub_str = haystack.substr(i, needle_size);
		//if (sub_str == needle)
		//	return i;
	}
	return -1;
}
bool check(string str, int len){
	if (str.size() % len != 0) return false;
	for (int i = 0; i < str.size()-len; ++i){
		if (str[i] != str[(i + len)])
			return false;
	}
	return true;
}
bool Solution::repeatedSubstringPattern(string str)
{
	if (str.size() <= 1)return false;
	for (int len = 1; len <= str.size() / 2; ++len){
		if (check(str, len)) return true;
	}
	return false;
}
vector<vector<int>> Solution::threeSum(vector<int>& nums){
	vector<vector<int>> result;
	vector<int> local(3, 0);
	if (nums.size() < 3)
		return result;

	sort(nums.begin(), nums.end());

	if (nums[0] > 0 || nums[nums.size() - 1] < 0){
		return result;
	}

	int p1 = 1, p2 = nums.size() - 1;
	for (int i = 0; i < nums.size() - 2;){
		p1 = i + 1;
		p2 = nums.size() - 1;
		while (p1 < p2){
			if (nums[i] + nums[p1] + nums[p2] == 0){
				local[0] = nums[i];
				local[1] = nums[p1];
				local[2] = nums[p2];

				result.push_back(local);

				do{
					--p2;
				} while (p1 < p2 && nums[p2] == nums[p2 + 1]);

				do{
					++p1;
				} while (p1 < p2 && nums[p1] == nums[p1 - 1]);
			}
			else if (nums[i] + nums[p1] + nums[p2] > 0){
				do{
					--p2;
				} while (p1 < p2 && nums[p2] == nums[p2 + 1]);
			}
			else if (nums[i] + nums[p1] + nums[p2] < 0){
				do{
					++p1;
				} while (p1 < p2 && nums[p1] == nums[p1 - 1]);
			}
		}

		do{
			++i;
		} while (i < nums.size() - 2 && nums[i] == nums[i - 1]);
	}

	return result;
}
int Solution::threeSumClosest(vector<int>& nums, int target)
{
	int min_result = INT_MAX;
	int min_closet = INT_MAX;
	vector<int> local(3, 0);
	if (nums.size() < 3)
		return INT_MAX;

	sort(nums.begin(), nums.end());

	int p1 = 1, p2 = nums.size() - 1;
	for (int i = 0; i < nums.size() - 2;){
		p1 = i + 1;
		p2 = nums.size() - 1;
		while (p1 < p2){
			int sum_ = nums[i] + nums[p1] + nums[p2];
			if (sum_ == target){
				min_result = target;
				return min_result;
			}
			else if (sum_ > target){
				int tmp = sum_ - target;
				if (tmp < min_closet){
					min_closet = tmp;
					min_result = sum_;
				}
				do{
					--p2;
				} while (p1 < p2 && nums[p2] == nums[p2 + 1]);
			}
			else if (sum_ < target){
				int tmp = target - sum_;
				if (tmp < min_closet){
					min_closet = tmp;
					min_result = sum_;
				}
				do{
					++p1;
				} while (p1 < p2 && nums[p1] == nums[p1 - 1]);
			}
		}

		do{
			++i;
		} while (i < nums.size() - 2 && nums[i] == nums[i - 1]);
	}

	return min_result;
}
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	vector<int> local(4, 0);
	if (nums.size() < 4)
		return result;

	sort(nums.begin(), nums.end());

	if (nums[0] > 0 || nums[nums.size() - 1] < 0){
		return result;
	}

	int p1 = 1, p2 = nums.size() - 1;
	for (int i = 0; i < nums.size() - 3;){
		for (int j = i + 1; j < nums.size() - 2;){
			p1 = j + 1;
			p2 = nums.size() - 1;
			while (p1 < p2){
				if (nums[i] + nums[j] + nums[p1] + nums[p2] == target){
					local[0] = nums[i];
					local[1] = nums[j];
					local[2] = nums[p1];
					local[3] = nums[p2];

					result.push_back(local);

					do{
						--p2;
					} while (p1 < p2 && nums[p2] == nums[p2 + 1]);
					do{
						++p1;
					} while (p1 < p2 && nums[p1] == nums[p1 - 1]);
				}
				else if (nums[i] + nums[j] + nums[p1] + nums[p2] > target){
					do{
						--p2;
					} while (p1 < p2 && nums[p2] == nums[p2 + 1]);
				}
				else if (nums[i] + nums[j] + nums[p1] + nums[p2] < target){
					do{
						++p1;
					} while (p1 < p2 && nums[p1] == nums[p1 - 1]);
				}
			}
			do{
				++j;
			} while (j < nums.size() - 2 && nums[j] == nums[j - 1]);

		}

		do{
			++i;
		} while (i < nums.size() - 3 && nums[i] == nums[i - 1]);
	}

	return result;

}
bool is_unique(vector<vector<int>>& result, vector<int> & local){
	bool is_un = true;
	for (int i = 0; i < result.size(); i++){
		vector<int> tmp = result[i];
		if (tmp[0] == local[0] && tmp[1] == local[1] && tmp[2] == local[2] && tmp[3] == local[3])
		{
			is_un = false;
			break;
		}
	}
	return is_un;
}
vector<vector<int>> Solution::fourSum_unorderedmap(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	vector<int> local(4, 0);
	if (nums.size() < 4)
		return result;

	sort(nums.begin(), nums.end());

	std::unordered_multimap<int, pair<int, int>> mapped;
	pair<int, int> pair_index;
	int pairsum;
	for (int i = 0; i < nums.size() - 1;i++)
	{
		for (int j = i + 1; j < nums.size();j++)
		{
			pairsum = nums[i] + nums[j];
			pair_index.first = i;
			pair_index.second = j;
			mapped.insert(pair<int, pair<int, int>>(pairsum,pair_index));// [pairsum] = pair_index;
			/*do{
				++j;
			} while (j<nums.size() && nums[j] == nums[j - 1]);*/
		}

		/*do{
			++i;
		} while (i<nums.size() && nums[i] == nums[i - 1]);*/

	}
	int preKey = INT_MAX;
	for (auto p : mapped){
		int keyA = p.first;

		if (preKey == keyA)
			continue;

		auto iterA = mapped.equal_range(keyA);
		int keyB = target - keyA;
		auto iterB = mapped.equal_range(keyB);
		for (auto ka = iterA.first; ka != iterA.second; ka++){
			int index0 = ka->second.first;
			int index1 = ka->second.second;
			for (auto kb = iterB.first; kb != iterB.second; kb++){
				if (kb != mapped.end()){
					int index2 = kb->second.first;
					int index3 = kb->second.second;

					if (index0 != index2 && index0 != index3 && index1 != index2 && index1 != index3){
						local[0] = nums[index0];
						local[1] = nums[index1];
						local[2] = nums[index2];
						local[3] = nums[index3];
						sort(local.begin(), local.end());

						bool isUN = is_unique(result, local);
						if (isUN)
							result.push_back(local);
					}

				}
			}
		}
	

		preKey = keyA;
	}

	return result;
}
vector<string> Solution::letterCombinations(string digits)
{
	vector<string> res;
	vector<string> preres;

	if (digits.size() == 0){
		res.resize(0);
		return res;
	}

	map<int,string> num_to_string;
	num_to_string.insert(pair<char, string>('2', "abc"));
	num_to_string.insert(pair<char, string>('3', "def"));
	num_to_string.insert(pair<char, string>('4', "ghi"));
	num_to_string.insert(pair<char, string>('5', "jkl"));
	num_to_string.insert(pair<char, string>('6', "mno"));
	num_to_string.insert(pair<char, string>('7', "pqrs"));
	num_to_string.insert(pair<char, string>('8', "tuv"));
	num_to_string.insert(pair<char, string>('9', "wxyz"));

	res.push_back("");

	for (int i = 0; i < digits.size(); i++){
		string tmp = num_to_string[digits[i]];
		for (auto c : res){
			for (int j = 0; j < tmp.size(); j++){
				preres.push_back(c + tmp[j]);
			}
		}

		res = preres;
		preres.resize(0);
	}
	return res;
}
void back(int begin, string digits, string comb, vector<string>& solution, vector<string>& letters){
	if (begin == digits.size()){
		solution.push_back(comb);
		return;
	}

	for (int i = 0; i < letters[digits[begin] - '2'].size(); i++){
		comb[begin] = letters[digits[begin] - '2'][i];
		back(begin + 1, digits, comb, solution, letters);
	}
}
vector<string> Solution::letterCombinations_backtracking(string digits){
	if (!digits.size()){ vector<string> a; return a;}

	vector<string> letters = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string comb(digits.size(), 0);
	vector<string> solution;
	back(0, digits, comb, solution, letters);
	return solution;
}

//map
int Solution::fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> mp;
	int count = 0;
	int i, j;
	for (i = 0; i < A.size(); i++)
		for (j = 0; j < B.size(); j++){
		    mp[A[i] + B[j]]++;
		}

	for (i = 0; i < C.size(); i++)
		for (j = 0; j < D.size(); j++){
		if (mp.find(-(C[i] + D[j])) != mp.end()){
			count += mp[-(C[i] + D[j])];
		}
	}
	return count;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	ListNode* p1, *p2;
	p1 = p2 = head;
	while (p2 && n){
		n--;
		p2 = p2->next;
	}

	if (!p2){
		p1 = head;
		head = head->next;
		return head;
		//free(p1);
	}

	while (p2->next){
		p1 = p1->next;
		p2 = p2->next;
	}

	ListNode * p = p1->next;
	p1->next = p->next;
	p->next = NULL;
	//delete p;
	//free(p);
	return head;
}

ListNode* Solution::reverseList(ListNode* head) 
{
	ListNode* pre = NULL, *next = NULL;
	while (head){
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	head = pre;
	return head;
}

ListNode* Solution::reverseList_recursive(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;
	ListNode* p = reverseList_recursive(head->next);

	head->next->next = head;
	head->next = NULL;
	return p;
}

ListNode* Solution::reverseBetween(ListNode* head, int m, int n)
{
	ListNode* *pre = &head,*next;
	int steps = m;
	while (--steps){ pre = &(*pre)->next; }
	ListNode* cur = *pre;
	for (int i = m; i < n; i++){
		next = cur->next;
		cur->next = next->next;
		next->next = *pre;
		*pre = next;
	}
	return head;
}
ListNode* Solution::removeElements(ListNode* head, int val)
{
	if (!head)return head;
	ListNode dummy(0);
	dummy.next = head;

	ListNode* pre = & dummy, *cur= head;

	while (cur){
		if (cur->val != val)
		{
			pre = cur;
			cur = cur->next;
		}
		else{
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		}
	}
	return dummy.next;
}

int Solution::removeElement(vector<int>& nums, int val){
	int len = nums.size();
	for (int i = 0; i < len; i++){
		while (nums[i] == val){
			len = len - 1;
			if (len != i){
				nums[i] = nums[len];
			}
			else{
				break;
			}
		}
	}
	return len;
}

int Solution::removeDuplicates(vector<int>& nums){
	if (nums.size() == 0) return 0;
	int i = 0;
	for (int j = 1; j < nums.size(); j++) {
		if (nums[j] != nums[i]) {
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}

int Solution::uniquePaths_recursive(int m, int n){
	if (m == 0 || n == 0)return 0;
	if (m == 1 && n == 1) return 1;
	if (m == 1 && n == 2)return 1;
	if (m == 2 && n == 1) return 1;
	return uniquePaths_recursive(m - 1, n) + uniquePaths_recursive(m, n - 1);
}

int Solution::uniquePaths(int m, int n){
	int **matrix = new int*[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];

	for (int i = 0; i < m; i++)
		matrix[i][0] = 1;

	for (int i = 0; i < n; i++)
		matrix[0][i] = 1;

	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
			matrix[j][i] = matrix[j - 1][i] + matrix[j][i - 1];

	return matrix[m - 1][n - 1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	int **matrix = new int*[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];

	int endm = m;
	for (int i = 0; i < m; i++){
		if (obstacleGrid[i][0] == 1)
		{
			endm = i;
			break;
		}
	}
		

	for (int i = 0; i < endm; i++)
		matrix[i][0] = 1;

	for (int i = endm; i < m; i++)
		matrix[i][0] = 0;

	int endn = n;
	for (int i = 0; i < n; i++)
	{
		if (obstacleGrid[0][i] == 1){
			endn = i;
			break;
		}
	}
		

	for (int i = 0; i < endn; i++)
		matrix[0][i] = 1;

	for (int i = endn; i < n; i++)
		matrix[0][i] = 0;

	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
		if (obstacleGrid[j][i] == 1)
			matrix[j][i] = 0;
		else
			matrix[j][i] = matrix[j - 1][i] + matrix[j][i - 1];
		}
	return matrix[m - 1][n - 1];
}

int Solution::maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
	if (m == 0) return 0;
	int n = matrix[0].size();
	if (n == 0)return 0;

	int maxsize = 0;
	vector<vector<int>> size(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		size[i][0] = matrix[i][0]-'0';
		maxsize = max(maxsize, size[i][0]);
	}

	for (int i = 0; i < n; i++)
	{
		size[0][i] = matrix[0][i]-'0';
		maxsize = max(maxsize, size[0][i]);
	}

	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
		if (matrix[j][i] == '1')
		{
			size[j][i] = min(size[j - 1][i], min(size[j][i - 1], size[j - 1][i - 1])) + 1;
			maxsize = max(maxsize, size[j][i]);
		}
		}

	return maxsize*maxsize;

}

//1.if the character is opening parenthesis, push it onto the stack
//2.if the character is a closing parenthesis:
     // if the stack is nonempty,and the current character matches the character on top of the stack, remove the character from the top of the stack
     // otherwise, the string is not matched
//ignore all other characters
bool Solution::isValid(string s)
{
	stack<char> pare_stack;
	for (auto c : s){
		if (c == '{' || c == '[' || c == '(')
			pare_stack.push(c);
		else
		{
			if (!pare_stack.empty()){
				char c_t = pare_stack.top();
				switch (c)
				{
				case '}':
					if (c_t == '{')
					{
						pare_stack.pop();
						continue;
					}
					else{
						return false;
					}
				case ']':
					if (c_t == '[')
					{
						pare_stack.pop();
						continue;
					}
					else{
						return false;
					}
				case ')':
					if (c_t == '(')
					{
						pare_stack.pop();
						continue;
					}
					else
						return false;
				default:
					return false;
				}
			}
			else{
				return false;
			}
		}
	}

	if (pare_stack.empty())
		return true;
	else
		return false;
}

void combine(vector<string> & result, string tmp, int i, int j)
{
	if (i == 0 && j == 0){
		result.push_back(tmp);
		return;
	}
	if (i > 0)
		combine(result, tmp + '(', i - 1, j);
	if (j > 0 && i < j)
		combine(result, tmp + ')', i, j - 1);
}
//backtracing
vector<string> Solution::generateParenthesis(int n)
{
	vector<string> result;
	combine(result, "", n, n);
	return result;
}

void depthSearch(int left, vector<int>& c, int index, vector<vector<int>> & ans,vector<int> & tmp)
{
	if (left == 0){
		ans.push_back(tmp);
		return;
	}

	for (int i = index; i < c.size(); i++){
		if (left < c[i])break;
		tmp.push_back(c[i]);
		depthSearch(left - c[i], c, i, ans, tmp);
		tmp.pop_back();
	}
}
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	sort(candidates.begin(), candidates.end());
	depthSearch(target, candidates, 0, ans, tmp);

	return ans;
}

void depthSearch2(int left, vector<int>& c, int index, vector<vector<int>> & ans, vector<int> & tmp)
{
	if (left == 0){
		ans.push_back(tmp);
		return;
	}
	for (int i = index; i < c.size();){
		if (left < c[i])break;
		tmp.push_back(c[i]);
		depthSearch2(left - c[i], c, i+1, ans, tmp);
		tmp.pop_back();
		i++;
		while (c[i] == c[i - 1])i++;
	}
}
vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	sort(candidates.begin(), candidates.end());
	depthSearch2(target, candidates, 0, ans, tmp);

	return ans;
}

void perm(vector<int>& nums, int index, vector<vector<int>>& result)
{
	if (index == nums.size()){
		result.push_back(nums);
		return;
	}

	for (int j = index; j < nums.size(); j++){
		swap(nums[index], nums[j]);
		perm(nums, index + 1, result);
		swap(nums[j], nums[index]);
	}
}
vector<vector<int>> Solution::permute(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> tmp;
	perm(nums, 0, result);
	return result;
}

vector<vector<int>> Solution::permute_2(vector<int>& nums)
{
	vector<vector<int>> permu;
	sort(nums.begin(), nums.end());
	permu.push_back(nums);
	while (next_permutation(nums.begin(),nums.end()))
	{
		permu.push_back(nums);
	}
	return permu;

}

void move(vector<int> & num, int j, int i)
{
	num.insert(num.begin() + i + (i > j), num[j]);
	num.erase(num.begin() + j + (j > i));
}
void perm2(vector<int>& nums, int index, vector<vector<int>>& result)
{
	if (index == nums.size()-1){
		result.push_back(nums);
		return;
	}

	for (int j = index; j < nums.size(); j++){
		if (j != index && nums[j] == nums[j-1]) continue;
		move(nums,j,index);
		perm2(nums, index + 1, result);
		move(nums, index,j);
	}
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> tmp;
	sort(nums.begin(), nums.end());
	perm2(nums, 0, result);
	return result;
}

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (!l1)return l2;
	if (!l2)return l1;

	ListNode* p1 = l1, *p2 = l2, *head = new ListNode(0),*tmp = head;

	while (p1 && p2){
		if (p1->val <= p2->val){
			tmp->next = p1;
			tmp = tmp->next;
			p1 = p1->next;
		}
		else{
			tmp->next = p2;
			tmp = tmp->next;
			p2 = p2->next;
		}
	}

	if (p1) tmp->next = p1;
	if (p2) tmp->next =p2;

	p1 = head;
	head = head->next;
	delete p1;
	return head;
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int p1 = m - 1, p2 = n - 1, i = m + n - 1;
	while (p1 >= 0 && p2 >= 0)nums1[i--] = nums2[p2] >= nums1[p1] ? nums2[p2--] : nums1[p1--];

	for (int k = p1; k >= 0; k--)nums1[i--] = nums1[k];
	for (int k = p2; k >= 0; k--)nums1[i--] = nums2[k];
}

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());

	int num_subset = pow(2, n);
	vector<vector<int>> subset(num_subset, vector<int>());

	for (int i = 0; i < n; i++)
		for (int j = 0; j < num_subset; j++)
		{
		if ((j >> i) & 1){
			subset[j].push_back(nums[i]);
		}
		}
	return subset;
}

ListNode* Solution::swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL){
		return head;
	}

	ListNode* dummy_head = new ListNode(0);
	dummy_head->next = head;

	ListNode* p1, *p2,*pre;
	pre = dummy_head;
	p1 = dummy_head->next;
	p2 = dummy_head->next->next;
	while (1){
		p1->next = p2->next;
		p2->next = p1;
		pre->next = p2;

		pre = p1;
		if (p1->next == NULL || p1->next->next == NULL)
			break;
		p1 = p1->next;
		p2 = p1->next;	
	}
	head = dummy_head->next;
	delete dummy_head;
	return head;
}

int Solution::divide(int dividend, int divisor)
{
	if (!divisor || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long dvd = labs(dividend);
	long long dvs = labs(divisor);

	int res = 0;
	while (dvd >= dvs){
		long long temp = dvs, multiple = 1;
		while (dvd >= (temp << 1)){
			temp <<= 1;
			multiple <<= 1;
		}
		dvd -= temp;
		res += multiple;
	}
	return sign == 1 ? res : -res;
}

void Solution::nextPermutation(vector<int> & nums)
{
	int k = -1;
	for (int i = nums.size() - 2; i >= 0; i--){
		if (nums[i] < nums[i + 1]){
			k = i;
			break;
		}
	}

	if (k == -1)
	{
		reverse(nums.begin(), nums.end());
		return;
	}

	int l = -1;
	for (int i = nums.size() - 1; i > k; i--)
	{
		if (nums[i]>nums[k])
		{
			l = i;
			break;
		}
	}
	swap(nums[k], nums[l]);
	reverse(nums.begin() + k + 1, nums.end());
}

/*
clockwise rotate
first reverse up to down, the swap the symmetry
* 1 2 3     7 8 9     7 4 1
* 4 5 6  => 4 5 6  => 8 5 2
* 7 8 9     1 2 3     9 6 3
*/
void Solution::rotate(vector<vector<int>> & matrix)
{
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = i + 1; j < matrix[i].size(); ++j){
		    swap(matrix[i][j], matrix[j][i]);
		}
}

/*The basic idea is that we iterate through the input array and mark elements as negative using nums[nums[i] - 1] = -nums[nums[i] - 1].
In this way all the numbers that we have seen will be marked as negative.
In the second iteration, if a value is not marked as negative, it implies we have never seen that index before, so just add it to the return list.*/

vector<int> Solution::findDisappearedNumbers(vector<int>& nums)
{
	int n = nums.size();
	vector<int> result(0);
	for (int i = 0; i < n; i++)
	{
		int index = abs(nums[i]) - 1;
		if (nums[index] >= 1)
		{
			nums[index] = -nums[index];
		}
	}

	for (int i = 0; i < n; i++){
		if (nums[i] >= 1){
			result.push_back(i + 1);
		}
	}
	return result;
}
// when find a number i, flip the number at position i-1 to negative. 
// if the number at position i-1 is already negative, i is the number that occurs twice.
vector<int> Solution::findDuplicates(vector<int>& nums)
{
	int n = nums.size();
	vector<int> result(0);
	for (int i = 0; i < n; i++)
	{
		int index = abs(nums[i]) - 1;
		if (nums[index] >= 1){
			nums[index] = -nums[index];
		}
		else if (nums[index] <= -1)
		{
			result.push_back(abs(nums[i]));
		}
	}
	return result;
}


//I traverse right and increment rowBegin, then traverse down and decrement colEnd, 
//then I traverse left and decrement rowEnd, and finally I traverse up and increment colBegin.
//The only tricky part is that when I traverse left or up I have to check whether the row or col still exists to prevent duplicates.
//If anyone can do the same thing without that check, please let me know!
vector<int> Solution::spiralOrder(vector<vector<int>> & matrix)
{
	vector<int> res(0);
	if (matrix.size() == 0)
		return res;
	int rowBegin = 0;
	int rowEnd = matrix.size() - 1;
	int colBegin = 0;
	int colEnd = matrix[0].size() - 1;

	while (rowBegin <= rowEnd && colBegin <= colEnd)
	{
		//traverse right
		for (int j = colBegin; j <= colEnd; j++)
		{
			res.push_back(matrix[rowBegin][j]);
		}
		rowBegin++;

		//traverse down
		for (int j = rowBegin; j <= rowEnd; j++){
			res.push_back(matrix[j][colEnd]);
		}
		colEnd--;

		if (rowBegin <= rowEnd){
			//traverse left
			for (int j = colEnd; j >= colBegin; j--){
				res.push_back(matrix[rowEnd][j]);
			}
		}

		rowEnd--;

		//traverse up
		if (colBegin <= colEnd){
			for (int j = rowEnd; j >= rowBegin; j--){
				res.push_back(matrix[j][colBegin]);
			}
		}	
		colBegin++;
	}
	return res;
}

vector<vector<int>> Solution::generateMatrix(int n)
{
	vector<vector<int>> matrix(n);

	if (n == 0)
		return matrix;
	for (int i = 0; i < n; i++)
		matrix[i].resize(n);

	//int square = n* n;
	int value = 1;

	int rowBegin = 0;
	int rowEnd = n - 1;
	int colBegin = 0;
	int colEnd = n - 1;

	while (rowBegin <= rowEnd && colBegin <= colEnd)
	{
		//traverse right
		for (int j = colBegin; j <= colEnd; j++)
		{
			matrix[rowBegin][j] = value++;
		}
		rowBegin++;

		//traverse down
		for (int j = rowBegin; j <= rowEnd; j++){
			matrix[j][colEnd] = value++;
		}
		colEnd--;

		if (rowBegin <= rowEnd){
			//traverse left
			for (int j = colEnd; j >= colBegin; j--){
				matrix[rowEnd][j] = value++;
			}
		}

		rowEnd--;

		//traverse up
		if (colBegin <= colEnd){
			for (int j = rowEnd; j >= rowBegin; j--){
				matrix[j][colBegin] = value++;
			}
		}
		colBegin++;
	}

	return matrix;

}

vector<int> Solution::plusOne(vector<int>& digits)
{
	int n = digits.size();
	for (int i = n-1; i >= 0; i--){
		if (digits[i] < 9){
			digits[i] ++;
			return digits;
		}

		digits[i] = 0;
	}

	digits[0] = 1;
	digits.push_back(0);
	return digits;
}

string Solution::multiply(string num1, string num2)
{
	string sum(num1.size() + num2.size(), '0');

	for (int i = num1.size() - 1; 0 <= i; --i) {
		int carry = 0;
		for (int j = num2.size() - 1; 0 <= j; --j) {
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] += carry;
	}

	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos) {
		return sum.substr(startpos);
	}
	return "0";
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	int n = matrix.size();
	int m = matrix[0].size();
	int l = 0, r = m * n - 1;
	while (l != r){
		int mid = (l + r - 1) >> 1;
		if (matrix[mid / m][mid % m] < target)
			l = mid + 1;
		else
			r = mid;
	}
	return matrix[r / m][r % m] == target;
}