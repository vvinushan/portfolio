// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWGameModeBase.h"

ASOWGameModeBase::ASOWGameModeBase()
{
}

void ASOWGameModeBase::StartPlay()
{
	Super::StartPlay();

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("SOWGameModeBase active"));*/
}
