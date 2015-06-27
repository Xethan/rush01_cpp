/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfo.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:01:55 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 22:04:28 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMINFO_HPP
# define RAMINFO_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <unistd.h>

# include "IMonitorModule.Class.hpp"

class RAMInfo : public IMonitorModule
{

public:

	RAMInfo(void);
	~RAMInfo(void);
	int64_t getRamMax(void) const;
	int64_t getRamUsed(void) const;
	int64_t getRamFree(void) const;
	int getRamPercent(void) const;

private:

	RAMInfo(RAMInfo const &copy);
	RAMInfo const &operator=(RAMInfo const &rhs);
};

#endif