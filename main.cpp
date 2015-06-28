/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 17:39:05 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>

int main(int ac, char **av)
{
	try
	{
		Monitor monitor;
		monitor.ProgramLoop();
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}

	return (0);
}
