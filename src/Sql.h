#pragma once

#include <BuildEvents.h>

bool SaveBuildEventsToDatabase(BuildEventsParser* parser, const std::string& fileName);
