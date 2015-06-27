/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:33:43 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 21:05:27 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Time.Class.hpp"

#include <sstream>

Time::Time(void)
{
	return;
}

Time::~Time(void)
{
	return;
}

std::string Time::getDate(void) const
{
	time_t current_time = std::time(0);
	std::stringstream ss_date;
	ss_date << std::put_time(std::localtime(&current_time), "%d/%m/%y");
	return (ss_date.str());
}
std::string Time::getTime(void) const
{
	time_t current_time = std::time(0);
	std::stringstream ss_time;
	ss_time << std::put_time(std::localtime(&current_time), "%T");
	return (ss_time.str());
}