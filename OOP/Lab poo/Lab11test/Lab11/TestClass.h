#pragma once
#ifndef TestClass_h
#define TestClass_h

#include "B.h"

class TestClass : public B {

private:
	int var1;
	float var2;

public:

	virtual int Get();


};

#endif // TestClass_h


