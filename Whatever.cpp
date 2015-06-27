/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:54:22 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

Whatever::Whatever(std::string display_mode) :
_display_mode(display_mode),
_username(getlogin()),
_ncurses()
{
	this->_os_info = new ModuleOS();
	char hostname[_POSIX_HOST_NAME_MAX + 1];
	if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == -1)
		throw std::runtime_error("Error : Could not access hostname");
	this->_hostname = hostname;
	return;
}

Whatever::~Whatever(void)
{
	delete this->_os_info;
	return;
}

void Whatever::display_all(void) const
{
	// time_t t = std::time(0);
	// std::cout << "hostname: " << this->_hostname << std::endl;
	// std::cout << "username: " << this->_username << std::endl << std::endl;
	clear();
	this->_ncurses.displayData(this->_os_info);
	refresh();
	// std::cout << "date: " << std::put_time(std::localtime(&t), "%d/%m/%y") << std::endl;
	// std::cout << "time: " << std::put_time(std::localtime(&t), "%T") << std::endl;
	return;
}

std::string Whatever::getHostname(void) const { return (this->_hostname); }
std::string Whatever::getUsername(void) const { return (this->_username); }