#include "Queue.hpp"

int main() {
	List<int> list;
	Queue<int> queue;
	int x = 0;

	list.insertAtBack(4);
	list.insertAtFront(12);
	list.insertAtFront(38);
	list.insertAtBack(27);
	cout << "List empty: " << (list.isEmpty() ? "True" : "False") << endl;
	list.print();
	list.removeFromFront(x);
	cout << "Removed from front: " << x << endl;
	list.removeFromBack(x);
	cout << "Removed from back: " << x << endl;
	list.print();
	list.removeFromFront(x);
	list.removeFromBack(x);
	cout << "List empty: " << (list.isEmpty() ? "True" : "False") << endl;

	queue.enqueue(5);
	queue.enqueue(9);
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	
	return 0;
}