/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 21:05:10 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.Class.hpp"

OSInfo::OSInfo(void)
{
	struct utsname os_info;
	if ( uname( &os_info ) == -1)
		throw std::runtime_error("Error : Could not access OS informations");
	this->_sysname = os_info.sysname;
	this->_nodename = os_info.nodename;
	this->_release = os_info.release;
	std::stringstream sstream;
	sstream << os_info.version;
	this->_version = sstream.str();
	this->_version = this->_version.substr(0, this->_version.find(":"));
	this->_machine = os_info.machine;
	return;
}

OSInfo::~OSInfo(void)
{
	return;
}

std::string OSInfo::getSysname(void) const { return (this->_sysname); }
std::string OSInfo::getNodename(void) const { return (this->_nodename); }
std::string OSInfo::getRelease(void) const { return (this->_release); }
std::string OSInfo::getVersion(void) const { return (this->_version); }
std::string OSInfo::getMachine(void) const { return (this->_machine); }