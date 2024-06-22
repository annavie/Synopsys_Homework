#include"string.h"

my_string::my_string() {
	string.str.size = 0;
	string.onstack[0] = '\0';
}

my_string::my_string(const char* data) {
	int len = std::strlen(data);

	if (len < 16) {
		string.str.size = len;
		std::memcpy(string.onstack, data, len);
		string.onstack[len] = '\0';
		std::cout << "In stack" << std::endl;
	} else {
		std::cout << "In heap" << std::endl;
		string.str.size = len;
		string.str.ptr = new char[len + 1];
		std::memcpy(string.str.ptr, data, len + 1);
	}
}

my_string::my_string(const my_string& other) {
	std::cout << "copy  ctor "<< std::endl;
	int len = other.string.str.size;
	if (len < 16) {
		string.str.size = len;
		std::memcpy(string.onstack, other.string.onstack, len);
	} else {
		string.str.size = len;
		string.str.ptr = new char[len + 1];
		std::memcpy(string.str.ptr, other.string.str.ptr, len + 1);
	}
}

my_string& my_string::operator=(const my_string& rhs) {
	std::cout << "= operator" << std::endl;

	if (this != &rhs) {

		if (string.str.size >= 16) {
			delete[] string.str.ptr;
		}

		int len = rhs.string.str.size;

		if (len < 16) {
			string.str.size = len;
			std::memcpy(string.onstack, rhs.string.onstack, len);
			string.onstack[len] = '\0';
		} else {
			string.str.size = len;
			string.str.ptr = new char[len + 1];
			std::memcpy(string.str.ptr, rhs.string.str.ptr, len + 1);
		}
	}

	return *this;
}

my_string& my_string::operator+=(const my_string& rhs) {
	int len_rhs = rhs.string.str.size;
	int len_lhs = string.str.size;
	int len = len_rhs + len_lhs;

	if (len < 16) {
		std::cout << "+= in stack" << std::endl;
		for (int i = 0; i < len_rhs; ++i) {
			string.onstack[len_lhs + i] = rhs.string.onstack[i];
		}
		string.onstack[len] = '\0';
		string.str.size = len;
	} else {
		std::cout << "+= in heap" << std::endl;
		char* result = new char[len + 1];

		for (int i = 0; i < len_lhs; ++i) {
			result[i] = (string.str.size >= 16) ? string.str.ptr[i] : string.onstack[i];
		}
		for (int i = 0; i < len_rhs; ++i) {
			result[i + len_lhs] = (rhs.string.str.size >= 16) ? rhs.string.str.ptr[i] : rhs.string.onstack[i];
		}

		if (string.str.size >= 16) {
			delete[] string.str.ptr;
		}
		result[len] = '\0';
		string.str.ptr = result;
		string.str.size = len;
	}
	return *this;
}

char& my_string::operator[](int index) {
	if (index < 0 || index >= string.str.size) {
		throw std::out_of_range("Index out of range");
	}
	int len = string.str.size;
	if (len < 16) {
		return string.onstack[index];
	} else {
		return string.str.ptr[index];
	}
}

void my_string::print() const {
	const char* ptr = (string.str.size < 16) ? string.onstack : string.str.ptr;

	for (int i = 0; i < string.str.size; ++i) {
		std::cout << ptr[i];
	}

	std::cout << std::endl;
}
char my_string::at(int index) const {
	if (index < 0 || index >= string.str.size) {
		throw std::out_of_range("Index out of range");
	}
	if (string.str.size < 16) {
		return string.onstack[index];
	} else {
		return string.str.ptr[index];
	}
}
my_string& my_string::append(const my_string& rhs) {
	*this +=rhs;
	return *this;

}
void my_string::push_back(char ch) {
	int len_lhs= string.str.size;
	int len = len_lhs + 1;
	if(len <16) {
		std::cout << "push_back in stack"<< std::endl;
		string.onstack[len_lhs] = ch;
		string.onstack[len] = '\0';
		string.str.size = len;
	}else {
		std::cout << "push_back in heap" << std::endl;
		char* result = new char [len+1];

		for (int i = 0; i < len_lhs; ++i) {
			result[i] = (string.str.size >= 16) ? string.str.ptr[i] : string.onstack[i];
		}
		result[len_lhs] = ch;
		result[len] = '\0';

		if (string.str.size >= 16) {
			delete[] string.str.ptr;
		}
		string.str.ptr = result;
		string.str.size = len;
	}

}

void my_string::clear() {
	if (string.str.size >= 16) {
		delete[] string.str.ptr;
		string.str.ptr = nullptr;
	}

	string.str.size = 0;
	string.onstack[0] = '\0';
}
int my_string::size() const {
	return string.str.size;
}
bool my_string::empty()  const {
	return string.str.size == 0;
}


my_string::~my_string() {
	if (string.str.size >= 16) {
		delete[] string.str.ptr;
	}
}

