#include<iostream>
#include<fstream>

using namespace std;

struct student
{
	char* name = new char[50];
	char* MSSV = new char[11];
	char* gender = new char[20];
	char* address = new char[50];
	float math = 0;
	float liter = 0;
	float eng = 0;
};
struct studentlist
{
	int n = 0;
	student* std=new student[10];
};

struct Snode
{
	student* key= new student;
	Snode* pnext;
};

struct Slist
{
	Snode* phead;
	Snode* ptail;
};

void initialize(Slist** W_list);

Snode* newnode(student* r_stu);

bool isEmpty(Slist* list);

void addHead(Slist* list, student* stu);// add to the heaad

Snode* pop(Slist* list);


void delist(Slist* list);

void outputList(Slist* list);

Slist* addTail(Slist* list, student *stu);

void createStudent(student *s);

void inputStudent(student* st);

void outputStudent2(student* stu);

Slist* destudent(Slist* list, char s[]);

void popback(Slist* list);

void sort(Slist* &list);// sorting go down follow math score

