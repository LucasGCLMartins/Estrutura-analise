// main.cpp
#include <iostream>
#include <locale>
#include "Estrutura-analise.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale.h>
using namespace std;

void Print(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->Disciplina<<" "<<node->ISBN<<" "<<node->Titulo<<" "<<node->Autor<<" "<<node->Edicao<<" "<<node->Cidade<<" "<<node->Editora<<" "<<node->Ano<<" "<<node->Complementar<<" "<<endl;
		node = node->next;
	}
	cout<<endl;
}
void GetHead(Node *node)
{
	cout<<"Head: "<<node->data<<endl;
}

void GetTail(Node *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	cout<<"Tail: "<<node->data<<endl;
}

bool isEmpty(Node *node)
{
	if (node == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintListInfo(Node *node)
{
 if (isEmpty(node))
 {
 cout << "Lista vazia!\n";
 }
 else
 {
 cout << "Lista: ";
 Print(node);
 }
}

Node* ReadFile(Node* list){

	Node node;
	string fname;
	fname = "bibliografia.csv";
	
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
			
			stringstream str(line);
			
			while(getline(str, word, ';'))
				row.push_back(word);
				node.Insert(&list, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]); 
				
			content.push_back(row);

		}
		cout<< list->Disciplina<<endl;
		return list;
	}
	else
		cout<<"Could not open the file\n";
}

void displaymenu()
{ 
	cout<<"===================================================== \n";
	cout<<"\t \t Menu: \n";
	cout<<"===================================================== \n";
	cout<<" 1.Ler dados\n";
	cout<<" 2.Exibir dados\n";
	cout<<" 8.Encerrar \n";
}

void EscolhaDois(Node *list)
{
	PrintListInfo(list);
}

int main()
{ 
	Node node;
	Node* list = node.Create();

	setlocale(LC_CTYPE, "Portuguese");
	int yourchoice;
	string confirm;

	displaymenu();

	do
	{ 
		cout<<"Digite sua escolha(1-5):";
		cin>>yourchoice;
		
	switch (yourchoice)
	{
		case 1:
			list = ReadFile(list);
			break;
		case 2:
			EscolhaDois(list);
			break;
		case 8:
			cout<< "VLW IRMAO \n";
			break;
		default: cout<<"invalid"; break;
	}
	} while (yourchoice != 8);
	


}