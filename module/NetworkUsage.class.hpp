/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkUsage.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 09:41:18 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 10:11:06 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKUSAGE_HPP
# define NETWORKUSAGE_HPP

# include <IMonitorModule.class.hpp>

class NetworkUsage : public IMonitorModule
{
private:
				NetworkUsage(NetworkUsage const & src);
	NetworkUsage const & operator=(NetworkUsage const & src);

public:
				NetworkUsage(void);
				~NetworkUsage(void);
};

#endif
