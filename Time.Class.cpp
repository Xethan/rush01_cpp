/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:33:43 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:47:25 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Time.Class.hpp"

#include <sstream>

Time::Time(void)
{
	time_t current_time = std::time(0);
	std::stringstream ss_date;
	ss_date << std::put_time(std::localtime(&current_time), "%d/%m/%y");
	this->_date = ss_date.str();
	std::stringstream ss_time;
	ss_time << std::put_time(std::localtime(&current_time), "%T");
	this->_time = ss_time.str();
	return;
}

Time::~Time(void)
{
	return;
}

std::string Time::getDate(void) const { return (this->_date); }
std::string Time::getTime(void) const { return (this->_time); }