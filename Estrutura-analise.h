#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
using namespace std;
#include <string>

class Node
{
	public:
        int data;
        std::string Disciplina;
        std::string ISBN;
        std::string Titulo;
        std::string Autor;
        std::string Edicao;
        std::string Cidade;
        std::string Editora;
        std::string Ano;
        std::string Complementar;

        Node *next;

        void Insert(Node** head_ref, string Disciplina, string ISBN, string Titulo, string Autor, string Edicao, string Cidade, string Editora, string Ano, string Complementar);
        void Append(Node** head_ref, int new_data); 
        Node* RemoveNode(Node** head_ref, int key);
        Node* RemoveHead(Node** head);
        void Clear(Node** head_ref);
        Node* RemoveTail(Node* head);
        Node* Create();
        Node* Destroy(Node* node);
};

#endif // __LINKEDLIST_H__