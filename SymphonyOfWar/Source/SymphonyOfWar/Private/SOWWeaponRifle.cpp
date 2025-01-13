// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWWeaponRifle.h"
//#include "GameFramework/PlayerCharacter.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

void USOWWeaponRifle::BeginPlay()
{
	Super::BeginPlay();

	// Pointers for use in this class
	PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	//PlayerCharacter = Cast<ASOWPlayerCharacter>(PlayerController->GetPawn());

	// Inputs for weapon
	SetupInputComponent();

	// PLAYER MESH
	// Create skeletal mesh component
	RifleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RifleMesh"));
	check(RifleMesh != nullptr);

	// Only the player can see the weapon mesh
	RifleMesh->SetOnlyOwnerSee(true);

	// Attach to character and disable shadows (future development if pending)
	//PlayerMesh->SetupAttachment(CameraComponent);
	RifleMesh->bCastDynamicShadow = false;
	RifleMesh->CastShadow = false;

	/*FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	PlayerCharacter->AttachToComponent(PlayerCharacter->GetPlayerMesh(), AttachmentRules, "hand_r_weapon");*/
}

void USOWWeaponRifle::SetupInputComponent()
{
	// Casts down pointer to current world player controller
	if (PlayerController != nullptr)
	{
		// Pointer to character
		if (PlayerCharacter != nullptr)
		{
			// Gets the enhanced input subsystem
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				// Adds weapon mapping context under one less priority than the default mapping context
				Subsystem->AddMappingContext(WeaponMappingContext, 1);
			}

			// Cast to enhanced input component from controller input component to bind input actions
			UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);

			// Binds input action assets from engine property values to relevant functions
			EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Ongoing, this, &USOWWeaponRifle::StartAimRifle);
			EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &USOWWeaponRifle::StopAimRifle);
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &USOWWeaponRifle::FireRifle);
			EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this, &USOWWeaponRifle::ReloadRifle);
		}
	}
}

void USOWWeaponRifle::StartAimRifle()
{
	//PlayerCharacter->CameraComponent->SetRelativeLocation
}

void USOWWeaponRifle::StopAimRifle()
{

}

void USOWWeaponRifle::FireRifle()
{
	if (ProjectileClass != nullptr)
	{
		FVector CameraLocation = PlayerCharacter->GetCameraComponent()->GetRelativeLocation();
		//FVector CameraLocation = PlayerController->PlayerCameraManager->GetCameraLocation();
		FRotator CameraRotation = PlayerCharacter->GetCameraComponent()->GetRelativeRotation();
		
		//MuzzleOffset = FVector(100.0f, 0.0f, 0.0f);
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			FActorSpawnParameters ActorSpawnParameters;

			World->SpawnActor<ASOWBulletProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation);
		}
	}

	// Animation
	if (FireAnimation != nullptr)
	{
		//// Get the animation object for the arms mesh
		//UAnimInstance* AnimInstance = PlayerCharacter->GetPlayerMesh()->GetAnimInstance();
		//if (AnimInstance != nullptr)
		//{
		//	AnimInstance->Montage_Play(FireAnimation, 1.0f);
		//}

		PlayerCharacter->PlayAnimMontage(FireAnimation);
	}

	//// Sound
	//if (FireSound != nullptr)
	//{
	//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	//}
}

void USOWWeaponRifle::ReloadRifle()
{

}
