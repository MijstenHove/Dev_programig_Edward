#include "XMLConfigurationGateway.h"
#include "../Common/Configuration.h"


Configuration* XMLConfigurationGateway::GetConfiguration()
{
	// Read from XML
	return new Configuration();
}