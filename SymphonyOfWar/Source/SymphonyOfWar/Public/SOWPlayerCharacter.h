// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include <EnhancedPlayerInput.h>
#include "SOWPlayerCharacter.generated.h"

UCLASS()
class SYMPHONYOFWAR_API ASOWPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	// First person mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* PlayerMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Weapon)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Health = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool IsDamageTaken = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int TimeTakenSinceDamage = 0;

	//// Fire input asset
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	//UInputAction* PlayerFireAction;

	//// Reload input asset
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Input")
	//UInputAction* PlayerReloadAction;

	//// Fire animation
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//UAnimMontage* PlayerFireAnimation;

	//// Reload animation
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//UAnimMontage* PlayerReloadAnimation;

	//// Weapon class
	//UPROPERTY(EditDefaultsOnly, Category = Weapon)
	//TSubclassOf<class ASOWRifleActor> WeaponClass;

	/*UPROPERTY(VisibleDefaultsOnly, Category = Weapon)
	USkeletalMeshComponent* WeaponMesh;*/

	//// Rifle class
	//UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	//TSubclassOf<class USOWWeaponRifle> RifleClass;
	
	// Sets default values for this character's properties
	ASOWPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Jump() override;

	virtual void StopJumping() override;

	void ReceiveDamage(float Damage);

	// Getter for player mesh
	UFUNCTION(BlueprintCallable, Category = "Get Player Mesh")
	USkeletalMeshComponent* GetPlayerMesh();

	// Getter for camera component
	UCameraComponent* GetCameraComponent();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	int GetHealth();

	//// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void DoPlayerFire();

	//void DoPlayerReload();

private:
	//USOWWeaponRifle* WeaponRifle;
};
