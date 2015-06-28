/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:33:43 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:10:22 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Time.class.hpp>

#include <sstream>

			Time::Time(void) {}

			Time::~Time(void) {}

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
