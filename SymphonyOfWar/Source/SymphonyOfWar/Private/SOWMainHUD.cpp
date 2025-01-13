// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWMainHUD.h"

void ASOWMainHUD::BeginPlay()
{
	Super::BeginPlay();

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("SOWMainHUD active"));*/
}

void ASOWMainHUD::DrawHUD()
{
	Super::DrawHUD();

	// Center of the screen
	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// Offset texture height and width to remain in center
	FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture2D->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture2D->GetSurfaceHeight() * 0.5f));

	// Draw the crosshair at the centerpoint.
	FCanvasTileItem CanvasTileItem(CrossHairDrawPosition, CrosshairTexture2D->Resource, FLinearColor::White);
	CanvasTileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(CanvasTileItem);
}
