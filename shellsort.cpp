#include <iostream>
using namespace std;

void f(int n, int arr[]) {
	int h;
	for (h = 1; h < n; h = 3 * h + 1) {}
	cout << "h : "<<h << endl;
	for (; h > 0; h = h / 3) {
		for (int i = h; i < n; i++) {
			int v = arr[i];
			int j = i;
			while (j >= h && arr[j - h] > v) {
				arr[j] = arr[j - h];
				j -= h;
			}
			arr[j] = v;
		}
	}
}
int main() {
	int arr[] = { 5,1,6,3,4,2,7 };

	f(7, arr);

	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
}