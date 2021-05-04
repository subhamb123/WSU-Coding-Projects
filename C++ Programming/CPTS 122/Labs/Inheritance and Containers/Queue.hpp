#include "List.hpp"

template <class NODETYPE>
class Queue : private List<NODETYPE> {
public:
	void enqueue(NODETYPE data);
	NODETYPE dequeue();
};

template <class NODETYPE>
void Queue<NODETYPE>::enqueue(NODETYPE data) {
	List<NODETYPE>::insertAtBack(data);
}

template <class NODETYPE>
NODETYPE Queue<NODETYPE>::dequeue() {
	NODETYPE removedData;
	List<NODETYPE>::removeFromFront(removedData);
	return removedData;
}