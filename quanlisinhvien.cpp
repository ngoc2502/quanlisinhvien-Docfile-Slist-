#include"quanlisinhvien.h"
#include<iostream>
#include<string.h>
using namespace std;

void initialize(Slist** W_list)
{
	*W_list = new Slist{ nullptr, nullptr };
}

Snode* newnode(student* r_stu)
{
	Snode* node = new Snode;
	node->key->address = r_stu->address;
	node->key->name = r_stu->name;
	node->key->gender = r_stu->gender;
	node->key->MSSV= r_stu->MSSV;
	node->key->math = r_stu->math;
	node->key->eng = r_stu->eng;
	node->key->liter = r_stu->liter;
	node->pnext = nullptr;
	return node;
}

bool isEmpty(Slist* list)
{
	if (list->phead == nullptr)
		return true;
	return false;
}

void addHead(Slist* list, student* stu)// add to the heaad
{
	Snode* node = newnode(stu);
	if (isEmpty(list))
	{
		list->phead = list->ptail = node;
		return;
	}
	node->pnext = list->phead;
	list->phead = node;
}

Snode* pop(Slist* list)// popfront
{
	if (isEmpty(list)) return nullptr;
	Snode* node = list->phead;
	Snode* temp = list->phead->pnext;

	delete [] list->phead->key->address ;
	list->phead->key->address = nullptr;
	delete [] list->phead->key->MSSV;
	list->phead->key->MSSV = nullptr;
	delete [] list->phead->key->gender;
	list->phead->key->gender=nullptr;
	delete[] list->phead->key->name;
	list->phead->key->name = nullptr;
	delete list->phead->key;
	list->phead->key = nullptr;
	delete list->phead;

	list->phead = temp;
	return node;
}

void inputStudent(student *st)
{
	cout << "NAME :";
	cin.ignore();
	cin.getline(st->name, 30);
	cin.ignore(0);
	cout << "MSSV :";
	cin.getline(st->MSSV, 11);
	cin.ignore(0);
	cout << "ADDRESS :";
	cin.getline(st->address, 100);
	cin.ignore(0);
	cout << "GENDER :";
	cin.getline(st->gender, 20);
	cin.ignore(0);
	cout << "MATH SCORE: ";
	cin >> st->math;
	cout << "LITERATER :";
	cin >> st->liter;
	cout << "ENGLISH SCORE: ";
	cin >> st->eng;
}

void outstring(char* s)
{
	int l = strlen(s);
	for (int i = 0; i < l; i++)
		cout << s[i];
	cout << "\t";
}

void outputStudent2(student* stu)
{
	outstring(stu->name);
	outstring(stu->MSSV); 
	outstring(stu->address);
	outstring(stu->gender);
	cout << stu->math << "\t" << stu->eng << "\t" << stu->liter << endl;
}

void delist(Slist* list)
{
	while (!isEmpty(list))
	{
		pop(list);
	}
}

void outputList(Slist* list)
{
	if (isEmpty(list))
	{
		cout << "Empty!";
		return;
	}
	Snode* node = list->phead;
	while (node != nullptr)   
	{
		outputStudent2(node->key);
		node = node->pnext;
	}
}

Slist* addTail(Slist* list, student* stu)
{
	Snode* node = newnode(stu);
	if (isEmpty(list))
	{
		list->phead = node;
		list->ptail = list->phead;
		return list;
	}
	list->ptail->pnext = node;
	list->ptail = node;
	return list;
}

Slist* destudent(Slist* list, char s[])
{
	if (isEmpty(list))
	{
		cout << "Empty!";
		return nullptr;
	}
	bool check = false;
	Snode* node = list->phead;
	if (strcmp(list->phead->key->MSSV, s) == 0)
	{
		pop(list);
		return list;
	}
	for (node; node != nullptr; node = node->pnext)
	{
		if (strcmp(node->key->MSSV, s) == 0 && node->pnext == nullptr)
		{
			popback(list);
			return list;
		}
	}
	Snode* n = list->phead;
	while (n != list->ptail)
	{
		if (strcmp(n->pnext->key->MSSV, s) == 0)
		{
			n->pnext = n->pnext->pnext;
			return list;
		}
		n = n->pnext;
	}
	return nullptr;
}

void popback(Slist* list)
{
	if (isEmpty(list)) return;
	if (list->phead->pnext == nullptr)
	{
		delete []list->phead->key->address;
		list->phead->key->address = nullptr;
		delete[] list->phead->key->MSSV;
		list->phead->key->MSSV = nullptr;
		delete[] list->phead->key->gender;
		list->phead->key->gender = nullptr;
		delete[] list->phead->key->name;
		list->phead->key->name = nullptr;
		delete list->phead->key;
		list->phead->key = nullptr;
		delete list->phead;

		list->phead = list->ptail = nullptr;
		return;
	}
	Snode* node = list->phead;
	while (node->pnext->pnext != nullptr)
	{
		node = node->pnext;
	}
	delete[]node->pnext->key->address;
	node->pnext->key->address = nullptr;
	delete[] node->pnext->key->MSSV;
	node->pnext->key->MSSV = nullptr;
	delete[] node->pnext->key->gender;
	node->pnext->key->gender = nullptr;
	delete[] node->pnext->key->name;
	node->pnext->key->name = nullptr;
	delete node->pnext->key;
	node->pnext->key = nullptr;
	delete node->pnext;

	list->ptail = node;
	node->pnext = nullptr;
	return;
}
void swap(student* &a, student* &b)
{
	student* temp = b;
	b = a;
	a = temp;
}
void sort(Slist* &list)
{
	for (Snode* n1 = list->phead; n1 != list->ptail; n1 = n1->pnext)
	{
		for (Snode* n2 = n1->pnext; n2 != nullptr; n2 = n2->pnext)
			if (n1->key->math < n2->key->math)
				swap(n1->key, n2->key);
	}
}