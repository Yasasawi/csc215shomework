/** **************************************************************************
 * @file    
 *
 * @brief   The declaration of the singly linked list for a list that
 *          is sorted.
 ****************************************************************************/
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::nothrow;
/** **************************************************************************
 * @class   sortedSingle
 *
 * @brief   A sorted singly linked list of integers.
 ****************************************************************************/
template<class TY>
class sortedSingle
{
public:
    // new
    void swap(sortedSingle<TY>& l);
    sortedSingle<TY>& operator=(sortedSingle<TY>& rhs);
    bool operator==(const sortedSingle<TY>& rhs) const;
    bool operator!=(const sortedSingle<TY>& rhs) const;
    template <class TY>
    friend ostream& operator<<(ostream& out, sortedSingle<TY>& l);

    // do not write.
    sortedSingle(sortedSingle<TY>& l);

    // file sortedSinglea.cpp
    sortedSingle();
    ~sortedSingle();
    bool find(TY item);
    int retrievePosition(TY item);
    int size();
    bool empty();

    // file sortedSingleb.cpp
    bool insert(TY item);
    void print(ostream& out, string seperator = ", ");

    // file sortedSinglec.cpp
    bool remove(TY item);
    void clear();


private:

    /**
     * @brief  the storage container for each item in the list
     */
    struct node
    {
        TY theItem;    /*!< the item */
        node* next;     /*!< pointer to the remaining nodes in list */
    };
    node* headptr;      /*!< The location of the first node in the list */
};

template <class TY>
void sortedSingle<TY>::swap(sortedSingle<TY>& l)
{
    node* temp;
    temp = headptr; 
    headptr = l.headptr;
    l.headptr = temp; 
}

template <class TY>
sortedSingle<TY>& sortedSingle<TY>::operator=(sortedSingle<TY>& rhs)
{
    sortedSingle<TY> tempList(rhs);
    std::swap(tempList.headptr, headptr);
    return *this;
}

template<class TY>
bool sortedSingle<TY>::operator==(const sortedSingle<TY>& rhs) const
{
    node* temp = headptr;
    node* main = rhs.headptr; 
    while (temp != nullptr && main != nullptr)
    {
        if (temp->theItem != main->theItem)
        {
            return false;
        }
        temp = temp->next;
        main = main->next;
    }
    if (temp != nullptr && main == nullptr)
    {
        return false;
    }
    if (temp == nullptr && main != nullptr)
    {
        return false;
    }
    return true; 
}

template<class TY>
bool sortedSingle<TY>::operator!=(const sortedSingle<TY>& rhs) const
{
    node* temp = headptr;
    node* main = rhs.headptr;
    while (temp != nullptr && main != nullptr)
    {
        if (temp->theItem != main->theItem)
        {
            return true; 
        }
        temp = temp->next;
        main = main->next;
    }
    if (temp != nullptr && main == nullptr)
    {
        return true;
    }
    if (temp == nullptr && main != nullptr)
    {
        return true;
    }
    return false; 
}

template <class TY>
sortedSingle<TY>::sortedSingle()
{
    headptr = nullptr; 
}

template <class TY>
sortedSingle<TY>::~sortedSingle()
{
    clear();
}

template <class TY>
bool sortedSingle<TY>::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }
    else
    {
        return false; 
    }
}

template <class TY>
int sortedSingle<TY>::size()
{
    node* temp = headptr; 
    int size = 0;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template <class TY>
bool sortedSingle<TY>::find(TY item)
{
    node* temp = headptr;
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class TY>
int sortedSingle<TY>::retrievePosition(TY item)
{
    node* temp = headptr;
    int i = 1;
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return 0;
}

template <class TY>
bool sortedSingle<TY>::insert(TY item)
{
    node* temp;
    node* insert;
    insert = new(nothrow) node;
    insert->theItem = item;

    temp = headptr;

    if (headptr == nullptr || headptr->theItem >= item)
    {
        insert->next = headptr;
        headptr = insert;
        return true;
    }

    while (temp->next != nullptr && temp->next->theItem < item)
    {
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;

    return true;
}

template <class TY>
void sortedSingle<TY>::print(ostream& out, string seperator)
{
    node* temp;
    temp = headptr;
    while (temp != nullptr)
    {
        if (temp->next == nullptr)
        {
            out << temp->theItem;
        }
        else
        {
            out << temp->theItem << seperator;
        }
        temp = temp->next;
    }
}

template <class TY>
bool sortedSingle<TY>::remove(TY item)
{
    node* temp;
    node* prev;
    temp = headptr;
    prev = nullptr;

    if (headptr == nullptr)
    {
        return false;
    }

    if (temp->theItem == item)
    {
        headptr = temp->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->theItem != item)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return false;
    }

    prev->next = temp->next;

    delete temp;
    return true;
}

template <class TY>
void sortedSingle<TY>::clear()
{
    node* temp;
    node* next;
    next = nullptr;
    temp = headptr;

    if (headptr == nullptr)
    {
        return;
    }
    while (temp != nullptr)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    headptr = nullptr;
}

template <class TY>
sortedSingle<TY>::sortedSingle(sortedSingle& l)
{
    node* src;
    node* dest;

    // handle copying an empty list
    headptr = nullptr;
    if (l.empty() == true)
        return;


    // attach the first node
    headptr = new(nothrow) node;
    headptr->theItem = l.headptr->theItem;
    headptr->next = nullptr;

    // attach the remaining node
    dest = headptr;
    src = l.headptr->next;
    while (src != nullptr)
    {
        dest->next = new(nothrow) node;
        dest = dest->next;
        dest->theItem = src->theItem;
        src = src->next;
    }
    dest->next = nullptr;
}

template<class TY>
ostream& operator<<(ostream& out, sortedSingle<TY>& l)
{
    l.print(out, " ");
    return out;
}
