// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWPlayerCharacter.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Kismet/GameplayStatics.h"

// Sets default values
ASOWPlayerCharacter::ASOWPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CAMERA
	// Create camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(CameraComponent != nullptr);

	// Attach camera component to the capsule component inside character blueprint
	CameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Set camera position
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	// Rotation control passed to possesed pawn
	CameraComponent->bUsePawnControlRotation = true;


	// PLAYER MESH
	// Create skeletal mesh component
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(PlayerMesh != nullptr);

	// Only the player can see the arms mesh
	PlayerMesh->SetOnlyOwnerSee(true);
	GetMesh()->SetOwnerNoSee(true);

	// Attach skeletal mesh component to camera component and disable shadows
	PlayerMesh->SetupAttachment(CameraComponent);
	PlayerMesh->bCastDynamicShadow = false;
	PlayerMesh->CastShadow = false;
	
	// WEAPON
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	check(WeaponMesh != nullptr);

	// Attach skeletal mesh component to camera component and disable shadows
	WeaponMesh->SetupAttachment(PlayerMesh);
	WeaponMesh->bCastDynamicShadow = false;
	WeaponMesh->CastShadow = false;

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	WeaponMesh->AttachToComponent(PlayerMesh, AttachmentRules, "hand_r_weapon");

	//RifleClass = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RifleMesh"));
	//// Attach weapon to character mesh
	//FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, true);
	//AttachToComponent(GetMesh(), AttachmentTransformRules, TEXT("hand_r_weapon"));
}

// Called when the game starts or when spawned
void ASOWPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("SOWPlayerCharacter active"));*/
	
	//// Gets the enhanced input subsystem for this player controller
	//if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	//	{
	//		// Add the mapping context so we get default movement controls, will be changed for menus in future
	//		Subsystem->AddMappingContext(DefaultMappingContext, 1);
	//	}
	//}
	//SpawnActorFromClass

	/*UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FActorSpawnParameters ActorSpawnParameters;

		World->SpawnActor<ASOWRifleActor>(WeaponClass, MuzzleLocation, MuzzleRotation);
	}*/
}

// Called every frame
void ASOWPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASOWPlayerCharacter::Jump()
{
	Super::Jump();
}

void ASOWPlayerCharacter::StopJumping()
{
	Super::StopJumping();
}

void ASOWPlayerCharacter::ReceiveDamage(float Damage)
{
	Health = Health - Damage;
	IsDamageTaken = true;

	if (Health <= 0)
	{
		UGameplayStatics::OpenLevel(this, "DeathMenuMap", false);
	}
}

USkeletalMeshComponent* ASOWPlayerCharacter::GetPlayerMesh()
{
	return PlayerMesh;
}

UCameraComponent* ASOWPlayerCharacter::GetCameraComponent()
{
	return CameraComponent;
}

int ASOWPlayerCharacter::GetHealth()
{
	return Health;
}

//// Called to bind functionality to input
//void ASOWPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//	// Cast to enhanced input component from controller input component to bind input actions
//	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
//
//	EnhancedInputComponent->BindAction(PlayerFireAction, ETriggerEvent::Triggered, this, &ASOWPlayerCharacter::DoPlayerFire);
//
//}
//
//void ASOWPlayerCharacter::DoPlayerFire()
//{
//	UAnimInstance* AnimInstance = PlayerMesh->GetAnimInstance();
//		if (AnimInstance != nullptr)
//		{
//			AnimInstance->Montage_Play(PlayerFireAnimation, 1.0f);
//		}
//
//	//PlayAnimMontage(PlayerFireAnimation, 1.0f);
//}
//
//void ASOWPlayerCharacter::DoPlayerReload()
//{
//	PlayAnimMontage(PlayerReloadAnimation, 5.0f);
//}

