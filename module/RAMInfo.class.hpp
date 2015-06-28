/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfo.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:01:55 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 09:55:39 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMINFO_HPP
# define RAMINFO_HPP

# include <iostream>
# include <unistd.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>

# include <IMonitorModule.class.hpp>

class RAMInfo : public IMonitorModule
{
private:
				RAMInfo(RAMInfo const &copy);
	RAMInfo const & operator=(RAMInfo const &rhs);

public:
				RAMInfo(void);
				~RAMInfo(void);
	int64_t 	getRamMax(void) const;
	int64_t 	getRamUsed(void) const;
	int64_t 	getRamFree(void) const;
	int 		getRamPercent(void) const;
};

#endif
