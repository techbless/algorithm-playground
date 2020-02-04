#include <stdio.h>
#include <stdlib.h>

// 노드 구조체
typedef struct NODE {
	struct NODE* next;
	int value;
} node;

// 리스트 구조체
typedef struct LIST {
	node* head;
	int length;
} list;

list* getNewList() {
	// 리스트 하나 만들고
	list* newList = (list*)malloc(sizeof(list));
	if (newList == NULL) {
		return NULL;
	}

	// 리스트 안에 대가리도 만들어주고 길이는 0으로 초기화
	newList->head = (node*)malloc(sizeof(node));
	if (newList->head != NULL) {
		newList->head->next = NULL;
		newList->length = 0;
	}

	// 그리고 리스트 반환해주자
	return newList;
}

void insert(list* lptr, int value) {
	node* nptr = lptr->head;

	// 마지막 노드를 찾아서
	while (nptr->next != NULL) {
		nptr = nptr->next;
	}
	// value를 입력후 그 다음 새로운 노드를 추가

	nptr->next = (node*)malloc(sizeof(node));
	if (nptr->next != NULL) {
		nptr->value = value;
		nptr->next->next = NULL;
	}

	// 리스트 길이 증가
	lptr->length++;
}


int get(list* lptr, int nth) {

	int current = 0;
	node* nptr = lptr->head;

	// nth번째까지 넘어가서 값을 가져다죠
	while (nptr->next != NULL) {
		if (current == nth) {
			return nptr->value;
		}
		nptr = nptr->next;
		current++;
	}

	// n번쨰 없자나 세캬
	return NULL;
}

void insertAt(list* lptr, int value, int at) {
	// 일단, 맨앞 대가리 가져와서
	node* nptr = lptr->head;

	// 왜 구지 0번째에 추가하고 그런데... 노드 새로 만들어서 head로 바꿔줘..
	if (at == 0) {
		node* newNode = (node*)malloc(sizeof(node));
		if (newNode != NULL) {
			newNode->next = lptr->head;
			newNode->value = value;
			lptr->head = newNode;
			lptr->length++;
		}
		return;
	}

	
	int current = 0;
	while (nptr->next != NULL) {
		// 추가하고 싶은 위치 바로 전까지 와서
		if (current == (at - 1)) {
			// 새로운 node를 생성하고 값이랑 next를 가져와
			node* newNode = (node*)malloc(sizeof(node));
			if (newNode != NULL) {
				newNode->next = nptr->next;
				newNode->value = value;
				// 현재 node->next가 새로추가되는 node지 그럼
				nptr->next = newNode;

				// 다했으면 리스트 길이 늘려줘야지
				lptr->length++;
				return;
			}
		}
		nptr = nptr->next;
		current++;
	}
}

void delete(list* lptr, int index) {
	node* nptr = lptr->head;

	//이번에도 head를 지우는건 말이좀 다르지
	if (index == 0) {
		node* target = nptr;
		// head가 head다음 노드로 대치
		lptr->head = nptr->next;
		// 이전 head 날려버리자
		free(target);
		lptr->length--;
		return;
	}

	int current = 0;
	while (nptr->next != NULL) {
		// 아... 일단 찾아봐
		if (current == (index - 1)) {
			// nptr->next의 next가 필요한데 지워지면 안대잖아?
			// 일단 target에 보관하고 next 꺼낸다음에 날려버려
			node* target = nptr->next;
			nptr->next = nptr->next->next;
			free(target);

			//하나 지웠으니까 길이 줄여주자
			lptr->length--;
			return;
		}
		nptr = nptr->next;
		current++;
	}
}

// 그래서 이 리스트가 얼마나 긴데
getLength(list* lptr) {
	return lptr->length;
}

int main(void) {
	list* mylist = getNewList();

	insert(mylist, 1);
	insert(mylist, 2);
	insert(mylist, 3);
	insert(mylist, 4);
	insertAt(mylist, 100, 3);
	delete(mylist, 0);

	for (int i = 0; i < getLength(mylist); i++)
		printf("mylist[%d] : %d\n", i, get(mylist, i));

	printf("\n리스트 길이 : %d\n", getLength(mylist));
}
