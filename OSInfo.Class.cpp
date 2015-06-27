/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:28:57 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.Class.hpp"

OSInfo::OSInfo(void)
{
	if ( uname( &(this->_os_info) ) == -1)
		throw std::runtime_error("Error : Could not access OS informations");
	return;
}

OSInfo::~OSInfo(void)
{
	return;
}

// void OSInfo::displayNcurses(void) const
// {
// 	mvprintw(2, 0, "OS info");
// 	mvprintw(3, 0, "System name: %s", this->_os_info.sysname);
// 	mvprintw(4, 0, "Node name: %s", this->_os_info.nodename);
// 	mvprintw(5, 0, "System release: %s", this->_os_info.release);
// 	mvprintw(6, 0, "System version: %s", this->_os_info.version);
// 	mvprintw(7, 0, "Hardware identifier: %s", this->_os_info.machine);
// 	return;
// }

struct utsname OSInfo::getOSInfo(void) const { return (this->_os_info); }