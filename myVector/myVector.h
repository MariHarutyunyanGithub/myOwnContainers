#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <fstream>

class Vector
{
    public:
        Vector();
        Vector(const Vector&);
        Vector(const Vector&&);
        Vector(size_t);
        Vector(std::initializer_list<int>);
        ~Vector();

        Vector& operator=(const Vector&);
        Vector& operator=(const Vector&&);
        int& operator[](size_t);
        const int& operator[](size_t) const;
        Vector& operator+(Vector&);
        void operator+=(Vector&);
        friend std::ostream& operator<<(std::ostream& cout, const Vector& vec)
        {
            for (size_t i{}; i < vec.m_size; ++i) {
                cout << vec.m_buf[i] << " ";
            }
            cout << std::endl;
            return cout;
        }

        void push_back(const int);
        // void push_back(const int&&);
        void pop_back();
        void insert(size_t, const int&);
        void insert(size_t, const int&&);
        void remove_at(size_t);
        size_t find_by_value(const int&);
        size_t remove_by_value(const int&);
        bool empty() const;
        void clear();

        private:
            size_t m_size;
            size_t m_cap;
            int* m_buf;
};

#endif // VECTOR_H