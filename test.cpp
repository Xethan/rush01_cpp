/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:25:48 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main(void)
{
	try
	{
		Whatever modules;
		int key;

		while ( ( key = getch() ) != 27 )
			modules.display_all();
		endwin();
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}
	return (0);
}