template <typename T>
Node<T>::Node() : prev(nullptr), next(nullptr), item(0) {}

template<typename T>
Node<T>::Node(const T& anItem) : item(anItem), prev(nullptr), next(nullptr) {}

template<typename T>
Node<T>::Node(const T& anItem, Node<T>* prevNodePtr, Node<T>* nextNodePtr)
{
    item = anItem;
    prev = prevNodePtr;
    next = nextNodePtr;
}

template<typename T>
Node<T>::~Node()
{
    prev = nullptr;
    next = nullptr;
}

template<typename T>
void Node<T>::setItem(const T& anItem)
{   
    item = anItem;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prevNodePtr)
{
    prev = prevNodePtr;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
    next = nextNodePtr;
}

template<typename T>
T Node<T>::getItem() const
{
    return item;
}

template<typename T>
Node<T>* Node<T>::getPrev() const
{
    return prev;
}

template<typename T>
Node<T>* Node<T>::getNext() const
{
    return next;
}
