/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfo.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:46:08 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:03:08 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFO_HPP
# define CPUINFO_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <unistd.h>

# include <IMonitorModule.class.hpp>

class CPUInfo : public IMonitorModule
{
private:
	std::string	_model;
	std::string	_clock_speed;
	int			_nb_cores;

				CPUInfo(CPUInfo const &copy);
	CPUInfo const & operator=(CPUInfo const &rhs);

public:
				CPUInfo(void);
				~CPUInfo(void);
	std::string	getModel(void) const;
	std::string	getClockSpeed(void) const;
	int 		getNbCores(void) const;
};

#endif
