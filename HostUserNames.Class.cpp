/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserNames.Class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:28:46 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 21:34:14 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostUserNames.Class.hpp"

HostUserNames::HostUserNames(void)
{
	this->_username = getlogin();
	if (this->_username.empty())
		throw std::runtime_error("Error : Could not access username");
	char hostname[_POSIX_HOST_NAME_MAX + 1];
	if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == -1)
		throw std::runtime_error("Error : Could not access hostname");
	this->_hostname = hostname;
	this->_hostname = this->_hostname.substr(0, this->_hostname.find("."));
	return;
}

HostUserNames::~HostUserNames(void)
{
	return;
}

std::string HostUserNames::getHostname(void) const { return (this->_hostname); }
std::string HostUserNames::getUsername(void) const { return (this->_username); }
