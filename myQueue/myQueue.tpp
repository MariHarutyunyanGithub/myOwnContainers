template <typename T>
MyQueue<T>::MyQueue() :list(new MyList<T>()), top(-1), count(0) 
{
    list->setHead(nullptr);
}

template <typename T>
MyQueue<T>::~MyQueue()
{
    list = nullptr;
}

template <typename T>
void MyQueue<T>::push(T value)
{
    list->push_back(value);
}

template <typename T>
void MyQueue<T>::pop()
{
    if (list->isEmpty()) {
        std::cout << "Queue is empty. Cannot pop." << std::endl;
        return;
    }
    list->pop_front();
}

template <typename T>
T MyQueue<T>::peek()
{
    if (list->isEmpty()) {
        std::cout << "Queue is empty. No top element." << std::endl;
        return T();
    }
    return list->getHead()->getItem();
}

template <typename T>
const T& MyQueue<T>::peek() const
{
    if (list->isEmpty()) {
        std::cout << "Queue is empty. No top element." << std::endl;
        return T();
    }
    return list->getHead()->getItem();
}

template <typename T>
int MyQueue<T>::size() const
{
    return list->getItemCount();
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
    return list->isEmpty();
}

template <typename T>
void MyQueue<T>::clear()
{
    list->clear();
}
