#ifndef CONFIGURATION_GATEWAY_HEADER
#define CONFIGURATION_GATEWAY_HEADER
class Configuration;

class IConfigurationGateway
{
public:

	virtual Configuration* GetConfiguration() = 0;
};
#endif