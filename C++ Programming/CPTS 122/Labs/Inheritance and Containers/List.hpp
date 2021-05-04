#include "ListNode.hpp"

template <class NODETYPE>
class List {
public:
	List();
	~List();
	void insertAtFront(const NODETYPE& newData);
	void insertAtBack(const NODETYPE& newData);
	bool removeFromFront(NODETYPE& removedData);
	bool removeFromBack(NODETYPE& removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE>* getNewNode(const NODETYPE& newData);
	ListNode<NODETYPE>* firstPtr;
	ListNode<NODETYPE>* lastPtr;
};

template <class NODETYPE>
List<NODETYPE>::List() {
	firstPtr = nullptr;
	lastPtr = nullptr;
}

template <class NODETYPE>
List<NODETYPE>::~List() {

}

template <class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE& newData) {
	ListNode<NODETYPE>* pMem = getNewNode(newData);
	if (pMem != nullptr) {
		if (firstPtr == nullptr)
			firstPtr = lastPtr = pMem;
		else {
			pMem->nextPtr = firstPtr;
			firstPtr = pMem;
		}
	}
}

template <class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& newData) {
	ListNode<NODETYPE>* pMem = getNewNode(newData);
	
	if (pMem != nullptr) {
		if (firstPtr == nullptr)
			firstPtr = lastPtr = pMem;
		
		else {
			lastPtr->nextPtr = pMem;
			lastPtr = pMem;
		}
	}
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& removedData) {
	ListNode<NODETYPE>* pTemp = firstPtr;

	if (firstPtr == lastPtr)
		firstPtr = lastPtr = nullptr;
	else
		firstPtr = firstPtr->nextPtr;

	removedData = pTemp->data;
	delete pTemp;
	return true;
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE& removedData) {
	ListNode<NODETYPE>* pTemp = lastPtr, *pPrev = firstPtr;

	while (pPrev->nextPtr != nullptr && pPrev->nextPtr != pTemp)
		pPrev = pPrev->nextPtr;

	if (firstPtr == lastPtr)
		firstPtr = lastPtr = nullptr;
	else {
		lastPtr = pPrev;
		pPrev->nextPtr = nullptr;
	}

	removedData = pTemp->data;
	delete pTemp;
	return true;
}

template <class NODETYPE>
bool List<NODETYPE>::isEmpty() const {
	return firstPtr == nullptr;
}

template <class NODETYPE>
void List<NODETYPE>::print() const {
	ListNode<NODETYPE>* pCur = firstPtr;
	while (pCur != nullptr) {
		cout << "Data: " << pCur->data << endl;
		pCur = pCur->nextPtr;
	}
}

template <class NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& newData) {
	return new ListNode<NODETYPE>(newData);
}