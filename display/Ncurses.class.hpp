/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 12:19:19 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <sstream>
# include <iomanip>
# include <ncurses.h>

# include <IMonitorDisplay.class.hpp>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;
class CPUUsage;
class NetworkUsage;

class Ncurses : public IMonitorDisplay
{
private:
	int		_h;
	int		_w;
	int		_y;
	int		_x;

			Ncurses(Ncurses const &copy);
	Ncurses const & operator=(Ncurses const &rhs);

public:
			Ncurses(void);
			~Ncurses(void);

	void	displayModule(HostUserNames * module);
	void	displayModule(OSInfo * module);
	void	displayModule(CPUInfo * module);
	void	displayModule(Time * module);
	void	displayModule(RAMInfo * module);
	void	displayModule(CPUUsage * module);
	void	displayModule(NetworkUsage * module);
	void	displayUI(void);

	void	print(std::string str);
};

#endif
