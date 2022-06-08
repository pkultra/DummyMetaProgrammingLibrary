#pragma once

namespace dmpl
{

template<typename T, T v>
struct integral_constant
{
	static constexpr T value = v;
	using value_type = T;
	using type = integral_constant;
	constexpr T operator()() { return v; }
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<typename T, typename U>
struct is_same: false_type
{};
template<typename T>
struct is_same<T, T>: true_type
{};

template<typename T>
struct is_null_pointer: false_type
{};
template<>
struct is_null_pointer<decltype(nullptr)>: true_type
{};

template<typename T>
struct is_const: false_type
{};
template<typename T>
struct is_const<T const>: true_type
{};

template<typename T>
struct remove_const
{
	using type = T;
};
template<typename T>
struct remove_const<T const>
{
	using type = T;
};

template<typename T>
struct remove_volatile
{
	using type = T;
};
template<typename T>
struct remove_volatile<T volatile>
{
	using type = T;
};

template<typename T>
struct remove_cv
{
	using type = remove_const<typename remove_volatile<T>::type>::type;
};

template<typename T>
struct remove_reference
{
	using type = T;
};
template<typename T>
struct remove_reference<T&>
{
	using type = T;
};
template<typename T>
struct remove_reference<T&&>
{
	using type = T;
};

} //namespace dmpl
