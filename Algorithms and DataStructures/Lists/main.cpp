//
// Lists, c++, Mohamad Alamin Yassin
//
#include <bits/stdc++.h>

using namespace std;

struct Product {
    // Name of the Product
	string name;
	// Price of the Product
	int price;
	// Year of production
	int year;
};

struct node {

	Product data;

	node *next;
};
// All the functions are written inside this class
class List {

	node *head;

	node *tail;

	node *temp;

	int nodeNum = 0;

	bool isEmpty()
	{
		return head == NULL;
	}
public:
    // constructor
	List()
	{
		head = NULL;
		tail = NULL;
	}
	// This function is adding the product at the first of the list
	void addAtFirst(Product p)
	{

		temp = new node;
		temp->data = p;
		if (isEmpty())
		{
			temp->next = NULL;
			tail = temp;
		}
		else
			temp->next = head;
		head = temp;
		nodeNum++;
	}
	void addAtLast(Product p)
	{
		temp = new node;
		temp->data = p;
		temp->next = NULL;
		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		nodeNum++;
	}
    // I'm using add before using only 2 pointers :D  "more efficient for memory"
	void addBefore(Product p, Product pos)
	{
		if (isEmpty())
		{
			cout << "Logic error, the list is empty, please add some nodes before using this function"<<endl;
		}
		else if (nodeNum == 1)
		{
			addAtFirst(p);
		}
		else
		{
		    // initializing 2 pointers
            node *prev;
            node *after;
            prev = head;
            after = head->next;
		    if(prev->data.name==pos.name)
		    {
		        addAtFirst(p);
		    }
            else
            {
                while (after->next != NULL && after->data.name != pos.name)
                {
                    prev = after;
                    after = after->next;
                }
                if (after->data.name == pos.name)
                {
                    temp = new node;
                    temp->data = p;
                    temp->next = prev->next;
                    prev->next = temp;

                    nodeNum++;
                }
                else
                {
                    cout << "Error, couldn't find the desired position to insert the product!"<<endl;
                }
            }

		}
	}
	void addAfter(Product p, Product pos)
	{
		if (isEmpty())
		{
			cout << "Logic error, the list is empty, please add some nodes before using this function";
		}
		else if (nodeNum == 1)
		{
			addAtLast(p);
		}
		else
		{

			node *prev = new node;
			prev = head;
			while (prev->next != NULL && prev->data.name != pos.name)
			{
				prev = prev->next;
			}
			if (prev->data.name == pos.name)
			{
			    temp = new node;
			    temp->data=p;
			    temp->next=prev->next;
			    prev->next=temp;
				nodeNum++;
			}
			else
			{
				cout << "Error, couldn't find the desired position to insert the product!\n";
			}
		}
	}
	void removeNode(Product p)
	{
		temp = head;
		node *prev;
		while (temp->next != NULL && temp->data.name != p.name)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp->data.name == p.name)
		{
			if (nodeNum > 1)
			{
				prev->next = temp->next;
				cout<<temp->data.name<<" has been deleted successfully "<<endl;
				delete temp;
			}
			else
			{
				cout <<"Error, please add any node before deleteing";
			}
		}
		else
		{
			cout << "couldn't find the desired node to delete";
		}
	}

    // This function is for printing the list
	void display()
	{
		if (!isEmpty())
		{
			for (temp = head; temp != NULL; temp = temp->next)
			{
				cout <<"Product: " <<temp->data.name << " - ";
				cout << temp->data.price << "$ - ";
				cout << temp->data.year <<"  ";
				cout <<"   ";
			}
			cout << endl<<endl;
			cout << "The shop has: "<< nodeNum <<" Products"<<endl<<endl;
		}
		else
		{
			cout << "Error, the list is empty, please add some nodes before using this function";
		}
	}
};

int main()
{
	List l;
	Product pro, pr, prod, p1, p2, p3, p4, p5, p6;

	pr.name = "Woods";
	pr.price = 2;
	pr.year=1998;
	l.addAtFirst(pr);


	pro.name = "Oil";
	pro.price = 20;
	pro.year=2016;
	l.addAtFirst(pro);


	prod.name = "Pancakes";
	prod.price = 3;
	prod.year=2021;
	l.addAtLast(prod);

	p2.name = "Butter";
	p2.price = 5;
	p2.year=2020;
	l.addAtLast(p2);

	p3.name = "Meat";
	p3.price = 7;
	p3.year=2021;
	l.addAtLast(p3);

	p4.name = "Cheese";
	p4.price = 3;
	p4.year=2020;
	l.addAtLast(p4);
	l.display();

	p1.name = "Kefir";
	p1.price = 2;
	p1.year=2021;
	l.addAfter(p1, p4);

	p6.name = "Ice cream";
	p6.price = 1;
	p6.year=1000;

	l.addBefore(p6, pro);




	l.display();

	return 0;
}
