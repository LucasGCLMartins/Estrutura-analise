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

int Size(Node *node)
{
	int cont = 0;
	while (node != NULL)
	{
		cont++;
		node = node->next;
	}
	return cont-1;
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
		return list;
	}
	else
		cout<<"Não foi possível abrir o arquívo\n";
}

void displaymenu()
{ 
	cout<<"===================================================== \n";
	cout<<"\t \t Menu: \n";
	cout<<"===================================================== \n";
	cout<<" 1.Ler dados\n";
	cout<<" 2.Exibir dados\n";
	cout<<" 3.livros brasileiros\n";
	cout<<" 4.livro mais velho\n";	
	cout<<" 5.Buscar por Ano\n";
	cout<<" 6.Buscar por Palavra\n";
	cout<<" 7.Buscar por Matéria\n";
	cout<<" 8.Encerrar \n";
}

void OldestBook(Node *list)
{
	Node *oldest = list;
	Node *current = list;
	
	while (current != NULL)
	{
		if (current->Ano < oldest->Ano)
		{
			oldest = current;
		}
		current = current->next;
	}	
	cout<< oldest->Titulo<<" "<<oldest->Ano<<endl;
}

void BrazilianBooks(Node *list)
{
	Node *current = list;
	string BrasilISBN = "978-85";
	int cont = 0;

	while (current != NULL)
	{
		if (current->ISBN.find(BrasilISBN) != std::string::npos) {
			cout<<current->Titulo;
			cont++;
		}
		current = current->next;
	}
	if (cont == 0)
		cout<<"Não há livros brasileiros\n";
	else 
		cout<<"\n";
		cout<<"Existem "<<cont<<" livros brasileiros\n";
		cout<<"Isso representa "<<(cont*100)/Size(list)<<"% dos livros\n";
}

void searchByYear(Node *list)
{
	string year;
	cout<<"Digite o ano: ";
	cin>>year;
	Node *current = list;
	int cont = 0;
	while (current != NULL)
	{
		if (current->Ano == year)
		{
			cout<<current->Titulo<<" "<<current->Ano<<endl;
			cont++;
		}
		current = current->next;
	}
	if (cont == 0)
		cout<<"Não há livros com o ano "<<year<<endl;
	else 
		cout<<"\n";
		cout<<"Existem "<<cont<<" livros com o ano "<<year<<endl;
		cout<<"Isso representa "<<(cont*100)/Size(list)<<"% dos livros\n";
}

void searchByWord(Node *list)
{
	string word;
	cout<<"Digite a palavra: ";
	cin>>word;
	Node *current = list;
	int cont = 0;
	while (current != NULL)
	{
		if (current->Titulo.find(word) != std::string::npos)
		{
			cout<<current->Titulo<<" "<<current->Ano<<endl;
			cont++;
		}
		current = current->next;
	}
	if (cont == 0)
		cout<<"Não há livros com a palavra "<<word<<endl;
	else 
		cout<<"\n";
		cout<<"Existem "<<cont<<" livros com a palavra "<<word<<endl;
		cout<<"Isso representa "<<(cont*100)/Size(list)<<"% dos livros\n";
}

void subjectSearch(Node* list){
  Node *current = list;
  string subject;
  int opcao=0,cont=0;
  bool flagInvalido=false;


  
	do{  

		cout<<"\nMateria da Terceira Etapa:\n 1.Banco de Dados\n 2.Estrutura de Dados\n 3.Modelagem Matematica\n 4.Organizacao de Computadores\n 5.Projeto e Analise de Algoritmos I\n\nSelecione a materia que voce deseja visualizar:";
		cin>>opcao;

		switch (opcao){
			case 1:
			subject="BANCO";
			break;
			case 2:
			subject="ESTRUTURA";
			break;
			case 3:
			subject="MODELAGEM";
			break;
			case 4:
			subject="ORGANIZAÇÃO";
			break;
			case 5:
			subject="PROJETO";
			break;
			default:
			cout<<"Opcao invalida";
			break;
		}
	} while (opcao<1 || opcao>5);
  
	while (current != NULL){
		if(current->Disciplina.find(subject) != std::string::npos){
			cout<<current->Titulo<<"\n";
			cont++;
    	}
    current=current->next;
    }

  cout<<"Existem "<<cont<<" livros dessa disciplina\n";

}

int main()
{ 
	Node node;
	Node* list = node.Create();

	setlocale(LC_CTYPE, "Portuguese");
	int yourchoice;
	string confirm;

	displaymenu();

	do{ 
		cout<<"Digite sua escolha(1-8):";
		cin>>yourchoice;
		
		switch (yourchoice)
		{
			case 1:
				list = ReadFile(list);
				break;
			case 2:
				PrintListInfo(list);
				break;
			case 3:
				BrazilianBooks(list);
				break;
			case 4:
				OldestBook(list);
				break;
			case 5:
				searchByYear(list);
				break;
			case 6:
				searchByWord(list);
				break;
			case 7:
				subjectSearch(list);
				break;
			case 8:
				cout<<"Encerrando o programa...\n";
				break;
			default: cout<<"Escolha inválida"; break;
		}
	} while (yourchoice != 8);
	
}