#include <iostream>
#include <ctime>
using namespace std;

void max_checkSort(int a[], int n) {
	bool sorted = true;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i + 1]) {
			sorted = false;
		}
		if (!sorted)break;
	}

	if (sorted) {
		cout << "MaxHeap sorting Complete!" << endl;
	}
	else {
		cout << "정렬 오류!!" << endl;
	}
}
void min_checkSort(int a[], int n) {
	bool sorted = true;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] < a[i + 1]) {
			sorted = false;
		}
		if (!sorted)break;
	}

	if (sorted) {
		cout << "MinHeap sorting Complete!" << endl;
	}
	else {
		cout << "정렬 오류!!" << endl;
	}
}

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
		if (v >= a[j]) break;
		else a[j / 2] = a[j]; // a[j]를 부모 노드로 이동(더 크므로)
	}
	a[j / 2] = v; // 바꿔줌
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
	}

	for (int i = 1; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i >= 1; i--) { // 오름차순 정렬
		int temp = a[1]; // maxheap으로 인해 a[1]이 가장 큰 원소가 되었음
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

void printResult(int a[], int n) {
	
	for (int j = 1; j < n; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
}

int ex1[10001];
int ex2[50001];
int ex3[100001];
int ex4[500001];
int ex5[1000001];

int main() {
	// 문제 1
	int arr[] = {0,6,2,8,1,3,9,4,5,10,7 }; // a[0]는 쓰지 않는다고 했으므로 0으로 설정

	max_heap_sort(arr, 10);
	printf("MaxHeap 정렬 결과\n");
	printResult(arr, 10);
	max_checkSort(arr, 10);
	
	min_heap_sort(arr, 10);
	printf("MinHeap 정렬 결과\n");
	printResult(arr, 10);
	min_checkSort(arr, 10);

	printf("\n\n");

	/*
	// 문제 2
	int n;
	clock_t start, end;
	float t;
	
	n = 10000;
	srand((unsigned)time(NULL));
	for (int i = 1; i < n; i++)
	{
		ex1[i] = rand() % 10001;
	}

	start = clock();
	max_heap_sort(ex1, 10000);
	end = clock();
	max_checkSort(ex1, 10000);
	t = float(end - start);
	printf("Maxheap sorting (N=%d) time cost : %f ms\n", n, t);

	start = clock();
	min_heap_sort(ex1, 10000);
	end = clock();
	min_checkSort(ex1, 10000);
	t = float(end - start);
	printf("Minheap sorting (N=%d) time cost : %f ms\n\n", n, t);


	//
	n = 50000;
	srand((unsigned)time(NULL));
	for (int i = 1; i < n; i++)
	{
		ex2[i] = rand() % 50001;
	}
	start = clock();
	max_heap_sort(ex2, 50000);
	end = clock();
	max_checkSort(ex2, 50000);
	t = float(end - start);
	printf("Maxheap sorting (N=%d) time cost : %f ms\n", n, t);

	start = clock();
	min_heap_sort(ex2, 50000);
	end = clock();
	min_checkSort(ex2, 50000);
	t = float(end - start);
	printf("Minheap sorting (N=%d) time cost : %f ms\n\n", n, t);


	//
	n = 100000;
	srand((unsigned)time(NULL));
	for (int i = 1; i < n; i++)
	{
		ex3[i] = rand() % 100001;
	}
	start = clock();
	max_heap_sort(ex3, 100000);
	end = clock();
	max_checkSort(ex3, 100000);
	t = float(end - start);
	printf("Maxheap sorting (N=%d) time cost : %f ms\n", n, t);

	start = clock();
	min_heap_sort(ex3, 100000);
	end = clock();
	min_checkSort(ex3, 100000);
	t = float(end - start);
	printf("Minheap sorting (N=%d) time cost : %f ms\n\n", n, t);


	//
	n = 500000;
	srand((unsigned)time(NULL));
	for (int i = 1; i < n; i++)
	{
		ex4[i] = rand() % 500001;
	}
	start = clock();
	max_heap_sort(ex4, 500000);
	end = clock();
	max_checkSort(ex4, 500000);
	t = float(end - start);
	printf("Maxheap sorting (N=%d) time cost : %f ms\n", n, t);

	start = clock();
	min_heap_sort(ex4, 500000);
	end = clock();
	min_checkSort(ex4, 500000);
	t = float(end - start);
	printf("Minheap sorting (N=%d) time cost : %f ms\n\n", n, t);


	//
	n = 1000000;
	srand((unsigned)time(NULL));
	for (int i = 1; i < n; i++)
	{
		ex5[i] = rand() % 1000001;
	}
	start = clock();
	max_heap_sort(ex5, 1000000);
	end = clock();
	max_checkSort(ex5, 1000000);
	t = float(end - start);
	printf("Maxheap sorting (N=%d) time cost : %f ms\n", n, t);

	start = clock();
	min_heap_sort(ex5, 1000000);
	end = clock();
	min_checkSort(ex5, 1000000);
	t = float(end - start);
	printf("Minheap sorting (N=%d) time cost : %f ms\n\n", n, t);*/
}