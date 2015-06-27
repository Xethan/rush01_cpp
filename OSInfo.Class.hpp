/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:23 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 18:48:51 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP

# include <sys/utsname.h>

# include "IMonitorModule.Class.hpp"

class OSInfo : public IMonitorModule
{
private:
	struct utsname		_os_info;

						OSInfo(OSInfo const &copy);
	OSInfo const &		operator=(OSInfo const &rhs);

public:
						OSInfo(void);
						~OSInfo(void);
	struct utsname		getOSInfo(void) const;
};

#endif
