/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:06:47 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <sstream>
# include <iomanip>
# include <ncurses.h>

# include "IMonitorDisplay.Class.hpp"

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;

class Ncurses : public IMonitorDisplay
{
private:
			Ncurses(Ncurses const &copy);
	Ncurses const & operator=(Ncurses const &rhs);

public:
			Ncurses(void);
			~Ncurses(void);

	void	displayModule(HostUserNames * module) const;
	void	displayModule(OSInfo * module) const;
	void	displayModule(Time * module) const;
	void	displayModule(CPUInfo * module) const;
	void	displayModule(RAMInfo * module) const;
	void	displayUI(std::string str) const;

	void	print(std::string str) const;
};

#endif
