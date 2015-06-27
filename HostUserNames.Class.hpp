/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserNames.Class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:28:48 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:04:48 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTUSERNAMES_HPP
# define HOSTUSERNAMES_HPP

# include <unistd.h>
# include <limits.h>

# include "IMonitorModule.Class.hpp"

class HostUserNames : public IMonitorModule
{
private:
	std::string	_hostname;
	std::string	_username;

				HostUserNames(HostUserNames const &copy);
	HostUserNames const & operator=(HostUserNames const &rhs);

public:
				HostUserNames(void);
				~HostUserNames(void);
	std::string	getHostname(void) const;
	std::string	getUsername(void) const;
};

#endif
