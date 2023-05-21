template <typename T>
FList<T>::FList() : head(nullptr), itemCount(0){}

template<typename T>
FList<T>::FList(const T& anItem) : itemCount(1)
{
    head = new Node<T>();
    head->setItem(anItem);
    head->setNext(nullptr);
}

template<typename T>
FList<T>::FList(const FList& other) :
            itemCount{other.itemCount}
{
    head = nullptr;
    Node<T>* prevNode = nullptr;
    Node<T>* otherNode = other.head;
    for(;otherNode != nullptr; otherNode = otherNode->getNext())
    {
        Node<T>* newNode = new Node<T>;
        newNode->setItem(otherNode->getItem());
        newNode->setNext(nullptr);
        if (!head) {
            head = newNode;
        }
        else {
            prevNode->setNext(newNode);
        }
        prevNode = newNode;
    }
}

template<typename T>
FList<T>::FList(FList&& other) :
            itemCount{other.itemCount}
{
    if (other.head != nullptr) {
       head = other.head;
       other.head = nullptr;
    }
}

template<typename T>        
FList<T>::~FList()  
{
    Node<T>* current = head;
    while(current != nullptr) {
        Node<T>* tmp = current;
        current = current->getNext();
        delete tmp;
    }
    head = nullptr;
}  

template<typename T>
FList<T>& FList<T>::operator=(const FList& other)
{
    if (head == other.head) {
        return *this;
    }
    if (other.head != nullptr) {
        itemCount = other.itemCount;

        head = other.head;        
    }
    return *this;
}

template<typename T>
FList<T>& FList<T>::operator=(FList&& other)
{
    if (head == other.head) {
        return *this;
    }
    if (other.head != nullptr) {
        itemCount = other.itemCount;   
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

template<typename T>
FList<T> FList<T>::operator+(const FList& other)
{
    if (other.head == nullptr) {
        return *this;
    }
    FList<T> result;
    Node<T>* newNodeptr = new Node<T>(); 
    result.head = newNodeptr;
    Node<T>* current2 = result.head;
    Node<T>* current = head;
    Node<T>* current1 = other.head;
   
    result.itemCount = itemCount > other.itemCount ? itemCount : other.itemCount;
    while ((current) && (current1)) {
        current2->setItem(current->getItem() + current1->getItem());  
        Node<T>* nextNodeptr = new Node<T>();
        current2->setNext(nextNodeptr);               
        current2 = current2->getNext(); 
        current = current->getNext(); 
        current1 = current1->getNext();         
    }
    if (current1) {
        current2->setNext(current1);
    }
    if(current) {
        current2->setNext(current);
    }
    return result;
}

template<typename T>
FList<T>& FList<T>::operator+=(const FList& other)
{
    if (other.head == nullptr) {
        return *this;
    }
    if (head == nullptr) {
        head = other.head;
        itemCount = other.itemCount;
        return *this;
    }
    itemCount += other.itemCount;
    Node<T>* current = head;
    while (current->getNext()) {
        current = current->getNext();
    }
    current->setNext(other.head);
    return *this;
}

template<typename T>
bool FList<T>::insert(int position, const T& entry)
{
    bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
    if (ableToInsert) {
        Node<T>* newNodePtr = new Node<T>(entry);
        if (position == 1) {
            newNodePtr->setNext(head);
            head = newNodePtr;
        }
        else {
            Node<T>* tmpPtr  = head;
            for (int i{1}; i < position - 1; ++i) {
                tmpPtr = tmpPtr->getNext();
            }
            Node<T>* nxt = tmpPtr->getNext();
            tmpPtr->setNext(newNodePtr);
            newNodePtr->setNext(nxt);
            
        }
        itemCount++;
    }
    return ableToInsert;
}

template<typename T>
FList<T>& FList<T>::push_front(const T& entry)
{
    Node<T>* newNodePtr = new Node<T>(entry);
        if (head == nullptr) {
            head = newNodePtr;
            newNodePtr->setNext(nullptr);
        }
        else {
            insert(1,entry);
        }
    itemCount++;
    return *this;
}

template<typename T>
bool FList<T>::remove_at(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount + 1);
    if (ableToRemove) {
        if (itemCount == 1) {
            head = nullptr;
        }
        else {
            Node<T>* tmphead = head;
            for (int i{1}; i < position - 1; ++i) {
                head = head->getNext();
            }
            Node<T>* tmpPtr = head->getNext();
            head->setNext(head->getNext()->getNext());
            tmpPtr = nullptr;
            head = tmphead;
        }
        --itemCount;
    }
    return ableToRemove;
}

template<typename T>
bool FList<T>::isEmpty() const
{
    return !(itemCount);
}

template<typename T>
void FList<T>::clear()
{
    itemCount = 0;
    head = nullptr;
}

template<typename T>
T FList<T>::getEntry(int position)
{
    bool ableToGet = (position >= 1) && (position <= itemCount + 1);
    if (ableToGet) {
        Node<T>* tmphead = head;
        for (int i{1}; i < position; ++i) {
            head = head->getNext();
        }
        T item = head->getItem();
        head = tmphead;
        tmphead = nullptr;
        return item;
    }
    throw "bad position";
}

template<typename T>
void FList<T>::setEntry(int position, const T& entry)
{
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet) {
        Node<T>* tmphead = head;
        for (int i{1}; i < position; ++i) {
            head = head->getNext();
        }
        head->setItem(entry);
        head = tmphead;
        tmphead = nullptr;
    }
}

template <typename T>
Node<T>* FList<T>::getHead() const
{
    return head;
}

template<typename T>
void FList<T>::setHead(Node<T>* newPtr)
{
    head = newPtr;
}


template<typename T>
int FList<T>::getItemCount() const
{
    return itemCount;
}

template<typename T>
void FList<T>::setItemCount(int count)
{
    itemCount = count;
}
