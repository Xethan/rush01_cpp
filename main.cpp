/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 16:23:20 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>

int		main(void)
{
	try
	{
		Monitor monitor;
		monitor.ProgramLoop();
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}
	return (0);
}
