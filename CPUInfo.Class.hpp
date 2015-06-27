/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:46:08 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:24:18 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFO_HPP
# define CPUINFO_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <unistd.h>

# include "IMonitorModule.Class.hpp"

class CPUInfo : public IMonitorModule
{

public:

	CPUInfo(void);
	~CPUInfo(void);
	std::string getModel(void) const;
	std::string getClockSpeed(void) const;
	int getNbCores(void) const;

private:

	CPUInfo(CPUInfo const &copy);
	CPUInfo const &operator=(CPUInfo const &rhs);

	std::string _model;
	std::string _clock_speed;
	int _nb_cores;
};

#endif