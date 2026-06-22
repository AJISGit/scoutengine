#pragma once
#include <instance.hpp>
#include <type_traits>
#include <stdexcept>


namespace Scout {
	
	template <typename T>
	class InstancePtr {
		private:
		T* ptr = nullptr;
	
		public:
		InstancePtr(T* instance);

		void destroy();

		T* operator->() const;

		friend class Instance;

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
T* Scout::InstancePtr<T>::operator->() const {
	return ptr;
}


template <typename T, typename... Args>
Scout::InstancePtr<T> Scout::newInstance(Args... args) {

	static_assert(std::is_base_of<Scout::Instance, T>::value, "T has to be derived from an Instance.");

	return Scout::InstancePtr<T>(new T(args...));

}
