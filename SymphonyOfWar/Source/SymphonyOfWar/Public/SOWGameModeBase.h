// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SOWGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SYMPHONYOFWAR_API ASOWGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASOWGameModeBase();

protected:
	virtual void StartPlay() override;

private:

};
