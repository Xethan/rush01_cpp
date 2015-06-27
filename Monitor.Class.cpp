/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:25:28 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"

Monitor::Monitor(std::string display_mode) :
_display_mode(display_mode),
_ncurses()
{
	this->_os_info = new OSInfo();
	this->_hostusernames = new HostUserNames();
	return;
}

Monitor::~Monitor(void)
{
	delete this->_os_info;
	return;
}

void Monitor::display_all(void) const
{
	clear();
	//this->_ncurses.displayData(this->_hostusernames);
	//this->_ncurses.displayData(this->_os_info);
	refresh();
	// time_t t = std::time(0);
	// std::cout << "date: " << std::put_time(std::localtime(&t), "%d/%m/%y") << std::endl;
	// std::cout << "time: " << std::put_time(std::localtime(&t), "%T") << std::endl;
	return;
}