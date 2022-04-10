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
		cout << "���� ����!!" << endl;
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
		cout << "���� ����!!" << endl;
	}
}

void max_heapify(int a[], int h, int m) { // �迭 / root / ũ��
	// parent node�� child node���� Ŀ�� �ϴ� maxheap
	// ��������� ������������ ���ĵ�
	int v = a[h]; // �ϴ� keep
	int j = 0;
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && a[j] < a[j + 1]) {
			j = j + 1; 
		}
		// j�� ���� ū �ڽ� ���
		if (v >= a[j]) break;
		else a[j / 2] = a[j]; // a[j]�� �θ� ���� �̵�(�� ũ�Ƿ�)
	}
	a[j / 2] = v; // �ٲ���
}
void min_heapify(int a[], int h, int m) {
	// parent node�� child node���� �۾ƾ� �ϴ� minheap
	// ��������� ������������ ���ĵ�
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
	// a[0]�� ������� �ʱ� ������ ��� i�� 1���� ���ư�

	for (int i = n / 2; i >= 1; i--) {
		max_heapify(a, i, n); // maxheap ������ �°� �����͸� �ٲ��� (�θ�>�ڽ�)
	}

	for (int i = 1; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i >= 1; i--) { // �������� ����
		int temp = a[1]; // maxheap���� ���� a[1]�� ���� ū ���Ұ� �Ǿ���
		a[1] = a[i + 1];
		a[i + 1] = temp;
		max_heapify(a, 1, i);
	}
}
void min_heap_sort(int a[], int size) {
	int n = size - 1;

	for (int i = n / 2; i >= 1; i--) {
		min_heapify(a, i, n); // minheap ������ �°� �����͸� �ٲ���
	}

	for (int i = n - 1; i >= 1; i--) { // �������� ����
		int temp = a[1]; // minheap���� ���� a[1]�� ���� ���� ����
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
	// ���� 1
	int arr[] = {0,6,2,8,1,3,9,4,5,10,7 }; // a[0]�� ���� �ʴ´ٰ� �����Ƿ� 0���� ����

	max_heap_sort(arr, 10);
	printf("MaxHeap ���� ���\n");
	printResult(arr, 10);
	max_checkSort(arr, 10);
	
	min_heap_sort(arr, 10);
	printf("MinHeap ���� ���\n");
	printResult(arr, 10);
	min_checkSort(arr, 10);

	printf("\n\n");

	/*
	// ���� 2
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