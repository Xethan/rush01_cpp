/*

#include <mach/mach.h>
#include <mach/mach_error.h>
#include <vector>
void		RAMInfo::getCpuPercent(void) const
{
	static std::vector<uint64_t> stU;
	static std::vector<uint64_t> stN;
	static std::vector<uint64_t> stS;
	static std::vector<uint64_t> stI;
	std::vector<uint64_t> tmpU;
	std::vector<uint64_t> tmpN;
	std::vector<uint64_t> tmpS;
	std::vector<uint64_t> tmpI;

	unsigned int				nb_core;
	processor_cpu_load_info_t	cpu_load;
	mach_msg_type_number_t		cpu_msg_count;
	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &nb_core, (processor_info_array_t *) &cpu_load, &cpu_msg_count);

	this->_nbCore = nb_core;

	if (this->_coreCpu.empty()) // si coreCpu(cpu%[i]) vide
	{
		stU = std::vector<uint64_t>(nb_core); // une case ST par core
		stN = std::vector<uint64_t>(nb_core);
		stS = std::vector<uint64_t>(nb_core);
		stI = std::vector<uint64_t>(nb_core);

		this->_coreCpu = std::vector<double>(this->_nbCore); // remplir coreCpu

		for (unsigned int i = 0; i < nb_core; i++) // pour chaque core (st)
		{
			stU[i] = cpu_load[i].cpu_ticks[CPU_STATE_USER];
			stN[i] = cpu_load[i].cpu_ticks[CPU_STATE_NICE];
			stS[i] = cpu_load[i].cpu_ticks[CPU_STATE_SYSTEM];
			stI[i] = cpu_load[i].cpu_ticks[CPU_STATE_IDLE];
			this->_coreCpu[i] = 0;
		}
	}
	else // si coreCpu(cpu%[i]) non-vide
	{
		tmpU = std::vector<uint64_t>(this->_nbCore); // une case TMP par core
		tmpN = std::vector<uint64_t>(this->_nbCore);
		tmpS = std::vector<uint64_t>(this->_nbCore);
		tmpI = std::vector<uint64_t>(this->_nbCore);

		for (unsigned int i = 0; i < this->_nbCore; i++) // pour chaque core (tmp)
		{
			tmpU[i] = cpu_load[i].cpu_ticks[CPU_STATE_USER];
			tmpN[i] = cpu_load[i].cpu_ticks[CPU_STATE_NICE];
			tmpS[i] = cpu_load[i].cpu_ticks[CPU_STATE_SYSTEM];
			tmpI[i] = cpu_load[i].cpu_ticks[CPU_STATE_IDLE];
		}

		for (unsigned int i = 0; i < this->_nbCore; i++) // pour chaque core (st)
		{
			uint64_t    tmp_used = (tmpU[i] + tmpN[i] + tmpS[i]) - (stU[i] + stN[i] + stS[i]); // diff used
			uint64_t    tmp_total = (tmpU[i] + tmpN[i] + tmpS[i] + tmpI[i]) - (stU[i] + stN[i] + stS[i] + stI[i]); // diff total

			double tmp = static_cast<double>(tmp_used) / static_cast<double>(tmp_total) * 100.0f; // cpu used
			if (!isnan(tmp) && tmp > 0)
			{
				this->_coreCpu[i] = tmp; // coreCpu[i] = cpu% pour chaque core
				stU[i] = tmpU[i]; // previous value
				stN[i] = tmpN[i];
				stS[i] = tmpS[i];
				stI[i] = tmpI[i];
			}
		}
	}
}*/
