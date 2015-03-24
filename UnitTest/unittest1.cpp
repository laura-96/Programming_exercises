#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"

#include "../2D_Engine/DynArray.h"
#include "../2D_Engine/Point2d.h"
#include "../2D_Engine/String.h"
#include "../2D_Engine/LinkedList.h"

#include "../2D_Engine/Point2d.cpp"
#include "../2D_Engine/String.cpp"

#


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// DYN ARRAY CLASS
		TEST_METHOD(DynArray_ctor)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			int a, b;

			Assert::IsTrue(array.Pop(a));
			Assert::IsTrue(array.Pop(b));

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 1);
			Assert::AreEqual(a, 3);
			Assert::AreEqual(b, 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_at)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(*(array.At(0)), 1);
			Assert::AreEqual(*(array.At(1)), 2);
			Assert::AreEqual(*(array.At(2)), 3);
			Assert::IsNull(array.At(3));
		}

		TEST_METHOD(DynArray_resize)
		{
			DynArray<int> array;

			for (int i = 0; i < 999; ++i)
			{
				array.PushBack(i);
			}

			Assert::AreEqual(*(array.At(900)), 900);
			Assert::IsNull(array.At(1000));

			Assert::AreEqual((int)array.GetCapacity(), 1008);
			Assert::AreEqual((int)array.Count(), 999);
		}

		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> array;

			for (int i = 0; i < DYN_ARRAY_BLOCK_SIZE; ++i)
			{
				array.PushBack(i);
			}

			array.Insert(999, 3);
			array.Insert(888, 17);
			array.Insert(777, 50);

			Assert::IsFalse(array.Insert(777, 50));
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE * 2);
			Assert::AreEqual((int)array.Count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}

		//STRING CLASS:
		TEST_METHOD(SString_empty_ctor)
		{
			String s;
			Assert::AreEqual((int)s.Length(), 0);
		}
		TEST_METHOD(SString_char_ctor)
		{
			String s("Hola mundo");
			Assert::AreEqual((int)s.Length(), 10);
		}
		TEST_METHOD(SString_format_ctor)
		{
			String s("%s %s %d", "hola", "mundo", 12);
			Assert::AreEqual((int)s.Length(), 13);
		}
		TEST_METHOD(SString_copy_ctor)
		{
			String s("%s %s %d", "hola", "mundo", 12);
			String s2(s);
			Assert::AreEqual((int)s2.Length(), 13);
		}
		TEST_METHOD(SString_op_equal)
		{
			String s1("Hola mundo");
			String s2("Hola mundo");
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(SString_op_notequal)
		{
			String s1("Hola mundo 1");
			String s2("Hola mundo 2");
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(SString_op_equal_cstr)
		{
			String s1("Hola mundo");
			Assert::IsTrue(s1 == "Hola mundo");
		}
		TEST_METHOD(SString_op_notequal_cstr)
		{
			String s1("Hola mundo 1");
			Assert::IsTrue(s1 != "test");
		}
		TEST_METHOD(SString_op_assign)
		{
			String s1("Hola mundo");
			String s2;
			s2 = s1;
			Assert::IsTrue(s2 == "Hola mundo");
		}
		TEST_METHOD(SString_op_assign_cstr)
		{
			String s1("Hola mundo");
			s1 = "this is a test";
			Assert::IsTrue(s1 == "this is a test");
		}
		TEST_METHOD(SString_op_concat)
		{
			String s1("Hola mundo");
			String s2("this is a test");
			s1 += s2;
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_op_concat_cstr)
		{
			String s1("Hola mundo");
			s1 += "this is a test";
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_length)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)s1.Length(), 10);
		}
		TEST_METHOD(SString_capacity)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)s1.GetCapacity(), 11);
		}
		TEST_METHOD(SString_getstr)
		{
			String s1("Hola mundo");
			Assert::AreEqual((int)strcmp("Hola mundo", s1.GetString()), 0);
		}
		TEST_METHOD(SString_clear)
		{
			String s1("Hola mundo");
			s1.Clear();
			Assert::AreEqual((int)s1.Length(), 0);
		}

		// LINKED LIST CLASS:
		TEST_METHOD(ListAdd)
		{
			LinkedList<int> mylist;
			Assert::AreEqual((int)mylist.add(5), 1);
		}

		TEST_METHOD(ListDel)
		{
			LinkedList<int> mylist;
			mylist.add(5);
			Assert::IsTrue(mylist.del(mylist.start));
			Assert::AreEqual((int)mylist.count(), 0);
		}

		TEST_METHOD(ListClear)
		{
			LinkedList<int> mylist;
			mylist.add(1); mylist.add(2); mylist.add(3);
			mylist.clear();
			Assert::AreEqual((int)mylist.count(), 0);
		}

		//POINT 2D CLASS:
		TEST_METHOD(SetZero)
		{
			Point2d punt;
			punt.SetZero();
			Assert::IsTrue(punt.x == 0.0f && punt.y == 0.0f);
		}

		TEST_METHOD(IsZero)
		{
			Point2d punt;
			punt.SetZero();
			Assert::IsTrue(punt.IsZero());
		}

		TEST_METHOD(DistanceTo)
		{
			Point2d a;
			Point2d b;
			Point2d c;

			a.x = 2;
			a.y = 0;
			b.x = 2;
			b.y = 0;
			c.x = 4;
			c.y = 0;
			float dist1 = a.DistanceTo(b);
			float dist2 = a.DistanceTo(c);

			Assert::AreEqual(dist1, 0.0f);
			Assert::AreEqual(dist2, 2.0f);
		}

		TEST_METHOD(Addition)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			Point2d sum = a.operator+(b);

			Assert::AreEqual(sum.x, 6.0f);
			Assert::AreEqual(sum.y, -3.0f);

		}

		TEST_METHOD(Substraction)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			Point2d res = a.operator-(b);

			Assert::AreEqual(res.x, -2.0f);
			Assert::AreEqual(res.y, 3.0f);

		}

		TEST_METHOD(Increase)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			a.operator+=(b);

			Assert::AreEqual(a.x, 6.0f);
			Assert::AreEqual(a.y, -3.0f);

		}

		TEST_METHOD(Decrease)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			a.operator-=(b);

			Assert::AreEqual(a.x, -2.0f);
			Assert::AreEqual(a.y, 3.0f);

		}

		TEST_METHOD(EqualTo)
		{
			Point2d punt;
			punt.SetZero();
			Point2d pt;
			pt.SetZero();
			bool equal = pt.operator==(punt);
			Assert::IsTrue(equal);
		}

		TEST_METHOD(DifferentFrom)
		{
			Point2d punt;
			punt.SetZero();
			Point2d pt;
			pt.SetZero();
			bool diff = pt.operator!=(punt);
			Assert::IsFalse(diff);
		}
	};
}