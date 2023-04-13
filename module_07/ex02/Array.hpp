#pragma once

template <typename T>
class Array
{
public:
	Array() : m_array(new T()), m_size(0) {};
	Array(unsigned int n) : m_array(new T[n]()), m_size(n) {};
	Array(const Array &src) : m_array(new T[src.size()]()), m_size(src.size()) {
		*this = src;};
	~Array() { delete[] m_array; };
	Array & operator=(const Array &rhs) {
		if (this != &rhs){
			delete[] m_array;
			m_array = new T[rhs.size()]();
			m_size = rhs.m_size;
			for (unsigned int i = 0; i < m_size; i++)
				m_array[i] = rhs.m_array[i];
		}
		return *this; };
	T & operator [](unsigned int n) {
		if (n >= m_size)
			throw OutOfBoundsException();
		return m_array[n]; };
	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {return "index is out of bounds";}; };
	unsigned int size() const {return m_size; };
 
private:
	T *m_array;
	unsigned int m_size;
};