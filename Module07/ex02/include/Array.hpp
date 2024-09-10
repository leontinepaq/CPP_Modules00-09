/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:22:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/10 23:29:37 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

# ifndef COLORS
#  define BLUE		"\033[1;34m"
#  define RED		"\033[1;31m"
#  define GREEN		"\033[1;32m"
#  define CYAN		"\033[1;36m"
#  define MAGENTA	"\033[1;35m"
#  define YELLOW	"\033[1;33m"
#  define GREY		"\033[1;30m"
#  define WHITE		"\033[1;37m"
#  define ORANGE	"\033[1;38;5;208m"
#  define PURPLE	"\033[1;38;5;129m"
#  define RESET		"\033[0m"
# endif

template <typename T> class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		void operator=(Array const &src);
		~Array();
		T		&operator[](unsigned int i);
		size_t	size(void) const;

	private:
		T				*_array;
		unsigned int	_size;
		class OutOfRange : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Error: index out of range";
				}
		};
		
};


template <typename T> Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << GREY "[Array] Default constructor" RESET << std::endl;
	_array = new T[_size];
}

template <typename T> Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (n < 0)
		throw OutOfRange();
	_array = new T[_size];
	std::cout << GREY "[Array] Parametric constructor" RESET << std::endl;
}

template <typename T> Array<T>::Array(Array const &src) : _array(NULL), _size(src._size)
{
	std::cout << GREY "[Array] Copy constructor" RESET << std::endl;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T> void Array<T>::operator=(Array const &src)
{
	std::cout << GREY "[Array] Assignation operator" RESET << std::endl;
	if (_array)
		delete [] _array;
	_size = src._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T> Array<T>::~Array()
{
	std::cout << GREY "[Array] Destructor" RESET << std::endl;
	delete [] _array;
}

template <typename T> T &Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= _size)
		throw OutOfRange();
	return _array[i];
}

template <typename T> size_t Array<T>::size(void) const
{
	return _size;
}


#endif
