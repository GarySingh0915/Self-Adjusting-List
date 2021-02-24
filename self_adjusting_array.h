//Name: Gurnaman Singh
//Date: 2/15/2021
//Assignment: HW3 Self Adjusting List
//This program is used for performing sort operations that specifically finds a given element and inserts it at the front using Move-To-Front Method
#ifndef self_adjusting_array_H
#define self_adjusting_array_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace nwacc {

	template <typename T>
	class self_adjusting_array {
	public:
		explicit self_adjusting_array(size_t initial_size = 14) :
			my_size{ 0 }, my_capacity{ initial_size + 2 }
		{
			this->data = new T[this->my_capacity];
			std::cout << "CALLING DEFAULT CONSTRUCTOR...\n";
		}

		self_adjusting_array(const self_adjusting_array& other) : // Copy constructor. 
			my_size{ other.my_size }, my_capacity{ other.my_capacity }, data{ nullptr }
		{
			this->data = new T[this->my_capacity];
			for (auto index = 0U; index < this->my_size; index++) {
				this->data[index] = other.data[index];
			} // remember, we are making a copy, NOT move. I do not want to destroy the other list!
			std::cout << "CALLING COPY CONSTRUCTOR...\n";
		}

		self_adjusting_array(self_adjusting_array&& other) : // Move constructor (other will be destroyed!) 
			my_size{ other.my_size }, my_capacity{ other.my_capacity }, data{ other.data }
		{

			other.data = nullptr;
			other.my_size = 0U;
			other.my_capacity = 0U;

			std::cout << "CALLING MOVE CONSTRUCTOR...\n";
		}

		self_adjusting_array& operator=(const self_adjusting_array& rhs)
		{
			std::cout << "CALLING COPY ASSIGNMENT OPERATOR...\n";
			auto copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		self_adjusting_array& operator=(self_adjusting_array&& rhs) // Move assignment operator
		{
			std::cout << "CALLING MOVE ASSIGNMENT OPERATOR...\n";
			std::swap(this->my_size, rhs.my_size);
			std::swap(this->my_capacity, rhs.my_capacity);
			std::swap(this->data, rhs.data);
			return *this;
		}

		~self_adjusting_array() // destructor
		{
			delete[] this->data;
			std::cout << "CALLING DESTRUCTOR TO DELETE this->data...\n";
		}

		T& operator[](int index)
		{
			// TODO ADD exception for index out of range. 
			return this->data[index];
		}

		const T& operator[](int index) const
		{
			// TODO ADD exception for index out of range.
			return this->data[index];
		}

		bool empty() const
		{
			return this->my_size == 0;
		}

		size_t size() const
		{
			return this->my_size;
		}

		void reserve(int new_capacity)
		{
			if (new_capacity < this->my_size) {
				return;
			} // else, the new capacity will increase beyond the current size, do_nothing();

			T* new_data = new T[new_capacity];
			for (auto index = 0U; index < this->my_size; index++) {
				new_data[index] = std::move(this->data[index]);
			}

			this->my_capacity = new_capacity;
			std::swap(this->data, new_data);
			delete[] new_data;
		}
		void push_front(const T& value)
		{
			if (this->my_size == this->my_capacity) {
				this->reserve((this->my_capacity * 3) / 2);
			}
			//This for loop runs through all elements of this->data and shifts them to the right one place relatively.
			for (auto index = this->my_size; index > 0U; index--) {
				this->data[index] = std::move(this->data[index - 1]);
			}
			// Set first element to value
			this->data[0U] = value;
			++this->my_size;
		}
		//Similarly to push_front, the emplace_front is more efficient because it uses std::move operation to shift data across data members.
		void emplace_front(const T&& value)
		{
			if (this->my_size == this->my_capacity) {
				this->reserve((this->my_capacity * 3) / 2);
			}
			for (auto index = this->my_size; index > 0U; index--) {
				this->data[index] = std::move(this->data[index - 1]);
			}
			this->data[0U] = std::move(value);
			++this->my_size;
		}

		// pop_front() job is to remove the element from the beginning of the arraylist
		void pop_front()
		{
			if (this->empty()) {
				throw std::out_of_range("list is empty");
			}
			//This for loop runs through all elements of this->data and shifts them to the left one place relatively.
			for (auto index = 0U; index < (this->my_size) - 1; index++) {
				this->data[index] = std::move(this->data[index + 1]);
			}
			--this->my_size;
		}

		const T& front() const
		{
			if (this->empty()) {
				throw std::out_of_range("list is empty");
			}
			return this->data[0U];
		}
		//This is the find function that basically takes the value given by the user to the front by swapping all the values at the beginning
		//For example, an arraylist (int) - 1 2 3 4 5 6. Find(5) should become 5 1 2 3 4 6. Values before 5 are shifted to the right.
		void find(const T& value)
		{
			for (auto find_index = 0; find_index < this->my_size; find_index++) {
				if (value == this->data[find_index]) {
					for (auto initial_value = 0; initial_value < find_index; initial_value++) {	
						auto temp = std::move(this->data[find_index]);
						this->data[find_index] = std::move(this->data[initial_value]);
						this->data[initial_value] = std::move(temp);
					}
				}
			}
		}

		
		typedef T* iterator; // This creates an alias SO iterator MEANS T*
		typedef const T* const_iterator; // const_iterator MEANS const T*
		// One iterator will be for for each loops (const iterator).
		// The iterator is for other uses (standard for loop).
		// iterators have two methods and three operators
		// two methods - begin, end.
		// three operators - ++, --, * (de-reference operator).

		// In the self_adjusting_array because the iterators are pointers (T*) the pointer ALREADY has
		// the operators ++, --, and *.
		// Because of this, we DO NOT have to implement them here.
		// The only thing I have to add is begin and end.

		iterator begin() // Iterator is a T pointer.
		{ // the operator & (address-of) operator.
			// What does a pointer hold? memory address.
			// What do I return the value OR the memory address of the value?
			return &this->data[0U];
		}

		const_iterator begin() const
		{
			return &this->data[0U];
		}

		// We go to size - 1 because arrays are zero based. Size 5, that means 0 to 4.
		// When we talk about the end, we DO NOT mean the last acceptable value, but the value
		// after it - meaning the END. 
		iterator end()
		{
			return &this->data[this->size()];
		}

		const_iterator end() const
		{
			return &this->data[this->size()];
		}

		friend std::ostream& operator<<(std::ostream& out, const self_adjusting_array& list)
		{
			out << "Size " << list.my_size << std::endl;
			out << "Capacity " << list.my_capacity << std::endl;

			for (auto index = 0U; index < list.my_size; index++) {
				out << list[index] << " ";
			}

			for (auto index = list.my_size; index < list.my_capacity; ++index) {
				out << "nil ";
			}

			out << std::endl;
			return out;
		}

	private:
		size_t my_size;

		size_t my_capacity;

		T* data;
	};
}

#endif