#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//Template LinkedList Node
template <class T>
class Node{
	public:
		// 데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node<T> *link;
		// 노드 생성자
		Node(T element){
		  data = element;
		  link = 0;
		}
	};

// Template LinkedList Class
template <class T>
class LinkedList{
	protected:		
		Node<T> *first; // 첫번째 노드의 주소를 저장할 포인터
		int current_size; // 리스트의 현재 크기(노드의 개수)를 저장
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0; // null 포인터로 초기화
			current_size = 0; // 크기는 0으로 초기화
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element); // virtual로 선언하여 파생 클래스에서 함수 재정의가 가능하다

		//리스트 출력
		void Print();
};

//새 노드를 맨 앞에 붙이고 값을 넣음
template <class T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode; // 새로운 노드가 첫번째 노드가 된다
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <class T>
bool LinkedList<T>::Delete(T &element){

	// first가 null 포인터면 비어있는 리스트이기 때문에 false 리턴
	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous) // 마지막 이전의 노드가 있다면 current -> link가 가리키는 null 포인터를 마지막 이전의 노드의 링크에 지정한다
				previous -> link = current -> link;
			else
				first = first -> link; // 노드가 한개만 있을 경우 첫번째 노드를 null로 가리킨다
			break;
		}
		// loop을 iterate 할 때마다 이전 노드를 현재 노드로 가리키고 current 노드를 다음 노드로 가리키며 노드를 하나씩 옮기면서 탐색한다
		previous = current; // 
		current = current -> link;
	}
	// 탐색을 마친 후 노드의 데이터를 저장하고 노드를 삭제한다
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
template <class T>
void LinkedList<T>::Print(){
	Node<T> *i; // 노드 포인터
	int index = 1;
	
	// 리스트에 노드가 있는 경우에 출력
	if (current_size != 0){
		// 첫번째 노드를 시작으로 노드의 데이터를 출력하고 link를 통해 다음 노드로 이동하여 null에 도달하기 전까지 각 노드의 데이터를 출력
		for( i = first; i != NULL; i=i->link){
			// 마지막 노드에 도달하면 괄호를 닫는다
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}
			// 마지막 노드가 아니라면 괄호를 닫고 화살표까지 출력한다
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}

#endif
