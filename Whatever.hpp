/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:03:45 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:43:02 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <limits.h>
# include <unistd.h> // getlogin / hostname
# include <iostream>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <stdexcept>

# include "Ncurses.Class.hpp"
# include "ModuleOS.Class.hpp"

class Whatever
{

public :

	Whatever(std::string display_mode = "ncurses");
	~Whatever(void);
	void display_all(void) const; // appeler classe QT / Ncurses
	std::string getHostname(void) const;
	std::string getUsername(void) const;

private:

	Whatever(Whatever const &copy);
	Whatever const &operator=(Whatever const &rhs);

	std::string _display_mode;
	std::string _hostname;
	std::string _username;
	IMonitorModule *_os_info;
	Ncurses _ncurses;
	//Class QT;
};

#endif