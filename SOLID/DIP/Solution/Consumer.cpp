#include "Consumer.h"
#include "IConfigurationGateway.h"
#include "../Common/Configuration.h"

void Consumer::Do(IConfigurationGateway &configurationGateway)
{
	auto configuration = configurationGateway.GetConfiguration();
}