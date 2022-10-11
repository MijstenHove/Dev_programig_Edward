#include "DIPMain.h"
#include "XMLConfigurationGateway.h"
#include "BinaryConfigurationGateway.h"
#include "IConfigurationGateway.h"
#include "Consumer.h"

#define USE_BINARY 0

void DIPMain::Main()
{
#if USE_BINARY
	auto configurationGateway = BinaryConfigurationGateway();
#else
	auto configurationGateway = XMLConfigurationGateway();
#endif
	auto consumer = Consumer();

	consumer.Do(configurationGateway);
}