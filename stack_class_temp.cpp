#include <iostream>
 
template <typename T> 
class stack
{
    private:
        T* m_arr;
        int m_top;
        int m_capacity;
    public:
        stack(int size);
        void push(T);
        T pop();
        T top();
        
        int size();
        bool empty();
        
        ~stack()
        {
            delete [] m_arr;
        }
};
 
template <typename T>
stack<T>::stack(int size)
{
    m_arr = new T[size];
    m_capacity = size;
    m_top = -1;
}
 
template <typename T>
void stack<T>::push (T elem)
{
    if(size() == m_capacity)
    {
        std::cout << "Stack overflow\n";
        exit(EXIT_FAILURE);
    }
    m_arr[++m_top] = elem;
    std::cout << "Inserting element is: " << elem << '\n';
}

template <typename T>
T stack<T>::pop()
{
    if(empty())
    {
        std::cout << "Stack underflow\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "Removing element is: " << m_arr[m_top] << '\n';
    return m_arr[m_top--];
}

template <typename T>
int stack<T>::size()
{
    return m_top + 1;
}

template <typename T>
T stack<T>::top()
{
    if (!empty())
    {
        return m_arr[m_top];
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

template <typename T>
bool stack<T>::empty()
{
    return size() == 0;
}


int main()
{
    stack<int> a(3);
    a.push(1);
    a.push(3);
    a.push(5);
    std::cout << '\n';
    
    a.pop();
    std::cout << '\n';
   
    std::cout << "The stack size is: " << a.size() << "\n\n";
    a.push(7);
    std::cout << '\n';
    std::cout << "The top element is: " << a.top() << std::endl;
    std::cout << '\n';
    std::cout << "The stack size is: " << a.size() << std::endl;
    std::cout << '\n';
    
    if (a.empty()) {
        std::cout << "The stack is empty\n";
    }
    else {
        std::cout << "The stack is not empty\n";
    }
}



