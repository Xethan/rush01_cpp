/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 20:31:44 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfo.Class.hpp"

					OSInfo::OSInfo(void)
{
	if (uname(&(this->_os_info)) == -1)
		throw std::runtime_error("Error : Could not access OS informations");
}

					OSInfo::~OSInfo(void)
{

}

struct utsname		OSInfo::getOSInfo(void) const
{
	return (this->_os_info);
}
