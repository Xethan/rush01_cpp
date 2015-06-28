/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkUsage.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 09:41:17 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 21:52:42 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkUsage.class.hpp>

std::string		NetworkUsage::pktsIn = "netstat -ib en0 | grep Link#4 | awk '{print $5}' | tr -d '\n'";
std::string		NetworkUsage::pktsOut = "netstat -ib en0 | grep Link#4 | awk '{print $8}' | tr -d '\n'";
std::string		NetworkUsage::bytesIn = "netstat -ib en0 | grep Link#4 | awk '{print $7}' | tr -d '\n'";
std::string		NetworkUsage::bytesOut = "netstat -ib en0 | grep Link#4 | awk '{print $10}' | tr -d '\n'";

				NetworkUsage::NetworkUsage(void) {}

				NetworkUsage::~NetworkUsage(void) {}

std::string		NetworkUsage::getNetworkThroughput(std::string cmd)
{
	FILE *answer;
	char buffer[500];
	std::string value;

	answer = popen(cmd.c_str(), "r");
	if (!answer)
		throw std::runtime_error("NetModule: Error popen");

	while (!feof(answer))
		if (fgets(buffer, sizeof(buffer), answer) != NULL)
			value += buffer;

	pclose(answer);
	return value;
}
