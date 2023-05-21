template <typename T>
MyList<T>:: MyList(): head(nullptr), tail(nullptr), itemCount(0) {}

template<typename T>
MyList<T>::MyList(const T& anItem) : itemCount(1)
{
    head = new Node<T>();
    head->setItem(anItem);
    head->setNext(nullptr);
    head->setPrev(nullptr);
    tail = head;
}

template<typename T>
MyList<T>::MyList(const MyList& other) :
            itemCount{other.itemCount}
{
    head = nullptr;
    tail = nullptr;
    Node<T>* lastNode = nullptr;
    Node<T>* otherNode = other.head;
    for(;otherNode; otherNode = otherNode->getNext())
    {
        Node<T>* newNode = new Node<T>;
        newNode->setItem(otherNode->getItem());
        newNode->setPrev(otherNode->getPrev());
        newNode->setNext(nullptr);
        if (!head) {
            head = newNode;
        } else {
            lastNode->setNext(newNode);
            newNode->setPrev(lastNode);
        }
        lastNode = newNode;
    }
    tail = lastNode;
}

template<typename T>
MyList<T>::MyList(MyList&& other) :
            itemCount{other.itemCount}
{
    if (other.head) {
       head = other.head;
       tail = other.tail;
       other.head = nullptr;
       other.tail = nullptr;
    }
}

