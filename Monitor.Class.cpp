/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 20:14:32 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>
#include <HostUserNames.class.hpp>
#include <OSInfo.class.hpp>
#include <CPUInfo.class.hpp>
#include <Time.class.hpp>
#include <RAMInfo.class.hpp>
#include <CPUUsage.class.hpp>
#include <NetworkUsage.class.hpp>

#include <Ncurses.class.hpp>
#undef scroll
#include <QtDisplay.class.hpp>

				Monitor::Monitor(int ac, char **av) : _ac(ac), _av(av)
{
	this->_hostusernames = new HostUserNames();
	this->_os_info = new OSInfo();
	this->_time_info = new Time();
	this->_cpu_info = new CPUInfo();
	this->_ram_info = new RAMInfo();
	this->_cpu_usage = new CPUUsage();
	this->_network_usage = new NetworkUsage();
	this->_ncurses = new Ncurses();
	this->_qtdisplay = NULL;
}

				Monitor::~Monitor(void)
{
	delete this->_hostusernames;
	delete this->_os_info;
	delete this->_time_info;
	delete this->_cpu_info;
	delete this->_ram_info;
	delete this->_cpu_usage;
	delete this->_network_usage;
}

void			Monitor::programLoop(void)
{
	while (1)
	{
		if (this->_ncurses)
		{
			if (this->_ncurses->loop(*this))
			{
				this->_qtdisplay = new QtDisplay(this->_ac, this->_av);
				delete this->_ncurses;
				this->_ncurses = NULL;
			}
			else
				return;
		}
		else if (this->_qtdisplay)
		{
			if (this->_qtdisplay->loop(*this))
			{
				this->_ncurses = new Ncurses;
				delete this->_qtdisplay;
				this->_qtdisplay = NULL;
			}
			else
				return;
		}
		else
			return;
	}
	return;
}

HostUserNames *		Monitor::getHostUserNames(void) const { return this->_hostusernames; }
OSInfo *			Monitor::getOSInfo(void) const { return this->_os_info; }
Time *				Monitor::getTimeInfo(void) const { return this->_time_info; }
CPUInfo *			Monitor::getCPUInfo(void) const { return this->_cpu_info; }
RAMInfo *			Monitor::getRAMInfo(void) const { return this->_ram_info; }
CPUUsage *			Monitor::getCPUUsage(void) const { return this->_cpu_usage; }
NetworkUsage *		Monitor::getNetworkUsage(void) const { return this->_network_usage; }

