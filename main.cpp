/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:24:35 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

#include "CPUInfo.Class.hpp"

int main(void)
{
	try
	{
		Monitor monitor;
		int key;

		monitor.display_all();
		while ( ( key = getch() ) != 27 )
			monitor.display_all();
		endwin();

    	int mib[2];
		int64_t physical_memory;
		mib[0] = CTL_HW;
		mib[1] = HW_MEMSIZE;
		size_t length = sizeof(int64_t);
		sysctl(mib, 2, &physical_memory, &length, NULL, 0);

    	std::cout << physical_memory << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}
	return (0);
}