/*
 * 
 * 孙悟空爱吃蟠桃，有一天趁着蟠桃园守卫不在来偷吃。
已知蟠桃园有N课桃树， 每棵树上都有桃子，天兵天将将在H小时后回来。
孙悟空可以决定他吃蟠桃的速度K（个/小时），每个小时选一棵桃树，从中吃掉K个，
如果树上的桃子少于K个，则全部吃掉，在这一小时剩余的时间里不再吃桃。
孙悟空喜欢慢慢吃，但又想在天兵天将回来前吃完所有桃子
求最小的K

输入
从标准输入读取一行数字， 前面数字表示每棵树上蟠桃个数，最后一个数字表示天兵天将离开的时间。

输出
吃掉所有桃子的最小速度K（整数），无解或输入异常时输出-1
 * */
#include <iostream>
#include <vector>
using namespace std;

int cost_hour_for_k(vector<int> trees, int k) {
	int total_hour = 0;

	for (auto it = trees.begin(); it != trees.end(); ++it) {
		total_hour += *it / k;
		if (*it % k > 0)
			total_hour++;
	}
	return total_hour;
}

int leastK(vector<int> trees, int max, int limit) {
#if 0
	int k = 1;
	int num = trees.size();
	if (num > limit) {
		return -1;
	}
	if (num == limit) {
		return max;
	}
	for (; k <= max; k++) {
		if (cost_hour_for_k(trees, k) <= limit) {
			return k;
		}
	}
	return -1;
#else
	// O(nlog(max))
	int k = 1;
	int min = 1;
	int num = trees.size();
	int cost_hour = 0;
	int result = -1;
	if (num > limit) {
		return -1;
	}
	if (num == limit) {
		return max;
	}
	while(1) {
		k = (min + max) / 2;
		if (min == k) {
			break;
		}
		cost_hour = cost_hour_for_k(trees, k);
		if (cost_hour == limit) {
			return k;
		}
		else if (cost_hour > limit) {
			min = k;
		}
		else if (cost_hour < limit) {
			max = k;
			result = k;
		}
	}
	return result;
#endif
}

int main () {
	vector<int> input;
	int max = 0;
	int tmp = 0;
	int limit_hour = 0;
	int length = 0;
	int k = 0;
	while (cin >> tmp) {
		input.push_back(tmp);
		if (cin.get() == '\n') {
			break;
		}
	}

	// last input is the limit hour
	limit_hour = input.back();

	input.pop_back();
	length = input.size();
	for (auto it = input.begin(); it != input.end(); ++it) {
		if (*it > max)
			max = *it;
	}
	k = leastK(input, max, limit_hour);
	cout << k << endl;
	return 0;
}


