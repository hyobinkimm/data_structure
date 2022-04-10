#include <iostream>
#include <ctime>
using namespace std;

void max_heapify(int a[], int h, int m) { // 배열 / root / 크기
	// parent node가 child node보다 커야 하는 maxheap
	// 결론적으로 내림차순으로 정렬됨
	int v = a[h]; // 일단 keep
	int j = 0;
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && a[j] < a[j + 1]) {
			j = j + 1; 
		}
		// j는 값이 큰 자식 노드
		if (v >= a[j]) break; // arr[j]가 v에 해당하는 값보다 더 큼
		else a[j / 2] = a[j]; // a[j]를 부모 노드로 이동(더 크므로)
	}
	a[j / 2] = v; // 바꿔줌
	cout << "max_heapify" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void min_heapify(int a[], int h, int m) {
	// parent node가 child node보다 작아야 하는 minheap
	// 결론적으로 오름차순으로 정렬됨
	int v = a[h];
	int j = 0;
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && a[j] > a[j + 1]) {
			j++;
		}
		if (v <= a[j])break;
		else a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void max_heap_sort(int a[], int size) {
	int n = size - 1;
	// a[0]를 사용하지 않기 때문에 모든 i는 1까지 돌아감

	for (int i = n / 2; i >= 1; i--) {
		max_heapify(a, i, n); // maxheap 성질에 맞게 데이터를 바꿔줌 (부모>자식)
		// 근데 완벽하게 되진 않음. 맨마지막이 정렬 안됨.
	}

	for (int i = 1; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i >= 1; i--) { // 오름차순 정렬
		// 맨 마지막에 있는 원소를 맨 위로 옮긴 다음 heapify, 범위는 (1,10), (1,9), (1,8) ,,, 순으로 점점 정렬완료 - 뒤에서 부터 큰 순서대로 정렬이 된다
		int temp = a[1]; 
		a[1] = a[i + 1];
		a[i + 1] = temp;
		max_heapify(a, 1, i);
	}
}
void min_heap_sort(int a[], int size) {
	int n = size - 1;

	for (int i = n / 2; i >= 1; i--) {
		min_heapify(a, i, n); // minheap 성질에 맞게 데이터를 바꿔줌
	}

	for (int i = n - 1; i >= 1; i--) { // 내림차순 정렬
		int temp = a[1]; // minheap으로 인해 a[1]이 가장 작은 원소
		a[1] = a[i + 1];
		a[i + 1] = temp;
		min_heapify(a, 1, i);
	}
}
