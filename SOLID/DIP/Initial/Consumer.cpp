#include "Consumer.h"
#include "ConfigurationGateway.h"
#include "../Common/Configuration.h"

void Consumer::Do()
{
	auto configurationGateway = ConfigurationGateway();
	auto configuration = configurationGateway.GetConfiguration();
}