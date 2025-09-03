// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "Modules/ModuleManager.h"

class FFishyProceduralSkeletalMeshModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
