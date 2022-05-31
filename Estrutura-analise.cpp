#include "Estrutura-analise.h"
#include <iostream>
#include <string>

Node* Node::Create()
{
    Node* list = NULL;
    return list;
}

Node* Node::Destroy(Node* node)
{
    delete node;
    node = NULL;
}
void Node::Insert(Node** head_ref, string Disciplina, string ISBN, string Titulo, string Autor, string Edicao, string Cidade, string Editora, string Ano, string Complementar)
{
    Node* new_node = new Node;
    new_node->Disciplina = Disciplina;
    new_node->ISBN = ISBN;
    new_node->Titulo = Titulo;
    new_node->Autor = Autor;
    new_node->Edicao = Edicao;
    new_node->Cidade = Cidade;
    new_node->Editora = Editora;
    new_node->Ano = Ano;
    new_node->Complementar = Complementar;

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Node::Append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	Node *last = *head_ref; 
	new_node->data = new_data;

	new_node->next = nullptr;

	if (*head_ref == nullptr)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != nullptr)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

Node* Node::RemoveNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = nullptr;
     
    if (temp != nullptr && temp->data == key)
    {
        *head_ref = temp->next; 
        return temp;           

    }
      else
    {
    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        return nullptr;
 
    prev->next = temp->next;
    return temp;
    }
}

Node* Node::RemoveHead(Node** head)
{
    if (head == nullptr)
        return nullptr;
    Node* temp = *head;
    *head = temp->next;
 
    return temp;
}

void Node::Clear(Node** head_ref)
{
 
    Node* current = *head_ref;
    Node* next = nullptr;
 
    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = nullptr;
}

Node* Node::RemoveTail(Node* head)
{
    if (head == nullptr)
        return head;
 
    if (head->next == nullptr) {
        return head;
    }
 
    Node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;
 
	Node* last = second_last->next;
 
    second_last->next = nullptr;
 
    return last;
}