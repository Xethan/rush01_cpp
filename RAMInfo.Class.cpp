/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfo.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:01:57 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 19:58:11 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMInfo.Class.hpp"

#include <iostream>

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

//      ------------- CAST C++ ---------------

RAMInfo::RAMInfo(void)
{
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	this->_ram_max = physical_memory / 1024 / 1024;

	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t ram_stats;

	mach_port = mach_host_self();
	count = sizeof(ram_stats) / sizeof(natural_t);
	if (KERN_SUCCESS != host_page_size(mach_port, &page_size))
		throw std::runtime_error("Error : Couldn't access RAM statistics");
	if (KERN_SUCCESS != host_statistics64(mach_port, HOST_VM_INFO, reinterpret_cast<host_info64_t>(&ram_stats), &count))
		throw std::runtime_error("Error : Couldn't access RAM statistics");
	this->_ram_free = ram_stats.free_count * page_size / 1024 / 1024;
	this->_ram_used = ram_stats.active_count;
	this->_ram_used += ram_stats.inactive_count;
	this->_ram_used += ram_stats.wire_count;
	this->_ram_used *= page_size;
	this->_ram_used /= 1024 * 1024;
	std::cout << this->_ram_max << std::endl;
	std::cout << this->_ram_used << std::endl;
	std::cout << this->_ram_free << std::endl;
	return;
}


RAMInfo::~RAMInfo(void)
{
	return;
}

int64_t RAMInfo::getRamMax(void) const { return (this->_ram_max); }
int64_t RAMInfo::getRamUsed(void) const { return (this->_ram_used); }
int64_t RAMInfo::getRamFree(void) const { return (this->_ram_free); }