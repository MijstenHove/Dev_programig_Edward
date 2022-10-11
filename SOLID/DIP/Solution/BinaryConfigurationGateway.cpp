#include "BinaryConfigurationGateway.h"
#include "../Common/Configuration.h"

#include <fstream>
#include <string>

Configuration* BinaryConfigurationGateway::GetConfiguration()
{
	std::ifstream f("file path", std::ios::in | std::ios::binary);
	Configuration* configuration = new Configuration();
	f.read(reinterpret_cast<char*>(configuration), sizeof(Configuration));
	f.close();
	return configuration;
}