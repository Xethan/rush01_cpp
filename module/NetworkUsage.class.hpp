/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkUsage.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 09:41:18 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 21:47:46 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKUSAGE_HPP
# define NETWORKUSAGE_HPP

# include <IMonitorModule.class.hpp>

# include <unistd.h>
# include <stdio.h>

class NetworkUsage : public IMonitorModule
{
private:
				NetworkUsage(NetworkUsage const & src);
	NetworkUsage const & operator=(NetworkUsage const & src);

public:
	static std::string pktsIn;
	static std::string pktsOut;
	static std::string bytesIn;
	static std::string bytesOut;

				NetworkUsage(void);
				~NetworkUsage(void);

	std::string	getNetworkThroughput(std::string cmd);
};

#endif
