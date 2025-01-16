#pragma once

#define NO_COPY(ClassName)								\
ClassName(const ClassName&) = delete;					\
ClassName& operator=(const ClassName&) = delete;

#define DECLARE_SINGLETON(ClassName)					\
		NO_COPY(ClassName)								\
public :												\
	static ClassName* Get_Instance();					\
	static unsigned int Destroy_Instance();				\
private:												\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)					\
ClassName* ClassName::m_pInstance = nullptr;			\
ClassName* ClassName::Get_Instance()					\
{														\
	if (nullptr == m_pInstance)							\
		m_pInstance = new ClassName;					\
	return m_pInstance;									\
}														\
unsigned int  ClassName::Destroy_Instance()				\
{														\
	unsigned int iRefCnt = { 0 };						\
	if(nullptr != m_pInstance)							\
	{													\
		m_pInstance->Free();							\
		if(0 == iRefCnt)								\
			m_pInstance = nullptr;						\
	}													\
	return iRefCnt;										\
}
