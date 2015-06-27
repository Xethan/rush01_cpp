/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserNames.Class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:28:48 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:27:35 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTUSERNAMES_HPP
# define HOSTUSERNAMES_HPP

# include <unistd.h>
# include <limits.h>

# include "IMonitorModule.Class.hpp"

class HostUserNames : public IMonitorModule
{

public:

	HostUserNames(void);
	~HostUserNames(void);
	std::string getHostname(void) const;
	std::string getUsername(void) const;

private:

	HostUserNames(HostUserNames const &copy);
	HostUserNames const &operator=(HostUserNames const &rhs);

	std::string _hostname;
	std::string _username;
};

#endif