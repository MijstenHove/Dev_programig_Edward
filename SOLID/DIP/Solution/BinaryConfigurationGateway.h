#pragma
#include "IConfigurationGateway.h"

class BinaryConfigurationGateway : public IConfigurationGateway
{
public:
	BinaryConfigurationGateway() = default;

	virtual Configuration* GetConfiguration() override;
};