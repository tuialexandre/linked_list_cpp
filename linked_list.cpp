#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node() {}
    Node(const int &value)
    {
        this->value = value;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void push(const int &value);
    void delete_last();
    void insert(const int &index, const int &value);
    void delete_position(const int &index);
    void print();
};

void LinkedList::push(const int &value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

void LinkedList::delete_last()
{
    if (head != NULL)
    {
        Node *current = new Node;
        Node *new_tail = new Node;
        current = head;
        while (current->next != NULL)
        {
            new_tail = current;
            current = current->next;
        }
        new_tail->next = NULL;
        tail = new_tail;
        delete current;
    }
    else if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
}

void LinkedList::insert(const int &index, const int &value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        int current_index = 0;
        Node *current_node = new Node;
        Node *previous_node = new Node;
        current_node = head;
        while (current_index < index && current_node != NULL)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        if (current_node == NULL)
        {
            tail->next = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = current_node;
            previous_node->next = new_node;
        }
    }
}

void LinkedList::delete_position(const int &index)
{
    if (head != NULL)
    {
        int current_index = 0;
        Node *current_node = new Node;
        Node *previous_node = new Node;
        current_node = head;
        while (current_index < index && current_node != tail)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        if (current_node == tail)
        {
            previous_node->next = NULL;
            tail = previous_node;
        }
        else
        {
            previous_node->next = current_node->next;
        }
        delete current_node;
    }
}

void LinkedList::print()
{
    Node *current = new Node;
    current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int test_values[5] = {2, 3, 4, 1, 7};
    LinkedList my_list;

    for (int i = 0; i < sizeof(test_values) / sizeof(*test_values); i++)
    {
        my_list.push(test_values[i]);
    }

    cout << "Initial list: " << endl;
    my_list.print();
    cout << "Delete last value: " << endl;
    my_list.delete_last();
    my_list.print();
    cout << "Inserting value 2 in index 1: " << endl;
    my_list.insert(1, 2);
    my_list.print();
    cout << "Deleting index 3: " << endl;
    my_list.delete_position(3);
    my_list.print();

    return 0;
}