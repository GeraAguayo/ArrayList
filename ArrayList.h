#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

template <typename T>
class ArrayList {
    private:
        T* data;
        size_t capacity; //Max number of values the array can hold
        size_t length; //Current n of values stored
    public:

        //Empty constructor
        ArrayList()
        : data{nullptr}, capacity{2}, length{0} {
            data = new T[this->capacity];
            std::cout << "Empty constructor - ArrayList with " << this->capacity << " created at " << &this->data << std::endl;
        }

        //Constructor with arraylist size indicated
        ArrayList(size_t in_capacity)
            : data{nullptr}, capacity(in_capacity), length(0) {
            data = new T[this->capacity];
            std::cout << "Capacity constructor - ArrayList with " << this->capacity << " created at " << &this->data << std::endl;

        }

        //Destructor
        ~ArrayList() {
            delete[] data;
            std::cout << "ArrayList destroyed\n";
        }

        //Push a value to the arraylist
        void push(T value) {
            if (this->length < capacity) {
                //Space available
                this->data[this->length] = value;
                this->length++;
            }
            else {
                //Resize array
                std::cout << "Resizing array\n";
                resize();
                push(value);
            }
        }

        //Resize arraylist to double capacity
        void resize() {
            size_t new_capacity = this->capacity * 2;
            T* new_data;
            new_data = new T[new_capacity];
            //Copy all elements to new array
            for (size_t i = 0; i < this->capacity; i++) {
                new_data[i] = this->data[i];
            }
            this->data = new_data;
            this->length = this->capacity;
            this->capacity = new_capacity;
        }

        //Removes an element at any given index
        void remove(int index) {
            if (index < this->length) {
                for (int i = index; i < this->length; i++) {
                    if (i == this->length-1) {
                        //Loop reaches final element, set to zero and change len
                        this->data[i] = 0;
                        this->length-=1;
                    }
                    else {
                        //Change value to the next one
                        this->data[i] = this->data[i+1];
                    }
                }
            }
            else {
                std::cerr << "Index out of bounds remove()\n";
            }
        }

        //Returns current number of value stored
        size_t len() {
            return this->length;
        }

        //Returns arraylist capacity
        size_t max_len() {
            return this->capacity;
        }

        T at(int index){
            if (index < this->length) {
                return data[index];
            }
            std::cerr << "Index out of bounds at()\n";
        }

};



#endif //ARRAYLIST_H
