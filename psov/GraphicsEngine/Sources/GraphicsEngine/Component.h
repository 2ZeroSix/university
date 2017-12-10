#pragma once
#include <stdlib.h>

class Object;


class Component
{
public:
	Component() 
	{
		m_pObject = NULL;
	}

	virtual ~Component() = default;

	void Init(Object * pObject)
	{
		m_pObject = pObject;
	}
	
	Object * GetObjectPtr()const {
		return m_pObject;
	}

	virtual void Update() { }

protected:
	Object * m_pObject;
};
