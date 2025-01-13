// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "SOWMainHUD.generated.h"

/**
 * 
 */
UCLASS()
class SYMPHONYOFWAR_API ASOWMainHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// Crooshair texture
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GeneralDisplay)
	UTexture2D* CrosshairTexture2D;

protected:
	// Called when game starts
	virtual void BeginPlay() override;
	
	// Draws HUD by overriding function from AHUD
	virtual void DrawHUD() override;

private:
	

};
