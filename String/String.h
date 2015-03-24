#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include <stdarg.h> //To be able to use va_list, va_start...
#include <stdio.h>


class String{

private:

	char *string;
	unsigned int size;

public:
	//Constructors
	String(){
		Alloc(1);
		Clear();
	}

	String(unsigned int size);
	String(const String &str);
	String(const char *format, ...);

	//Operators:
	bool operator==(const String &str) const;
	bool operator==(const char *str) const;
	bool operator!=(const String &str) const;
	bool operator!=(const char *str) const;
	const String& operator=(const String &str);
	const String& operator=(const char *str);
	const String& operator+=(const String &str);
	const String& operator+=(const char *str);

	unsigned int Length() const;
	const char* GetString()const;
	void Clear();

	//Destructor:
	virtual ~String(){

		delete[] string;
	}

private:
	//Allocate memory:
	void Alloc(unsigned int memory);
};


#endif