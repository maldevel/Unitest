#pragma once

/*
	Unitest - Unit Testing Framework for C
	Copyright (C) 2016  @maldevel

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define WIN32_LEAN_AND_MEAN

#include "Common.h"
#include <Windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#define TEST_METHOD(methodName) static void methodName(void)

//represents a test method
typedef void(*TFunction) (void);


//method structure
typedef struct TMethod
{
	const char *name;
	TFunction function;
}TMethod, *PTMethod;


enum
{
	LIMIT = 1,
	GROW = 2
};


//list of objects
typedef struct List
{
	unsigned int num_elements;
	unsigned int max_elements;
	int current;
	int last;
	void **data;
}List, *PList;


//a group of test methods
typedef struct TEST_GROUP
{
	const char *name;
	List *methods;
}TEST_GROUP, *PTEST_GROUP;


//list
List *list_create(void);

void list_add(List *list, void *p);

void list_front(List * list);

bool list_at_end(List * list);

void list_advance(List * list);

void *list_val(List * list);

void list_free(List * list);


//group
TEST_GROUP *group_create(const char *name);

void _group_add_test(TEST_GROUP *tGroup, TFunction tFunction, const char *fName);

#define group_add_test(Group, Function) _group_add_test(Group, Function, #Function);

void group_run_all(TEST_GROUP *tGroup);

void group_free(TEST_GROUP *tGroup);


//assert
void _assert_failed(const char *expr, ...);
void _assert_succeeded(const char *msg, ...);

#define _assert_msg(expr, format, ...) \
  (expr) ? \
     _assert_succeeded(">> [SUCCEEDED] Assertion '%s'\n", ## __VA_ARGS__, NULL) : \
     _assert_failed(">> [FAILED] Assertion '%s'\n\n[REASON] "#format, ## __VA_ARGS__, NULL)


#define _assert_int(X, OP, Y) {\
	long long _ck_x = (X); \
	long long _ck_y = (Y); \
	_assert_msg(_ck_x OP _ck_y, "%s == %I64d", #X" "#OP" "#Y, #X, _ck_x); \
}

#define _assert_uint(X, OP, Y) {\
	unsigned long long _ck_x = (X); \
	unsigned long long _ck_y = (Y); \
	_assert_msg(_ck_x OP _ck_y, "%s == %I64u", #X" "#OP" "#Y, #X, _ck_x); \
}

#define _assert_double(X, OP, Y) {\
	double _ck_x = (X); \
	double _ck_y = (Y); \
	_assert_msg(_ck_x OP _ck_y, "%s == %f", #X" "#OP" "#Y, #X, _ck_x); \
}

#define _assert_single(X, OP, Y) {\
	float _ck_x = (X); \
	float _ck_y = (Y); \
	_assert_msg(_ck_x OP _ck_y, "%s == %f", #X" "#OP" "#Y, #X, _ck_x); \
}

#define _assert_str(X, OP, Y) {\
	const char* _ck_x = (X); \
	const char* _ck_y = (Y); \
	_assert_msg(strcmp(_ck_x, _ck_y) OP 0, "%s == %s, %s == %s", #X" "#OP" "#Y, #X, _ck_x, #Y, _ck_y); \
}

#define _assert_true(X, OP) {\
	bool _ck_x = (X); \
	_assert_msg(true OP _ck_x, "%s == %s", #X" "#OP" true", #X, _ck_x?"true":"false"); \
}

#define _assert_null(X, OP) {\
	const void* _ck_x = (X); \
	_assert_msg(NULL OP _ck_x, "%s is %s", #X" "#OP" NULL", #X, _ck_x==NULL?"NULL":"not NULL"); \
}


//X==Y
#define AssertAreEqual_int(X, Y) _assert_int(X, ==, Y)
//X!=Y
#define AssertAreNotEqual_int(X, Y) _assert_int(X, !=, Y)
//X<Y
#define AssertLessThan_int(X, Y) _assert_int(X, <, Y)
//X<=Y
#define AssertLessEqual_int(X, Y) _assert_int(X, <=, Y)
//X>Y
#define AssertGreaterThan_int(X, Y) _assert_int(X, >, Y)
//X>=Y
#define AssertGreaterEqual_int(X, Y) _assert_int(X, >=, Y)


//X==Y
#define AssertAreEqual_uint(X, Y) _assert_uint(X, ==, Y)
//X!=Y
#define AssertAreNotEqual_uint(X, Y) _assert_uint(X, !=, Y)
//X<Y
#define AssertLessThan_uint(X, Y) _assert_uint(X, <, Y)
//X<=Y
#define AssertLessEqual_uint(X, Y) _assert_uint(X, <=, Y)
//X>Y
#define AssertGreaterThan_uint(X, Y) _assert_uint(X, >, Y)
//X>=Y
#define AssertGreaterEqual_uint(X, Y) _assert_uint(X, >=, Y)


//X==Y
#define AssertAreEqual_double(X, Y) _assert_double(X, ==, Y)
//X!=Y
#define AssertAreNotEqual_double(X, Y) _assert_double(X, !=, Y)
//X<Y
#define AssertLessThan_double(X, Y) _assert_double(X, <, Y)
//X<=Y
#define AssertLessEqual_double(X, Y) _assert_double(X, <=, Y)
//X>Y
#define AssertGreaterThan_double(X, Y) _assert_double(X, >, Y)
//X>=Y
#define AssertGreaterEqual_double(X, Y) _assert_double(X, >=, Y)


//X==Y
#define AssertAreEqual_single(X, Y) _assert_single(X, ==, Y)
//X!=Y
#define AssertAreNotEqual_single(X, Y) _assert_single(X, !=, Y)
//X<Y
#define AssertLessThan_single(X, Y) _assert_single(X, <, Y)
//X<=Y
#define AssertLessEqual_single(X, Y) _assert_single(X, <=, Y)
//X>Y
#define AssertGreaterThan_single(X, Y) _assert_single(X, >, Y)
//X>=Y
#define AssertGreaterEqual_single(X, Y) _assert_single(X, >=, Y)


//strcmp(X, Y)==0
#define AssertAreEqual_str(X, Y) _assert_str(X, ==, Y)
//strcmp(X, Y)!=0
#define AssertAreNotEqual_str(X, Y) _assert_str(X, !=, Y)
//strcmp(X, Y)<0
#define AssertLessThan_str(X, Y) _assert_str(X, <, Y)
//strcmp(X, Y)<=0
#define AssertLessEqual_str(X, Y) _assert_str(X, <=, Y)
//strcmp(X, Y)>0
#define AssertGreaterThan_str(X, Y) _assert_str(X, >, Y)
//strcmp(X, Y)>=0
#define AssertGreaterEqual_str(X, Y) _assert_str(X, >=, Y)

//X==true
#define AssertIsTrue(X) _assert_true(X, ==)
//X==false
#define AssertIsFalse(X) _assert_true(X, !=)


//X==null
#define AssertIsNull(X) _assert_null(X, ==)
//X!=null
#define AssertIsNotNull(X) _assert_null(X, !=)
