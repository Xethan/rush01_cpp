/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 20:13:31 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>

int main(int ac, char **av)
{
	try
	{
		Monitor monitor(ac, av);
		monitor.programLoop();
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
