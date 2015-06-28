/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUUsage.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 09:41:01 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 10:38:45 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUUSAGE_HPP
# define CPUUSAGE_HPP

# include <mach/mach.h>
# include <mach/mach_error.h>
# include <vector>
# include <cmath>

# include <IMonitorModule.class.hpp>

class CPUUsage : public IMonitorModule
{
private:
	std::vector<double> _cpuP;

				CPUUsage(CPUUsage const & src);
	CPUUsage const & operator=(CPUUsage const & src);

public:
				CPUUsage(void);
				~CPUUsage(void);

	void		getCpuPercent(void);
	std::vector<double> const & getCpuP(void) const;
};

#endif
