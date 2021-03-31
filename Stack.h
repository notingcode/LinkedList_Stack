#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		virtual bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) return false;
			
			// current에 첫번째 노드를 저장
			Node<T> *current = this->first;
			// 새로운 첫번째 노드는 원래의 첫번째 노드가 다음으로 가리키는 노드로 변경
			this->first = this->first->link;
			// current에 저장되어 있는 원래의 첫번째 노드의 데이터의 값을 element에 저장
			element = current->data;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			delete current;
			// Stack의 크기를 1 줄임
			this->current_size--;
			
			return true;
			}
};
