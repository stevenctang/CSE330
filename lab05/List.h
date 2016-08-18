#ifndef __Lab5__List__
#define __Lab5__List__

#include<algorithm>

using namespace std;

template<class T> class Link;
template<class T> class List_Iterator;

template <class T>
class List
{
public:
    typedef List_Iterator<T> iterator;

    List();
    List(const List<T> & l);
    ~List();

    bool empty() const;
    unsigned int size() const;
    T & back() const;
    T & front() const;
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    iterator begin() const;
    iterator end() const;
    void insert(iterator pos, const T & x); // insert x before pos
    void erase(iterator & pos);             // pos must be valid after erase() returns
    List<T> operator=(const List<T> & l);

protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
};


template<class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

template<class T>
List<T>::List(const List<T> & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for(Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current->value);

}

template<class T>
typename List<T>::iterator List<T>::begin() const
{
    return iterator(first_link);
}

template<class T>
typename List<T>::iterator List<T>::end() const
{
    return iterator(last_link);
}

template<class T>
List<T>::~List()
{
    while(!empty())
        pop_back();
}

template<class T>
bool List<T>::empty() const
{
    return my_size == 0;
}

template<class T>
unsigned int List<T>:: size() const
{
    return my_size;
}

template<class T>
T & List<T>::back() const
{
    return last_link->value;
}

template<class T>
T & List<T>::front() const
{
    return first_link->value;
}
template<class T>
void List<T>::push_back(const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link  == 0) {
        cout << "Out of memory\n";
        exit(1);
    }
    if(first_link == 0)
        first_link = last_link = new_link;
    else {
        new_link->prev_link=last_link;
        last_link->next_link = new_link;
        last_link = new_link;
    }
    my_size++;
}

template<class T>
void List<T>::push_front(const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link  == 0) {
        cout << "Out of memory\n";
        exit(1);
    }

    if(my_size == 0)
        last_link = first_link = new_link;
    else {
        new_link->next_link=first_link;
        first_link->prev_link = new_link;
        first_link = new_link;
    }
    my_size++;
}

template<class T>
void List<T>::erase(iterator & pos)
{
    Link<T> * next = pos.current_link->next_link;
    Link<T> * prev = pos.current_link->prev_link;
    if(next == 0)
        last_link = prev;
    if(prev == 0)
        first_link = next;
    else
        prev->next_link=next;
    delete pos.current_link;
    my_size--;
    pos.current_link = next;
}

template<class T>
void List<T>::insert(iterator pos, const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    Link<T> * next = pos.current_link->next_link;
    Link<T> * prev = pos.current_link->prev_link;
    if (pos == begin()) {
        push_front(x);
    } else if(pos == end()) {
        new_link->next_link = last_link;
        new_link->prev_link = prev;
        prev->next_link = new_link;
        last_link->prev_link = new_link;
        prev = new_link;
        my_size++;
    } else {
        new_link->next_link = next;
        new_link->prev_link = prev;
        prev->next_link = new_link;
        next->prev_link = new_link;
        pos = new_link;
        my_size++;
    }
}

template<class T>
void List<T>::pop_front()
{
    first_link= first_link->next_link;
    first_link->prev_link = NULL;
    my_size--;

}

template<class T>
void List<T>::pop_back()
{

    if(my_size == 0) return;

    if(my_size == 1) {
        first_link = NULL;
        last_link = NULL;
        my_size = 0;
        return;
    }
    last_link = last_link->prev_link;
    last_link->next_link = NULL;
    my_size--;


}


template<class T>
class Link
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) { }

    T value;
    Link<T> * next_link;
    Link<T> * prev_link;

    friend class List<T>;
    friend class List_Iterator<T>;
};

template<class T> class List_Iterator
{
public:
    typedef List_Iterator<T> iterator;

    List_Iterator(Link<T> * source_link): current_link(source_link) { }
    List_Iterator(): current_link(0) { }
    List_Iterator(List_Iterator<T> * source_iterator): current_link(source_iterator) { }

    T & operator *();
    iterator & operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator!=(const iterator & rhs) const;
    iterator & operator++();
    iterator operator++(int);
    iterator & operator--();
    iterator operator--(int);

protected:
    Link<T> * current_link;
    friend class List<T>;
};

template<class T>
T & List_Iterator<T>::operator*()
{
    return current_link->value;
}

template<class T>
List_Iterator<T> & List_Iterator<T>::operator++()
{
    current_link = current_link -> next_link;
    return *this;
}

template<class T>
List_Iterator<T> List_Iterator<T>::operator++(int)
{
    List_Iterator<T> copy(current_link);
    current_link->current_link->next_link;
    return copy;
}

template <class T>
List_Iterator<T> & List_Iterator<T>::operator--()
{
    current_link = current_link->last_link->prev_link;
    return *this;
}

template <class T>
List_Iterator<T>  List_Iterator<T>::operator--(int)
{
    List_Iterator<T> copy(current_link);
    current_link->current_link->last_link->prev_link;
    return copy;
}

template<class T>
List_Iterator<T> & List_Iterator<T>::operator=(const iterator & rhs)
{
    current_link = rhs.current_link;
    return *this;
}

template<class T>
bool List_Iterator<T>::operator==(const iterator & rhs) const
{
    if(current_link == rhs.current_link)
        return true;
    return false;

}


template<class T>
bool List_Iterator<T>::operator!=(const iterator & rhs) const
{

    if(current_link != rhs.current_link->next_link)
        return true;
    return false;

}





#endif /* defined(__Lab5__List__) */
