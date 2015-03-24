#include "String.h"

String::String(unsigned int size){

	if (size != NULL){
		Alloc(size);
	}

	else{
		Alloc(1);
	}

	Clear();
}

String::String(const String &str){

	Alloc(str.size);
	strcpy_s(string, size, str.string);
}

String::String(const char *format, ...){ // ... mean that more arguments can be recieved, however, the amount of them remains unknown

	size = 0;
	if (format != NULL){
		char tmp[4000];

		static va_list args;
		va_start(args, format);
		unsigned int characters = vsprintf_s(tmp, 4000, format, args);
		va_end(args);

		Alloc(characters + 1);

		if (characters > 0){

			strcpy_s(string, size, tmp);
		}

		else{

			Clear();
		}
	}
}

bool String::operator==(const String &str) const{

	return(strcmp(string, str.string)) == 0;
}

bool String::operator==(const char *str) const{
	
	if (str != NULL){
		return(strcmp(string, str)) == 0;
	}

	else
	{
		return false;
	}
}

bool String::operator!=(const String &str) const{

	return(strcmp(string, str.string)) != 0;
}

bool String::operator!=(const char *str) const{

	if (str != NULL){
		return(strcmp(string, str)) != 0;
	}

	else
	{
		return false;
	}
}

void String::Clear(){

	string[0] = '\0';
}

void String::Alloc(unsigned int memory){

	size = memory;
	string = new char[size];
}