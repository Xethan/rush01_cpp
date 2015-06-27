/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleOS.Class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:54:07 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleOS.Class.hpp"

ModuleOS::ModuleOS(void)
{
	if ( uname( &(this->_os_info) ) == -1)
		throw std::runtime_error("Error : Could not access OS informations");
	return;
}

ModuleOS::~ModuleOS(void)
{
	return;
}

void ModuleOS::display(void) const
{
	mvprintw(0, 0, "OS info");
	// std::cout << "--- OS info ---" << std::endl;
	// std::cout << "system name: " << this->_os_info.sysname << std::endl;
	// std::cout << "node name: " << this->_os_info.nodename << std::endl;
	// std::cout << "system release: " << this->_os_info.release << std::endl;
	// std::cout << "system version: " << this->_os_info.version << std::endl;
	// std::cout << "hardware identifier: " << this->_os_info.machine << std::endl;
	return;
}