template<typename T>        
MyList<T>::~MyList()  
{
    Node<T>* current = head;
    while(current) {
        Node<T>* tmp = current;
        current = current->getNext();
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}  

template<typename T>
MyList<T>& MyList<T>::operator=(const MyList& other)
{
    if (head == other.head) {
        return *this;
    }
    if (other.head) {
        itemCount = other.itemCount;
        head = other.head;  
        tail = other.tail;      
    }
    return *this;
}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList&& other)
{
    if (head == other.head) {
        return *this;
    }
    if (other.head) {
        itemCount = other.itemCount;   
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template<typename T>
MyList<T> MyList<T>::operator+(const MyList& other)
{
    if (!other.head) {
        return *this;
    }
    MyList<T> result;
    Node<T>* newNodeptr = new Node<T>();
    result.head = newNodeptr;
    Node<T>* current2 = result.head;
    Node<T>* current = head;
    Node<T>* current1 = other.head;
    result.itemCount = itemCount + other.itemCount;
    
    while ((current) && (current1)) {
        current2->setItem(current->getItem() + current1->getItem());
        Node<T>* nextNodeptr = new Node<T>();
        current2->setNext(nextNodeptr);
        current2->getNext()->setPrev(current2);
        current2 = current2->getNext();
        current = current->getNext();
        current1 = current1->getNext();
    }
    
    Node<T>* remainingNodes = current ? current : current1;
    if (remainingNodes) {
        current2->setItem(remainingNodes->getItem());
        current2->setNext(remainingNodes->getNext());
        current2->getNext()->setPrev(current2);
        remainingNodes = remainingNodes->getNext();
        current2 = current2->getNext();
        while (remainingNodes) {
            current2->setItem(remainingNodes->getItem());
            current2->setNext(remainingNodes->getNext());
            current2->getNext()->setPrev(current2);
            remainingNodes = remainingNodes->getNext();
            if (remainingNodes) {
                Node<T>* nextNodeptr = new Node<T>();
                current2->setNext(nextNodeptr);
                current2->getNext()->setPrev(current2);
                current2 = current2->getNext();
            }
        }
    }
    result.tail = current2 ? current2->getPrev() : newNodeptr;
    if (result.tail) {
        result.tail->setNext(nullptr);
    }    
    return result;
}


template<typename T>
MyList<T> MyList<T>::operator+=(const MyList& other)
{
    if (other.isEmpty()) {
        return *this;
    }
    if (isEmpty()) {
        head = other.head;
        tail = other.tail;
    } else {
        tail->setNext(other.head);
        other.head->setPrev(tail);
        tail = other.tail;
    }
    itemCount += other.itemCount;
    return *this;
}

template<typename T>
bool MyList<T>::insert(int position, const T& element)
{
    bool ableToInsert = (position > 0) && (position <= itemCount + 1);
    if (ableToInsert) {
        Node<T>* newNodePtr = new Node<T>(element);
        if (position == 1) {
            push_front(element);
        }
        else if (position == itemCount + 1) {
            push_back(element);
        }
        else if (position <= itemCount / 2) {
            Node<T>* tmpPtr  = head;
            for (int i{1}; i < position - 1; ++i) {
                tmpPtr = tmpPtr->getNext();
            }
            Node<T>* ptr = tmpPtr->getNext();
            ptr->setPrev(newNodePtr);
            tmpPtr->setNext(newNodePtr);
            newNodePtr->setPrev(tmpPtr);
            newNodePtr->setNext(ptr); 
            itemCount++;           
        }
        else {
            Node<T>* tmpPtr  = tail;
            for (int i = itemCount; i > position; --i) {
                tmpPtr = tmpPtr->getPrev();
            }
            Node<T>* ptr = tmpPtr->getPrev();
            ptr->setNext(newNodePtr);
            tmpPtr->setPrev(newNodePtr);
            newNodePtr->setNext(tmpPtr);
            newNodePtr->setPrev(ptr);  
            itemCount++; 
        }
    }
    return ableToInsert;
}

template<typename T>
MyList<T>& MyList<T>::push_front(const T& entry)
{
    // insert(1,entry);
    Node<T>* newNodePtr = new Node<T>(entry);
    newNodePtr->setNext(head);
    if (head) {
        head->setPrev(newNodePtr);
    }
    head = newNodePtr;
    ++itemCount;
    return *this;
}

template <typename T>
MyList<T>& MyList<T>::push_back(const T& entry)
{
    // insert(itemCount + 1, entry);
    Node<T>* newNodePtr = new Node<T>(entry);
    tail->setNext(newNodePtr);
    newNodePtr->setPrev(tail);
    tail = tail->getNext();
    ++itemCount;
    return *this;
}

template <typename T>
void MyList<T>::pop_front()
{
    remove_at(1);
}

template <typename T>
void MyList<T>::pop_back()
{
    remove_at(itemCount);
}

template<typename T>
bool MyList<T>::remove_at(int position)
{
    bool ableToRemove = (position > 0) && (position <= itemCount);
    if (ableToRemove) {
        if (itemCount == 1) {
            head = tail = nullptr;
        }
        else if (position == 1) {
            Node<T>* tmpptr = head;
            head = tmpptr->getNext();
            head->setPrev(nullptr);
            delete tmpptr;
            tmpptr = nullptr;
        }
        else if (position == itemCount) {
            Node<T>* tmpptr = tail;
            tail = tail->getPrev();
            tail->setNext(nullptr);
            delete tmpptr;
            tmpptr = nullptr;
        }
        else if (position <= itemCount / 2) {
            Node<T>* tmphead = head;
            for (int i{1}; i < position - 1; ++i) {
                tmphead = tmphead->getNext();
            }
            Node<T>* tmpPtr = tmphead->getNext();
            tmphead->setNext(tmpPtr->getNext());
            tmpPtr->getNext()->setPrev(tmphead);
            delete tmpPtr;
            tmpPtr = nullptr;
        }
        else {
            Node<T>* tmptail = tail;
            for (int i{itemCount}; i > position; --i) {
                tmptail = tmptail->getPrev();
            }
            Node<T>* tmpPtr = tmptail->getPrev();
            tmpPtr->setNext(tmptail->getNext());
            tmptail->getNext()->setPrev(tmpPtr);
            delete tmptail;
            tmptail = nullptr;
        }
        --itemCount;
    }
    return ableToRemove;
}

template <typename T>
bool MyList<T>::remove(T& lvalue)
{
    if(!head) {
        return false;
    }
    if (head->getItem() == lvalue) {
        Node<T>* tmpPtr = head;
        head = head->getNext();
        delete tmpPtr;
        head->setPrev(nullptr);
    } else {
        Node<T>* current = head;
        for (int i{1}; i < itemCount; ++i) {
            if (current->getNext()->getItem() == lvalue) {
                Node<T>* tmp = current->getNext();
                current->setNext(tmp->getNext());
                current->getNext()->setPrev(current);
                delete tmp;
                return true;
            }
            current = current->getNext();
        } 
        return false;
    }
    return true;
}

template <typename T>
bool MyList<T>::remove(T&& rvalue)
{
    if(!head) {
        return false;
    }
    if (head->getItem() == rvalue) {
        Node<T>* tmpPtr = head;
        head = head->getNext();
        delete tmpPtr;
        head->setPrev(nullptr);
    } else {
        Node<T>* current = head;
        for (int i{1}; i < itemCount; ++i) {
            if (current->getNext()->getItem() == rvalue) {
                Node<T>* tmp = current->getNext();
                current->setNext(tmp->getNext());
                if (current->getNext()) {
                    current->getNext()->setPrev(current);
                }                
                delete tmp;
                return true;
            }
            current = current->getNext();
        } 
        return false;
    }
    return true;
}

template<typename T>
bool MyList<T>::isEmpty() const
{
    return !(itemCount);
}

template<typename T>
void MyList<T>::clear()
{
    Node<T>* current = head;
    Node<T>* next = head->getNext();
    while (current) {
        next = current->getNext();
        delete current;
        current = next;
    }
    itemCount = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
T MyList<T>::getEntry(int position)
{
    bool ableToGet = (position > 0) && (position <= itemCount);
    if (ableToGet) {
        Node<T>* tmphead = head;
        for (int i{1}; i < position; ++i) {
            tmphead = tmphead->getNext();
        }
        T item = tmphead->getItem();
        tmphead = nullptr;
        return item;
    }
    throw "bad position";
}

template<typename T>
bool MyList<T>::setEntry(int position, const T& entry)
{
    bool ableToSet = (position > 0) && (position <= itemCount + 1);
    if (ableToSet) {
        Node<T>* tmphead = head;
        for (int i{1}; i < position; ++i) {
            tmphead = tmphead->getNext();
        }
        tmphead->setItem(entry);
        tmphead = nullptr;
    }
    return ableToSet;
}

template <typename T>
void MyList<T>::setHead(Node<T>* ptr)
{
    head = ptr;
}

template <typename T>
Node<T>* MyList<T>::getHead()
{
    return head;
}

template <typename T>
void MyList<T>::setTail(Node<T>* ptr)
{
    tail = ptr;
}

template <typename T>
Node<T>* MyList<T>::getTail() const
{
    return tail;
}

template<typename T>
int MyList<T>::getItemCount() const
{
    return itemCount;
}