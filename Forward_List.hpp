#include "Forward_List.h"

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if(head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    temp = nullptr;
    Size--;
}

template<typename T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data,head);
    Size++;
}

template<typename T>
void List<T>::insert(T data,int index)
{
    if(index == 0)
    {
        push_front(data);
    }
    else
    {
    Node<T> *previus = this->head;
    for(int i = 0; i < index - 1; i++)
    {
        previus = previus->pNext;
    }
    Node<T> *newNode = new Node<T>(data,previus->pNext);
    previus->pNext = newNode;
    Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index)
{
    if(index==0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previus = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            previus = previus->pNext;
        }
        Node<T> *toDelete = previus->pNext;
        previus->pNext = toDelete->pNext;
        delete toDelete;
        toDelete = nullptr;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(Size-1);
}