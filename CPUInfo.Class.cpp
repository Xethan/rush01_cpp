/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:46:07 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:23:09 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfo.Class.hpp"

#include <vector>

CPUInfo::CPUInfo(void)
{
	char buf[100];
	size_t buflen = 100;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	std::string cpu_info(buf);
	std::vector<std::string> v;
	std::string::size_type pos;
	while ( ( pos = cpu_info.find(" ") ) != std::string::npos )
	{
		v.push_back(cpu_info.substr(0, pos));
		cpu_info.erase(0, pos + 1);
	}
	v.push_back(cpu_info);
	this->_model = v[0] + " " + v[1] + " " + v[2];
	this->_clock_speed = v[5];
	this->_nb_cores = sysconf( _SC_NPROCESSORS_ONLN );
}


CPUInfo::~CPUInfo(void)
{
	return;
}

std::string CPUInfo::getModel(void) const { return (this->_model); }
std::string CPUInfo::getClockSpeed(void) const { return (this->_clock_speed); }
int CPUInfo::getNbCores(void) const { return (this->_nb_cores); }