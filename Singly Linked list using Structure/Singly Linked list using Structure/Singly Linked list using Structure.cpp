#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;

	node(int value)
	{
		data = value;
		next = NULL;
	}
};

int findlength(node*& head)
{
	int length = 1;
	node* temp = head;
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			length++;
		}
		return length;
	}
}

void insertattail(struct node*& head, int data)
{
	struct node* temp = head;
	if (head == NULL)
	{
		struct node* newnode = new node(data);
		head = newnode;
		return;
	}
	else
	{
		struct node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new node(data);
	}
}

void display(struct node*& head)
{
	node* temp = head;
	if (head == NULL)
	{
		cout << "Linked list is empty !";
	}
	else
	{
		while (temp->next != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << temp->data << "\n";
	}
}

void deletefromtail(node*& head)
{
	struct node* temp = head;
	if (head == NULL)
	{
		"Linked list is empty !\n";
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
}

int deletefrompos(node*& head, int pos)
{
	struct node* temp = head;
	int c = 1;

	if (pos <= 1 || pos > findlength(head))
	{
		cout << "Invalid position for deletion !\n";
	}

	else
	{
		while (c != pos - 1)
		{
			temp = temp->next;
			c++;
		}
		node* deleted = temp->next;
		temp->next = temp->next->next;
		return deleted->data;
	}
}

void insertatpos(struct node*& head, int pos, int data)
{
	node* temp = head;
	node* temp2 = head;
	node* n = new node(data);
	int c = 1;

	if (pos<1 || pos>findlength(head))
	{
		cout << "Invalid position for insertion !\n";
	}

	while (c != pos - 1)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	temp2 = temp->next;
	temp->next = n;
	n->next = temp2;
}

void modifyvalue(struct node*& head, int pos, int val)
{
	node* temp = head;
	int c = 1;
	if (pos < 1 || pos > findlength(head))
	{
		cout << "Invalid position for modification of value !\n";
	}
	else
	{
		while (c != pos)
		{
			temp = temp->next;
			c++;
		}
		temp->data = val;
	}
}

int main()
{
	struct node* head = NULL;
	insertattail(head, 1);
	insertattail(head, 2);
	insertattail(head, 3);
	insertattail(head, 4);
	insertattail(head, 5);
	display(head);
	deletefromtail(head);
	display(head);
	deletefrompos(head, 2);
	display(head);
	insertatpos(head, 2, 77);
	display(head);
	modifyvalue(head, 2, 99);
	display(head);

	return 0;
}