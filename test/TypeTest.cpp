#include <gtest/gtest.h>
#include "type_traits.hpp"

namespace dmpl
{

TEST(TypeTest, IntegralConstantTest)
{
	using v = integral_constant<int, 3>;
	EXPECT_EQ(v::value, 3);
	EXPECT_EQ(v{}(), 3);
	
	EXPECT_TRUE(true_type::value);
	EXPECT_TRUE(true_type{}());
	EXPECT_FALSE(false_type::value);
	EXPECT_FALSE(false_type{}());
}

TEST(TypeTest, IsSameTest)
{
	EXPECT_TRUE((is_same<int*, int*>::value));
	EXPECT_FALSE((is_same<int, int const>::value));
	EXPECT_FALSE((is_same<int*, int>::value));
}

TEST(TypeTest, IsNullPointerTest)
{
	int *a = 0;
	EXPECT_TRUE((is_null_pointer<decltype(nullptr)>::value));
	EXPECT_FALSE((is_null_pointer<decltype(a)>::value));
}

TEST(TypeTest, IsConstTest)
{
	EXPECT_TRUE((is_const<float* const>::value));
	EXPECT_FALSE((is_const<const float*>::value));
	EXPECT_FALSE((is_const<float*>::value));
}

TEST(TypeTest, RemoveConstVolatileTest)
{
	EXPECT_TRUE((is_same<int, remove_cv<int const>::type>::value));
	EXPECT_TRUE((is_same<int, remove_cv<int volatile>::type>::value));
	EXPECT_TRUE((is_same<int, remove_cv<int volatile const>::type>::value));
	EXPECT_TRUE((is_same<int, remove_cv<int const volatile>::type>::value));
	EXPECT_TRUE((is_same<int, remove_cv<const volatile int>::type>::value));
	EXPECT_FALSE((is_same<int*, remove_cv<const volatile int*>::type>::value));
	EXPECT_TRUE((is_same<int*, remove_cv<int* const volatile>::type>::value));
}

TEST(TypeTest, RemoveReferenceTest)
{
	EXPECT_TRUE((is_same<int, remove_reference<int>::type>::value));
	EXPECT_TRUE((is_same<int, remove_reference<int&>::type>::value));
	EXPECT_TRUE((is_same<int, remove_reference<int&&>::type>::value));
	EXPECT_FALSE((is_same<int&, remove_reference<int&>::type>::value));
}

}
