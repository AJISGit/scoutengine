#pragma once
#include <instance.hpp>
#include <lockedinstance.hpp>

#include <type_traits>
#include <stdexcept>


namespace Scout {

	template <typename T>
	class InstancePtr;

	template <typename T>
	class InstancePtr {
		private:
		T* ptr = nullptr;
	
		public:
		InstancePtr(T* instance);
		InstancePtr(const InstancePtr<T>&) = default;

		void destroy();
		bool isNull() const;

		T* operator->() const;
		T& operator*();
		const T& operator*() const;

		InstancePtr<T>& operator++();	
		InstancePtr<T> operator++(int);
		InstancePtr<T>& operator--();	
		InstancePtr<T> operator--(int);

		bool operator==(const InstancePtr<Instance>& rhs) const;
		bool operator!=(const InstancePtr<Instance>& rhs) const;

		operator InstancePtr<Instance>();

		friend class Instance;

		template <typename from, typename to>
		friend InstancePtr<to> convertInstPtr(const InstancePtr<from>& ptr);

	};

	template <typename T, typename... Args>
	InstancePtr<T> newInstance(Args... args);
	
}

template <typename T>
Scout::InstancePtr<T>::InstancePtr(T* instance) {
	static_assert(std::is_base_of<Scout::Instance, T>::value, "T has to be derived from an Instance.");
	ptr = instance;
}


template <typename T>
void Scout::InstancePtr<T>::destroy() {
	if (!ptr->isDestroyable()) {
		throw std::runtime_error(ptr->getName() + " is not destroyable.");
	}
	delete ptr;
}


template <typename T>
bool Scout::InstancePtr<T>::isNull() const {
	return ptr == nullptr;
}


template <typename T>
T* Scout::InstancePtr<T>::operator->() const {
	return ptr;
}


template <typename T>
T& Scout::InstancePtr<T>::operator*() {
	return *ptr;
}


template <typename T>
const T& Scout::InstancePtr<T>::operator*() const {
	return *ptr;
}


template <typename T>
Scout::InstancePtr<T>& Scout::InstancePtr<T>::operator++() {
	++ptr;
	return *this;
}



template <typename T>
Scout::InstancePtr<T> Scout::InstancePtr<T>::operator++(int) {
	Scout::InstancePtr<T> temp = *this;
	++ptr;
	return temp;
}


template <typename T>
Scout::InstancePtr<T>& Scout::InstancePtr<T>::operator--() {
	--ptr;
	return *this;
}



template <typename T>
Scout::InstancePtr<T> Scout::InstancePtr<T>::operator--(int) {
	Scout::InstancePtr<T> temp = *this;
	--ptr;
	return temp;
}


template <typename T>
bool Scout::InstancePtr<T>::operator==(const Scout::InstancePtr<Scout::Instance>& rhs) const {	
	return rhs.ptr == ptr;
}


template <typename T>
bool Scout::InstancePtr<T>::operator!=(const Scout::InstancePtr<Scout::Instance>& rhs) const {	
	return rhs.ptr != ptr;
}


template <typename T>
Scout::InstancePtr<T>::operator Scout::InstancePtr<Scout::Instance>() {
	return Scout::InstancePtr<Instance>(ptr);
}


template <typename T, typename... Args>
Scout::InstancePtr<T> Scout::newInstance(Args... args) {

	static_assert(std::is_base_of<Scout::Instance, T>::value, "T has to be derived from an Instance.");

	return Scout::InstancePtr<T>(new T(args...));

}


template <typename from, typename to>
Scout::InstancePtr<to> Scout::convertInstPtr(const Scout::InstancePtr<from>& ptr) {

	static_assert(std::is_base_of<Scout::Instance, from>::value, "from has to be derived from an Instance.");
	static_assert(std::is_base_of<Scout::Instance, to>::value, "to has to be derived from an Instance.");

	return Scout::InstancePtr<to>(ptr.ptr);

}

