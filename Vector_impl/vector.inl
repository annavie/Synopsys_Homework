
template<typename T>
Vector<T>::Vector() 
                : m_size(0)
                , m_capacity(0) {
	m_arr = new T[m_capacity];

}

template<typename T>
Vector<T>::~Vector() { 
	//std::cout << "Destructor" << std::endl;
	delete[] m_arr; 
}

template<typename T>
Vector<T>::Vector(const Vector& other) 
	: m_size(other.m_size)
	, m_capacity(m_capacity)
	, m_arr(new T[m_capacity]) {

	std::cout << "copy ctor" << std::endl;
	for(int i = 0;i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}

template<typename T>
Vector<T>::Vector(Vector&& other) 
	: m_capacity(other.m_capacity)
  	, m_size(other.m_size)
	, m_arr(other.m_arr) {

	std::cout << "Move ctor" << std::endl;
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_arr = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
	std::cout << "Move =" << std::endl;
	if (this == &other) {
		return *this;
	} 
	delete[] m_arr;
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_arr = other.m_arr;
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_arr = nullptr;
	return *this;

}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
	std::cout << "operator=";
	if (this == &other) {
		return *this;
	}
	delete[] m_arr;
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_arr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int index) {
	if (index >= 0 && index < m_size) {
		return m_arr[index];
	}
	throw std::out_of_range("Index out of range");
}

template<typename T>
void Vector<T>::push_back(T elem) {
	if (m_capacity == m_size) {
		m_capacity = m_capacity ? m_capacity * 2 : 1;
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size; ++i) {
			temp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = temp;
	}
	m_arr[m_size] = elem;
	++m_size;
}

template<typename T>
void Vector<T>::push_front(T elem) {
	if (m_capacity == m_size) {
		m_capacity = m_capacity ? m_capacity * 2 : 1;
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size; ++i) {
			temp[i+1] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = temp;
	}else {
		for (int i = m_size; i > 0; --i) {
			m_arr[i] = m_arr[i-1];
		}
	}

	m_arr[0] = elem;
	++m_size;
}

template<typename T>
void Vector<T>::pop_back() {
	m_size--;
}

template<typename T>
void Vector<T>::pop_front() {
	if (m_size > 0) {
		for (int i = 1; i < m_size; ++i) {
			m_arr[i-1] = m_arr[i];
		}
		--m_size;
	}       
}

template<typename T>
void Vector<T>::insert(int position, T value) {
	if (position > m_size) {
		throw std::out_of_range("Invalid index for insertation :(") ;
	}
	if (m_size == m_capacity) {
		m_capacity = m_capacity ? m_capacity * 2 : 1;
		T* temp = new T[m_capacity];
		for(int i = 0; i < m_size; ++i) {
			temp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = temp;
	}
	for (int i = m_size; i > position; --i) {
		m_arr[i] = m_arr[i-1];
	}
	m_arr[position] = value;
	++m_size;
}

template<typename T>
void Vector<T>::remove(int position) {
	if (position > 0 && position < m_size) {
		for (int i = position; i < m_size-1; ++i) {
			m_arr[i] = m_arr[i+1];
		}
		--m_size;
	} else {
		throw std::out_of_range("Invalid index for removing :(");

	}
}

template<typename T>
void Vector<T>::clear() {
	if (m_size > 0) {
		m_size = 0;

	} else { 
		return ;
	}
}	

template<typename T>
void Vector<T>::print() {
	if (m_size == 0) {
		std::cout << "Vector is empty " << std::endl;
	} else {
		std::cout<<"Vectors elemnts: " << std::endl;
		for(int i = 0; i < m_size; ++i) {
			std::cout << " " << m_arr[i];
		}
		std::cout << std::endl;
	}
}
template<typename T>
int Vector<T>::get_size() const {
	return m_size;
}

template<typename T>
Vector<T> foo() {
	Vector<int> myVector;
	for (int i = 10; i < 14; ++i) {
                myVector.push_back(i);
        }

	return myVector;
};
