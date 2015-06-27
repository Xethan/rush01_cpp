/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:23 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:27:13 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP

# include <sys/utsname.h>

# include "IMonitorModule.Class.hpp"

class OSInfo : public IMonitorModule
{

public:

	OSInfo(void);
	~OSInfo(void);
	struct utsname getOSInfo(void) const;

private:

	OSInfo(OSInfo const &copy);
	OSInfo const &operator=(OSInfo const &rhs);

	struct utsname _os_info;
};

#endif