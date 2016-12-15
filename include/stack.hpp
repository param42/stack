#include <stdexcept>
template <typename T>
class stack
{
public:

	stack(); 
	auto count() const noexcept->size_t;
	auto push(const T&) /* strong */ -> void;
	auto pop() noexcept -> void;
	auto top() const /* strong */ -> T;
	auto empty() const noexcept -> bool;
	 
	 
	~stack() { delete[] array_; }

private:
	 
	T* array_;
	size_t array_size_;
	size_t count_;
};


template <typename T>
stack<T>::stack() : count_(0), array_(nullptr), array_size_(0) {
}

template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
	return count_;
}

template <typename T>
auto stack<T>::push(const T& value) /* strong */ -> void
{
	T* backup = array_;
	T* new_array = nullptr;
	bool realloc = false;
	if (count_ == array_size_)
	{
		array_size_ =array_size_*2 + (array_size_==0);

		try
		{
			new_array = new T[array_size_];
			std::copy(array_, array_ + count_, new_array);
		}
		catch (...)
		{
			delete[] new_array;
			array_size_ /= 2;
			throw;
		}

		array_ = new_array;
		realloc = true;
	}

	try
	{
		array_[count_] = value;
	}
	catch (...)
	{
		if (realloc)
		{
			delete[] array_;
			array_ = backup;
			array_size_ /= 2;
		}
		throw;
	}

	++count_;
	if (realloc) delete[] backup;
	return;
}


template <typename T>
auto stack<T>::pop() noexcept -> void
{
	if (count_)
		--count_;
	return;
}


template <typename T>
auto stack<T>::top() const /* strong */ -> T
{
	if (count_)
	{
		T value = array_[count_ - 1];
		return value;
	}
	throw std::underflow_error("Stack is empty!");
}


template <typename T>
auto stack<T>::empty() const noexcept -> bool
{
	return (count_ ? false : true);
}
