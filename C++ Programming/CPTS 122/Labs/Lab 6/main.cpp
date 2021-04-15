#include "Queue.hpp"
#include "TestQueue.hpp"

int main(void) {
	Queue printList;
	TestQueue test;

	test.testEnqueue(0);
	test.testEnqueue(1);
	test.testDequeue(0);
	test.testDequeue(1);

	printList.enqueue("lol");
	printList.enqueue("sup");
	printList.printQueueRecursive(printList.getHeadPtr());

	return 0;
}