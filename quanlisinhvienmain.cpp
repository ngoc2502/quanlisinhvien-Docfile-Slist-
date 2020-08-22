#include"quanlisinhvien.h"
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	Slist* list = nullptr;
	initialize(&list);
	studentlist* stud = new studentlist;
	fin.open("InStudentList.txt");
	fout.open("OutStudetntList.txt");
	if (fin.fail()) cout << " error open file!";
	else
	{
		cout << "yup\n";
		fin >> stud->n;
		for (int i = 0; i < stud->n; i++)
		{
			fin.getline(stud->std[i].name, 50, ',');
			fin.getline(stud->std[i].MSSV, 50, ',');
			fin.getline(stud->std[i].address, 50, ',');
			fin.getline(stud->std[i].gender, 50, ',');
			fin >> stud->std[i].math;
			fin >> stud->std[i].eng;
			fin >> stud->std[i].liter;
			addTail(list, &stud->std[i]);
		}
	}
	
	outputList(list);
	cout << "========================================\n";
	char s[11];
	cout << "MSSV: ";
	cin >> s;
	Slist*l=destudent(list, s);
	//outputList(list);
	sort(list);
	outputList(list);
	if (fout.fail()) cout << "error open file!";
	else
	{
		fout << "Student list has been updated: ";
		Snode* node = list->phead;
		while (node != nullptr)
		{
			fout << node->key->name << node->key->MSSV << "\t" << node->key->address << "\t" << node->key->gender << "\t" << node->key->math << "\t" << node->key->eng << "\t" << node->key->liter << endl;
			node = node->pnext;
		}
	}
	delist(list);
	
	stud->std->address = nullptr;
	stud->std->gender = nullptr;
	stud->std->MSSV = nullptr;
	stud->std->name = nullptr;

	delete []stud->std;
	stud->std = nullptr;

	delete stud;
	stud = nullptr;

	delete list;
	list = nullptr;

	fin.close();
	fout.close();
	return 0;
}