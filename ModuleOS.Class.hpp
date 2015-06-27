/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleOS.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:23 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:23:29 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULEOS_HPP
# define MODULEOS_HPP

# include <iostream>
# include <stdexcept>
# include <sys/utsname.h>

# include "IMonitorModule.hpp"

class ModuleOS : public IMonitorModule
{

public:

	ModuleOS(void);
	//ModuleOS(ModuleOS const &copy);
	~ModuleOS(void);
	//ModuleOS const &operator=(ModuleOs cosnt &rhs);
	void display(void) const;

private:

	struct utsname _os_info;
};

#endif