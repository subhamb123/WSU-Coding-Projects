#include "TestQueue.hpp"

void TestQueue::testEnqueue(int option) {
	if (option) {
		Queue q;

		bool success = q.enqueue("kkk");

		if (success) {
			if (!q.isEmpty()) {
				if (q.getHeadPtr()->getData() == "kkk")
					cout << "Success" << endl;
			}
		}
	}
	else {
		Queue q;

		bool success = q.enqueue("kkk") && q.enqueue("ggg");

		if (success) {
			if (!q.isEmpty()) {
				if (q.getHeadPtr()->getData() == "kkk" && q.getHeadPtr()->getNextPtr()->getData() == "ggg")
					cout << "Success" << endl;
			}
		}
	}
}

void TestQueue::testDequeue(int option) {
	if (option) {
		Queue q;

		bool success = q.enqueue("kkk");
		string test = q.dequeue();

		if (success) {
			if (q.isEmpty()) {
				if (test == "kkk")
					cout << "Success" << endl;
			}
		}
	}
	else {
		Queue q;

		bool success = q.enqueue("kkk") && q.enqueue("ggg");
		string test = q.dequeue();

		if (success) {
			if (!q.isEmpty()) {
				if (test == "kkk")
					cout << "Success" << endl;
			}
		}
	}
}