#include<bits/stdc++.h>
using namespace std;
struct linked_list
{
	int num;
	linked_list *next;
	void insert(int num);
	void deletion();
	linked_list()
	{
		next=NULL;

	}
} *start,*end,temp;
void insert(int number)
{	linked_list *a;
	a = (linked_list *)malloc(sizeof(linked_list));
	a->num=number;
	a->next = NULL;
	if(start == NULL)
	{
		start = a;
		end = a;
	}
	else
	{
		end->next = a;
		end = a;
	}
}
void deletion()
{
	start = start -> next;
}
void display()
{
	linked_list *disp;
	disp = start;
	while(disp != end)
	{
		cout<<disp->num<<"  ";
		disp = disp -> next;
	}
	cout<<disp->num<<endl;
}
int menu()
{	int choice;
	cout<<"Select an option \n";
	cout<<"1. Insert element\n";
	cout<<"2. Delete element\n";
	cout<<"3. Display\n";
	cin>>choice;
	return choice;
}
int main ()
{	int num;
	start = NULL;
	end = NULL;


	char ch;
	do{
		int option = menu();
	if (option == 1)
	{
		cout<<"Enter element\n";
		cin>>num;
		insert(num);
	}
	if (option == 2 )
	{
		deletion();
	}
	if (option == 3)
	{
		display();
	}	cout<<"Want to continue? (y/n)\n";
		cin>>ch;}while(ch == 'y');
	return 0;
}
