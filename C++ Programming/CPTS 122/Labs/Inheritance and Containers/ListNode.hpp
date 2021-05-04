#include <iostream>

using namespace std;

template <class NODETYPE> class List; // forward declaration

template <class NODETYPE>
class ListNode {
	friend class List<NODETYPE>; // make List a friend
public:
	ListNode(const NODETYPE& newData);
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode<NODETYPE>* nextPtr;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& newData) {
	data = newData;
	nextPtr = nullptr;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const {
	return data;
}