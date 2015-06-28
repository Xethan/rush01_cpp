/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtWindow.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:49:09 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 23:37:00 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QTWINDOW_HPP
# define QTWINDOW_HPP

# include <QApplication>
# include <QWidget>
# include <QPushButton>
# include <QProgressBar>
# include <QLabel>

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
	QLabel	*createLabel(std::string msg, int x_pos, int y_pos);

private:

	QtWindow(QtWindow const &copy);
	QtWindow const &operator=(QtWindow const &rhs);

};

#endif
