//focus on just explaining not writing code as it is already written in the file. 


#include <iostream>
using namespace std;

template<typename T>
class MyVector {
private:
    T* start;
    T* finish;
    T* end_of_storage;

public:
    // 🔹 Constructor
    MyVector() : start(nullptr), finish(nullptr), end_of_storage(nullptr) {}

    // 🔹 Destructor
    ~MyVector() {
        clear();
        operator delete(start);
    }

    // 🔹 Size
    size_t size() const {
        return finish - start;
    }

    // 🔹 Capacity
    size_t capacity() const {
        return end_of_storage - start;
    }

    // 🔹 push_back (copy)
    void push_back(const T& value) {
        if (finish == end_of_storage) {
            reallocate();
        }
        new (finish) T(value);  // placement new
        finish++;
    }

    // 🔹 push_back (move)
    void push_back(T&& value) {
        if (finish == end_of_storage) {
            reallocate();
        }
        new (finish) T(std::move(value));  // move
        finish++;
    }

    // 🔹 operator[]
    T& operator[](size_t i) {
        return start[i];
    }

    // 🔹 clear
    void clear() {
        while (finish != start) {
            (--finish)->~T();
        }
    }

private:
    // 🔹 reallocate
    void reallocate() {
        size_t old_size = size();
        size_t new_capacity = (old_size == 0) ? 1 : old_size * 2;

        cout << "Reallocating: " << new_capacity << endl;

        T* new_start = (T*)operator new(sizeof(T) * new_capacity);

        // move old elements
        for (size_t i = 0; i < old_size; i++) {
            new (new_start + i) T(std::move(start[i]));
            start[i].~T();
        }

        operator delete(start);

        start = new_start;
        finish = start + old_size;
        end_of_storage = start + new_capacity;
    }
};


// 🔷 Test class to see copy/move
class Test {
public:
    int x;

    Test(int val) : x(val) {
        cout << "Constructor: " << x << endl;
    }

    Test(const Test& other) {
        x = other.x;
        cout << "Copy Constructor\n";
    }

    Test(Test&& other) {
        x = other.x;
        cout << "Move Constructor\n";
    }
};


// 🔷 MAIN FUNCTION
int main() {
    MyVector<Test> v;

    cout << "\n--- push_back temporary ---\n";
    v.push_back(Test(10));  // temp → move

    cout << "\n--- push_back object ---\n";
    Test t(20);
    v.push_back(t);  // copy

    cout << "\n--- more insertions (trigger reallocation) ---\n";
    v.push_back(Test(30));
    v.push_back(Test(40));

    cout << "\n--- Access elements ---\n";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i].x << " ";
    }

    cout << "\n";

    return 0;
}




