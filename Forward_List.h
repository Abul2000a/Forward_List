template<typename T> class List
{
public:
    List();
    ~List();
    void pop_front();
    void push_front(T data);
    void removeAt(int index);
    void insert(T data,int index);
    void pop_back();
    void clear();
    void push_back(T data);
    int getSize(){ return Size;}
    T& operator[](const int index);
private:
    template<typename U> class Node
    {
    public:
        Node *pNext;
        U data;

        Node(U data = U(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;
};