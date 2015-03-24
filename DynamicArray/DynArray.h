#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

#include <assert.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class VALUE>

class DynArray
{
private:

	VALUE* data;
	unsigned int mem_capacity;
	unsigned int num_elements;

public:

	// Constructors
	DynArray()
	{
		mem_capacity = 0;
		num_elements = 0;
		data = NULL;
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	DynArray(unsigned int capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}

	// Destructor
	~DynArray()
	{
		delete[] data;
	}


	VALUE& operator[](unsigned int index)
	{
		assert(index < num_elements);
		return data[index];
	}

	const VALUE& operator[](unsigned int index) const
	{
		assert(index < num_elements);
		return data[index];
	}


	void PushBack(const VALUE& element)
	{
		if (num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);
		}

		data[num_elements++] = element;
	}

	void Pop(VALUE& value)
	{
		if (num_elements >=1)
		{
			num_elements -= 1;
		}

	}

	void Clear()
	{
		num_elements = 0;
	}

	bool Insert(const VALUE& element, unsigned int position)
	{
		if (position > num_elements)
			return false;

		if (position == num_elements)
		{
			PushBack(element);
			return true;
		}

		if (num_elements + 1 > mem_capacity)
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);

		for (unsigned int i = num_elements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++num_elements;

		return true;
	}

	VALUE* At(unsigned int index)
	{
		VALUE* result = NULL;

		if (index < num_elements)
			return result = &data[index];

		return result;
	}

	const VALUE* At(unsigned int index) const
	{
		VALUE* result = NULL;

		if (index < num_elements)
			return result = &data[index];

		return result;
	}


	unsigned int GetCapacity() const
	{
		return mem_capacity;
	}

	unsigned int Count() const
	{
		return num_elements;
	}

private:

	//Allocate memory:
	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;

		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		if (num_elements > mem_capacity)
			num_elements = mem_capacity;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}
};

#endif