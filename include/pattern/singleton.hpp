#pragma once
#include <memory>
#include <pattern/noncopyable/noncopyable.hpp>
#include <iostream>
template<typename T>
class Singleton : private noncopyable
{
public:
	static T* GetInstance();
	static T* CreateInstance();
	static void destroy();

protected:
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) noexcept = delete;

protected:
	static std::unique_ptr<T> m_instance;
	Singleton() {};
	virtual ~Singleton() {
	};
};

template<typename T>
typename std::unique_ptr<T> Singleton<T>::m_instance = 0;

template<typename T>
T* Singleton<T>::GetInstance()
{
	if (!m_instance)
	{
		Singleton<T>::m_instance = std::make_unique<T>();
	}
	return m_instance.get();
}

template<typename T>
T* Singleton<T>::CreateInstance()
{
	if (!m_instance)
	{
		Singleton<T>::m_instance = std::make_shared<T>();
	}
	return m_instance.get();
}

template<typename T>
void Singleton<T>::destroy()
{
	Singleton<T>::m_instance = nullptr;
}
