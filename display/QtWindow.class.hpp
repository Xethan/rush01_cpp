/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtWindow.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:49:09 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 22:12:15 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QTWINDOW_HPP
# define QTWINDOW_HPP

# include <QApplication>
# include <QWidget>
# include <QPushButton>
# include <QProgressBar>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;
class CPUUsage;
class NetworkUsage;

class QtWindow : public QWidget
{

public:

	QtWindow(void);
	~QtWindow(void);
	void	displayModule(HostUserNames * module);
	void	displayModule(OSInfo * module);
	void	displayModule(CPUInfo * module);
	void	displayModule(Time * module);
	void	displayModule(RAMInfo * module);
	void	displayModule(CPUUsage * module);
	void	displayModule(NetworkUsage * module);

private:

	QPushButton *_ncurses_button;
	QPushButton *_hostusernames;
	QProgressBar *_ram_usage;

	QtWindow(QtWindow const &copy);
	QtWindow const &operator=(QtWindow const &rhs);

};

#endif
