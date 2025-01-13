// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/SkeletalMeshComponent.h"
#include "SOWPlayerCharacter.h"
#include "SOWBulletProjectile.h"
#include <EnhancedPlayerInput.h>
#include "SOWRifleActor.generated.h"

UCLASS()
class SYMPHONYOFWAR_API ASOWRifleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Aim input asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Input")
	UInputAction* AimAction;

	// Fire input asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Input")
	UInputAction* FireAction;

	// Reload input asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Input")
	UInputAction* ReloadAction;

	// Fire animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	// Reload animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* ReloadAnimation;

	// Fire sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* FireSound;

	// Reload sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* ReloadSound;

	// Weapon mapping context (work in tandem with default mapping context)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Input")
	UInputMappingContext* WeaponMappingContext;

	// Weapon mesh
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* RifleMesh;

	// Muzzle offset from camera, aligned with gun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	// Projectile class
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ASOWBulletProjectile> ProjectileClass;
	
	// Sets default values for this weapon actor's properties
	ASOWRifleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetupInputComponent();

	void StartAimRifle();

	void StopAimRifle();

	void FireRifle();

	void ReloadRifle();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 
	APlayerController* PlayerController;

	// 
	ASOWPlayerCharacter* PlayerCharacter;
};
