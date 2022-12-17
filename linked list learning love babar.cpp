//programer Name: Abuzar hassan
//registeration no. : 4313-FBAS/BSSE/F21
//OOP PROGREAM: SINGLY LINKED LIST USING OOP
//IN THIS PROGRAM I PERFORM DIFFERENT FUNCTION ON LINKED LIST
//CREATE,DISPLAY,DELETE NODE,UPDATE DATA,DATA AVERAGE ETC AND MANY MORE


#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	void createLL(Node*& head, Node*& curr, int t);
	void displayLL(Node*& head);
	void searchLL(Node*& head);
	void shortLL(Node*& head);
	void updateLL(Node*& head);
	void insertAtstart(Node*& head, Node*& curr);
	void insertAtend(Node*& head, Node*& curr);
	void insertAtPos(Node*& curr, Node*& head);
	void deleteNode(Node*& tail, Node*& first);
	void classAvgLL(Node*& head);



};
void Node::createLL(Node*& head, Node*& curr, int t) {
	int d = 0;
	if (head == NULL) {
		cout << "                                                                 Enter data ";
		cin >> d;
		cout << endl;
		Node* temp = new Node(d);
		head = temp;
		curr = temp;
		while (t != 1) {
			cout << "                                                             Enter data ";
			cin >> d;
			Node* temp1 = new Node(d);
			curr->next = temp1;
			curr = curr->next;

			cout << endl;
			t--;
		}
	}
	else {
		while (t != 0) {
			cout << "                                                             Enter data ";
			cin >> d;
			Node* temp1 = new Node(d);
			curr->next = temp1;
			curr = curr->next;

			cout << endl;
			t--;
		}
	}
	
}
void  Node::displayLL(Node*& head) {
	Node* temp = head;
	if (head == NULL) {
		cout << "                                           ************** Linked list is empty **************";
	}
	else {
		while (temp != NULL) {
			cout << temp->data << "  ";
			temp = temp->next;

		}
	}
	cout << endl;
}
void  Node::searchLL(Node*& head) { 
	int counter = 1;
	bool found = 1;
	int d=0;
	cout <<                                                            "Enter data you wnt to search ";
	cin >> d;
	cout << endl;
	if (head == NULL) {  //CHEAK
		cout << "                                           ************** Linked list is empty **************";
		cout << endl;

	}
	else
	{
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == d) {
				cout << "                                          data found at position  ["<<counter<<"]";
				cout << endl;
				return;
			}
			temp = temp->next;
			counter++;
		}
		found = 0;
		if (found == 0) {
			cout << "                                                          data not found ";
			cout << endl;
		}

	}
	

}
void  Node::shortLL(Node*& head) {
	Node* i = head;
	Node* j;
	int temp;
	while (i->next != NULL) {
		j =i->next;
		do {
			if (i->data > j->data) {
				
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			
	
			}
		
			
		} while (j->next != NULL, j = j->next);
		i = i->next;
	}


	displayLL(head);
}
void  Node::updateLL(Node*& head) {
	int counter = 0;
	bool found = 1;
	int d = 0;
	cout << "                                                              Enter data you wnt to UPdate ";
	cin >> d;
	cout << endl;
	if (head == NULL) {
		cout << "                                                               data does not exist ";
		
		cout << endl;
		return;

	}
	else
	{
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == d) {
				cout << "                                                           Enter data  ";
				cin >> d;
				temp->data = d;
				cout << endl;
				cout << "                                                        data is updated " << endl;
				return;
			}
			temp = temp->next;
			counter++;
		}
		found = 0;
		if (found == 0) {
			cout << "                                                   data not found you want to update ";
			cout << endl;
		}

	}

}
void  Node::insertAtstart(Node*& head,Node*&curr) {
	int d;
	cout << "                                                                     Enter  data ";
	cin >> d;
	Node* temp = new Node(d);
	if (head == NULL) {
		head = temp;
		curr = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}
void Node::insertAtend(Node*& head, Node*& curr) {
	int d;
	cout << "                                                                      Enter  data ";
	cin >> d;
	Node* temp = new Node(d);
	if (curr == NULL) {
		head = temp;
		curr = temp;
	}
	else {
		curr->next = temp;
		curr = curr->next;//last=temp
	}
}
//insert at any postion................
void  Node::insertAtPos(Node*& curr, Node*& head) {
	int pos;
	cout << "                                                                   Enter  Position ";
	cin >> pos;
	Node* temp = head;
	int count = 1;
	//cheacking if pos ia at last then call insertAtstart function
	if (pos == count) {
		insertAtstart(head,curr);
		return;
	}
	//cheacking the pos where to add
	while (count < pos - 1) {
		temp = temp->next;
		count++;
	}
	//cheacking if pos ia at last then call insertAtend function
	if (temp->next == NULL) {
		insertAtend(head,curr);
		return;
	}
	//create new node for  d
	int d;
	cout << "                                                                          Enter  data ";
	cin >> d;
	Node* nodeToinsert = new Node(d);
	nodeToinsert->next = temp->next;
	temp->next = nodeToinsert;
}
void  Node::deleteNode(Node*& tail, Node*& first) {
	Node* temp = first;
	Node* curr = first;
	Node* prev = NULL;
	int pos;
	cout << "                                                      Enter  Position of node you want to delete ";
	cin >> pos;
	if (first == NULL) {
		cout << "                                           ************** Linked list is empty **************";
	}
	else {
		int count = 1;
		if (pos == count) {
			first = first->next;
		
			delete temp;
			cout << "                                                           Node deleted " << endl;
		}
		else {
			while (count < pos) {
				prev = curr;
				curr = curr->next;
				count++;
			}
			prev->next = curr->next;
			if (prev->next == NULL) {
				tail = prev;
			}
			delete curr;
			cout << "                                                                Node deleted " << endl;

		}
	}
}
void  Node::classAvgLL(Node*& head) {
	Node* temp = head;
	float sum = 0.0;
	float count =0.0;
	float avg = 0.0;
	if (head == NULL) {
		cout << "                                           ************** Linked list is empty **************";
		cout << endl;

	}
	else {
		while (temp->next!=NULL) {
			sum =sum+ temp->data;
			temp = temp->next;
			count++;
		}
		avg = sum / count;
		cout << "                                                     Average of data is: " << avg << endl;
	}
}
int main() {
	Node* head = NULL;
	Node* curr = NULL;
	do {
		//system("cls");
		char ch = '/0';
		cout << endl;
		cout << "                        ********************     " << "                          " << "          ********************" << endl;
		cout << "                                                               Main Menu                                  " << endl;
		cout << "                        ********************     " << "                          " << "          ********************" << endl;
		cout << "                                                           1.Create link list  " << endl;	     
		cout << "                                                           2.Display  " << endl;			     
		cout << "                                                           3.Search  " << endl;			     
		cout << "                                                           4.sorting " << endl;			     
		cout << "                                                           5.updation " << endl;			     
		cout << "                                                           6.insertion " << endl;			     
		cout << "                                                           7.deletion " << endl;			     
		cout << "                                                           8.data average " << endl;		     
		cout << "                                                           9.Exit " << endl;				     
		cout << "                        ********************     " << "                          " << "          *********************" << endl;
		cout << "                                                           Enter Your choice ";			     
		cin >> ch;												    										     
		cout << "                        ********************     " << "                          " << "          *********************" << endl;
		switch (ch) {
		case '1':
		{int t = 0;
		cout << "                                                        How many time you want to enter data  ";
		cin >> t;
		head->createLL(head, curr, t);
		
		}
		break;
		case '2':
			head->displayLL(head);
			break;
		case '3':
			head->searchLL(head);
			break;
		case '4':
			head->shortLL(head);
			
			break;
		case '5':
			head->updateLL(head);
			break;
		case '6':
			system("cls");
		      
				cout << "Insertion Menu" << endl;
				cout << "1.insert at start" << endl;
				cout << "2.insert at End" << endl;
				cout << "3.insert at Position" << endl;
				cout << endl;
				cout << "Enter YOur choice ";
				cin >> ch;
				switch (ch) {
				case '1':
					head->insertAtstart(head, curr);
					break;
				case '2':
					head->insertAtend(head, curr);
					break;
				case '3':
					head->insertAtPos(curr, head);
					break;
				default:
					if (ch != '1' && ch != '3') {

						cout << "please enter valid data" << endl;
					}
				}

			break;
		case '7':
			head->deleteNode(curr, head);
			break;
		case '8':
			head->classAvgLL(head);

			break;
		case '9':
			cout << "Enter any key To Exit ";
			cin >> ch;
			exit(0);
			break;
		default:
			if (ch != '1' && ch != '9') {

				cout << "please enter valid data" << endl;
			}

		}
	} while (true);


}