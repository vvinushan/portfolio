// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWPlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Kismet/GameplayStatics.h"



void ASOWPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("SOWPlayerController active"));*/

	// Gets the enhanced input subsystem for this player controller
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// Add the mapping context so we get default movement controls, will be changed for menus in future
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	AmmoCount = 30;
}

void ASOWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast to enhanced input component from controller input component to bind input actions
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	// Binds input action assets from engine property values to relevant functions
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASOWPlayerController::MovePlayer);
	EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ASOWPlayerController::CameraPlayer);
	EnhancedInputComponent->BindAction(WeaponFireAction, ETriggerEvent::Started, this, &ASOWPlayerController::StartFireWeapon);
	EnhancedInputComponent->BindAction(WeaponFireAction, ETriggerEvent::Completed, this, &ASOWPlayerController::EndFireWeapon);
	EnhancedInputComponent->BindAction(WeaponReloadAction, ETriggerEvent::Started, this, &ASOWPlayerController::StartReloadWeapon);
	EnhancedInputComponent->BindAction(WeaponReloadAction, ETriggerEvent::Completed, this, &ASOWPlayerController::EndReloadWeapon);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASOWPlayerController::JumpPlayer);
}

void ASOWPlayerController::MovePlayer(const FInputActionInstance& Instance)
{
	// Get the value of input to move player
	FVector2D MoveAxisValue = Instance.GetValue().Get<FVector2D>();
	
	// Get the current direction of player
	FVector WorldDirectionX = FRotationMatrix(GetPawn()->GetControlRotation()).GetScaledAxis(EAxis::X);
	FVector WorldDirectionY = FRotationMatrix(GetPawn()->GetControlRotation()).GetScaledAxis(EAxis::Y);

	// Pointers to pawn currently being possessed (player)
	GetPawn()->AddMovementInput(WorldDirectionY, MoveAxisValue.X);
	GetPawn()->AddMovementInput(WorldDirectionX, MoveAxisValue.Y);
}

void ASOWPlayerController::JumpPlayer()
{
	ACharacter* PlayerCharacter = Cast<ACharacter>(GetPawn());
	PlayerCharacter->Jump();
}


void ASOWPlayerController::CameraPlayer(const FInputActionInstance& Instance)
{
	// Get the value of input to move camera
	FVector2D CamAxisValue = Instance.GetValue().Get<FVector2D>();

	// Pointer to pawn currently being possessed (player)
	GetPawn()->AddControllerYawInput(CamAxisValue.X);
	GetPawn()->AddControllerPitchInput(CamAxisValue.Y);
}

void ASOWPlayerController::StartFireWeapon()
{
	if (IsReloading != true)
	{
			IsFiring = true;
			FireWeapon();
	}
}

void ASOWPlayerController::FireWeapon()
{	
	if (ProjectileClass != nullptr && AmmoCount != 0)
	{
		//FVector CameraLocation = GetPawn()->GetCameraComponent()->GetRelativeLocation();
		FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
		//FRotator CameraRotation = PlayerCharacter->GetCameraComponent()->GetRelativeRotation();
		FRotator CameraRotation = PlayerCameraManager->GetCameraRotation();

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		/*UWorld* World = GetWorld();
		if (World != nullptr)
		{
			FActorSpawnParameters ActorSpawnParameters;

			World->SpawnActor<ASOWBulletProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation);
		}*/

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the muzzle.
			ASOWBulletProjectile* Projectile = World->SpawnActor<ASOWBulletProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile != nullptr)
			{
				// Set the projectile's initial trajectory.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->ProjectileLaunch(LaunchDirection);
				UGameplayStatics::PlaySoundAtLocation(this, WeaponFireSound, GetPawn()->GetActorLocation());
				AmmoCount--;
			}
		}
	}
	else
		UGameplayStatics::PlaySoundAtLocation(this, WeaponEmptySound, GetPawn()->GetActorLocation());
}

void ASOWPlayerController::EndFireWeapon()
{
	if (IsFiring != false)
	{
		IsFiring = false;
		//GetWorldTimerManager().ClearTimer(WeaponFireTimerHandle);
	}
}

void ASOWPlayerController::StartReloadWeapon()
{
	if (IsFiring != true && AmmoCount != 30)
	{
		IsReloading = true;
		AmmoCount = 0;

		//GetWorldTimerManager().SetTimer(WeaponTimerHandle, this, &ASOWPlayerController::ReloadWeapon, 2.0f, false);
		ReloadWeapon();
	}
}

void ASOWPlayerController::ReloadWeapon()
{
	UGameplayStatics::PlaySoundAtLocation(this, WeaponReloadSound, GetPawn()->GetActorLocation());
	AmmoCount = 30;

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Weapon reloaded"));*/
}

void ASOWPlayerController::EndReloadWeapon()
{
	if (IsReloading != false)
	{
		IsReloading = false;
		//GetWorldTimerManager().ClearTimer(WeaponTimerHandle);
	}
}

int ASOWPlayerController::GetAmmoCount()
{
	return AmmoCount;
}
