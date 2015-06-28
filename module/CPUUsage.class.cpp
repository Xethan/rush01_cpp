/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUUsage.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 09:40:59 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 10:28:56 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CPUUsage.class.hpp>

				CPUUsage::CPUUsage(void) {}

				CPUUsage::~CPUUsage(void) {}

void			CPUUsage::getCpuPercent(void)
{
	static std::vector<uint64_t> stU;
	static std::vector<uint64_t> stN;
	static std::vector<uint64_t> stS;
	static std::vector<uint64_t> stI;
	std::vector<uint64_t> tmpU;
	std::vector<uint64_t> tmpN;
	std::vector<uint64_t> tmpS;
	std::vector<uint64_t> tmpI;

	unsigned int				nbCore;
	processor_cpu_load_info_t	cpuLoad;
	mach_msg_type_number_t		cpuMsgCount;
	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &nbCore, (processor_info_array_t *) &cpuLoad, &cpuMsgCount);

	if (this->_cpuP.empty()) // si coreCpu(cpu%[i]) vide
	{
		stU = std::vector<uint64_t>(nbCore); // une case ST par core
		stN = std::vector<uint64_t>(nbCore);
		stS = std::vector<uint64_t>(nbCore);
		stI = std::vector<uint64_t>(nbCore);

		this->_cpuP = std::vector<double>(nbCore); // remplir coreCpu

		for (unsigned int i = 0; i < nbCore; i++) // pour chaque core (st)
		{
			stU[i] = cpuLoad[i].cpu_ticks[CPU_STATE_USER];
			stN[i] = cpuLoad[i].cpu_ticks[CPU_STATE_NICE];
			stS[i] = cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
			stI[i] = cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];
			this->_cpuP[i] = 0;
		}
	}
	else // si coreCpu(cpu%[i]) non-vide
	{
		tmpU = std::vector<uint64_t>(nbCore); // une case TMP par core
		tmpN = std::vector<uint64_t>(nbCore);
		tmpS = std::vector<uint64_t>(nbCore);
		tmpI = std::vector<uint64_t>(nbCore);

		for (unsigned int i = 0; i < nbCore; i++) // pour chaque core (tmp)
		{
			tmpU[i] = cpuLoad[i].cpu_ticks[CPU_STATE_USER];
			tmpN[i] = cpuLoad[i].cpu_ticks[CPU_STATE_NICE];
			tmpS[i] = cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
			tmpI[i] = cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];
		}

		for (unsigned int i = 0; i < nbCore; i++) // pour chaque core (st)
		{
			uint64_t    tmp_used = (tmpU[i] + tmpN[i] + tmpS[i]) - (stU[i] + stN[i] + stS[i]); // diff used
			uint64_t    tmp_total = (tmpU[i] + tmpN[i] + tmpS[i] + tmpI[i]) - (stU[i] + stN[i] + stS[i] + stI[i]); // diff total

			double tmp = static_cast<double>(tmp_used) / static_cast<double>(tmp_total) * 100.0f; // cpu used
			if (!isnan(tmp) && tmp > 0)
			{
				this->_cpuP[i] = tmp; // coreCpu[i] = cpu% pour chaque core
				stU[i] = tmpU[i]; // previous value
				stN[i] = tmpN[i];
				stS[i] = tmpS[i];
				stI[i] = tmpI[i];
			}
		}
	}
}

std::vector<double> const & CPUUsage::getCpuP(void) const
{ return this->_cpuP; }
