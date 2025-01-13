// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <EnhancedPlayerInput.h>
#include "SOWBulletProjectile.h"
#include "SOWPlayerCharacter.h"
#include "SOWPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class SYMPHONYOFWAR_API ASOWPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Movement for player (default player, OOP approach)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* CameraAction;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* WeaponAction;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* WeaponFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* WeaponReloadAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* JumpAction;

	// For future development, in the event that crouch is a requirement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputMappingContext* DefaultMappingContext;

	// For future development, for things like in-game inventory or menus
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputMappingContext* MenuMappingContext;

	//// Fire animation
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//UAnimMontage* WeaponFireAnimation;

	//// Reload animation
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//UAnimMontage* WeaponReloadAnimation;

	// Fire sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* WeaponFireSound;

	// Empty sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* WeaponEmptySound;

	// Reload sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* WeaponReloadSound;

	// Muzzle offset from camera, aligned with gun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	// Projectile class
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ASOWBulletProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
	int AmmoCount;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	int GetAmmoCount();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	void MovePlayer(const FInputActionInstance& Instance);

	void JumpPlayer();

	void CameraPlayer(const FInputActionInstance& Instance);

	void StartFireWeapon();

	void FireWeapon();

	void EndFireWeapon();

	void StartReloadWeapon();

	void ReloadWeapon();

	void EndReloadWeapon();

	//int GetAmmoCount();

private:
	//int AmmoCount;
	bool IsFiring;
	bool IsReloading;
	//FTimerHandle WeaponTimerHandle;
	//FTimerHandle WeaponReloadTimerHandle;

};
