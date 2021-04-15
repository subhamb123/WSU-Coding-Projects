#include "header.hpp"

int main() {
	srand((unsigned)time(nullptr));
	MergeSort<int> sort;
	for(int i = 0; i < size; i++)
		sort.arr[i] = rand() % 100 + 1;

	cout << "Unsorted array" << endl;
	for (int i = 0; i < size; i++)
		cout << sort.arr[i] << " ";

	cout << endl << endl << "Sorted array" << endl;
	sort.sort(sort.arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << sort.arr[i] << " ";

	cout << endl << endl;

	return 0;
}