#include <iostream>
#include <algorithm>
using namespace std;

void f(int left, int right, int arr[]) {
	if (left >= right)return;
	int p_right = right;
	int p_left = left;

	int pivot = arr[(left + right) / 2];

	while (p_left <= p_right) {
		while (arr[p_left] < pivot) { p_left++; }
		while (pivot < arr[p_right]) { p_right--; }
		if (p_left <= p_right) {
			swap(arr[p_left], arr[p_right]);
			p_left++; p_right--;
		}
	}
	f(left, p_right, arr);
	f(p_left, right, arr);
}

int main() {
	int arr[] = { 5,1,6,3,4,2,7 };
	f(0, 6, arr);

	for (int i = 0; i <= 6; i++)
	{
		cout << arr[i] << " ";
	}
}