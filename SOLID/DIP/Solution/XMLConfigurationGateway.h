#pragma
#include "IConfigurationGateway.h"

class XMLConfigurationGateway : public IConfigurationGateway
{
public:
	XMLConfigurationGateway() = default;

	virtual Configuration* GetConfiguration() override;
};