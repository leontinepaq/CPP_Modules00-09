/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:30:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 14:49:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEASURE_HPP
#define MEASURE_HPP

# include <vector>
# include <ctime>
# include <functional>
	
template <typename Func, typename Args>
double measureExecutionTime(Func f, Args& args) {
	std::clock_t start = std::clock();
	f(args);
	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return duration;
}

#endif

