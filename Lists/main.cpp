//
// Lists, c++, Mohamad Alamin Yassin
//
#include <bits/stdc++.h>

using namespace std;

// I have made a struct called Products
struct Product {
    // Name of the Product
	string name;
	// Price of the Product
	int price;
	// Year of production
	int year;
};
// I have made a struct called node, each node is made up from Data and pointer
struct node {
    // Here we have the data
	Product data;
	// and here we have the pointer that points out to the next node
	node *next;
};
// All the functions are written inside this class
class List {
    // First node Pointer
	node *head;
	// last node Pointer
	node *tail;
	// Temporary pointer that can be used whenever we want
	node *temp;
	// A counter to count how many nodes are in the list
	int nodeNum = 0;
	// This function check if the list is empty or not
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
	    // initializing
		temp = new node;
		// adding the data
		temp->data = p;
		// checking if the list is empty
		if (isEmpty())
		{
		    // pointing to NULL
			temp->next = NULL;
			// our node is the last node in the list
			tail = temp;
		}
		else
            // if the list is not empty, then we point out to the head
			temp->next = head;
        // our node is the first node in the list
		head = temp;
		nodeNum++;
	}
    // This function is adding the product at the last of the list
	void addAtLast(Product p)
	{
	    // initializing
		temp = new node;
		// adding the data
		temp->data = p;
		// // initializing the next pointer
		temp->next = NULL;
		// checking if it's empty or not
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
		// increasing the amounts of the nodes
		nodeNum++;
	}
    // This function is adding the product before a given name
	void addBefore(Product p, Product pos)
	{
	    // checking if the list is empty
		if (isEmpty())
		{
			cout << "Logic error, the list is empty, please add some nodes before using this function"<<endl;
		}
		// if we have only one node, then we can use add at first function
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
            // here we are saying if we want to add before the first node, we will use addAtFirst function so we won't get a "logic error"
		    if(prev->data.name==pos.name)
		    {
		        addAtFirst(p);
		    }
            else
            {
                // searching for the required node
                while (after->next != NULL && after->data.name != pos.name)
                {
                    prev = after;
                    after = after->next;
                }
                // if we found the node, we will add our node before of it
                if (after->data.name == pos.name)
                {
                    temp = new node;
                    temp->data = p;
                    temp->next = prev->next;
                    prev->next = temp;

                    nodeNum++;
                }
                // rather that, we will show an error that we didn't find that product
                else
                {
                    cout << "Error, couldn't find the desired position to insert the product!"<<endl;
                }
            }

		}
	}
    // This function is adding the product after a given name
	void addAfter(Product p, Product pos)
	{
	    // checking if it's empty or not
		if (isEmpty())
		{
			cout << "Logic error, the list is empty, please add some nodes before using this function";
		}
		// if there is only one node, we can use add at last function
		else if (nodeNum == 1)
		{
			addAtLast(p);
		}
		else
		{

            // initializing
			node *prev = new node;
			prev = head;
            // searching for the required node
			while (prev->next != NULL && prev->data.name != pos.name)
			{
				prev = prev->next;
			}
            // if we found the node, we will add our node after of it
			if (prev->data.name == pos.name)
			{
			    temp = new node;
			    temp->data=p;
			    temp->next=prev->next;
			    prev->next=temp;
				nodeNum++;
			}
            // rather that, we will show an error that we didn't find that product
			else
			{
				cout << "Error, couldn't find the desired position to insert the product!\n";
			}
		}
	}
    // This function is removing a specific product
	void removeNode(Product p)
	{
	    // initializing
		temp = head;
		node *prev;
        // searching for the required node
		while (temp->next != NULL && temp->data.name != p.name)
		{
			prev = temp;
			temp = temp->next;
		}
		// if we found the node, we will delete it
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
			//show the number of the nodes
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
