// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWEnemyCharacter.h"
#include "SOWPlayerCharacter.h"

// Sets default values
ASOWEnemyCharacter::ASOWEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// MESH
	// Create skeletal mesh component
	EnemyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyMesh"));
	check(EnemyMesh != nullptr);

	// Attach camera component to the capsule component inside character blueprint
	EnemyMesh->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// COLLISION BOX
	// Create collision box around enemy (damage player on collision)
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Collision Box");
	CollisionBox->SetupAttachment(EnemyMesh);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASOWEnemyCharacter::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ASOWEnemyCharacter::OnOverlapEnd);

	// AI
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	SenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISight"));
	SenseConfig_Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("AIHearing"));
	// Touch sense used for damage?

	SenseConfig_Sight->SightRadius = 1000.0f;
	SenseConfig_Sight->LoseSightRadius = 1100.0f;
	SenseConfig_Sight->PeripheralVisionAngleDegrees = 90.0f;
	SenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = true;
	//SenseConfig_Sight->AutoSuccessRangeFromLastSeenLocation = 100.0f;
	SenseConfig_Sight->GetDebugColor().Green;
	SenseConfig_Sight->SetMaxAge(0.1f);
	SenseConfig_Sight->IsEnabled();
	AIPerceptionComponent->ConfigureSense(*SenseConfig_Sight);

	/*SenseConfig_Hearing->HearingRange = 1000.f;
	SenseConfig_Hearing->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig_Hearing->GetDebugColor().Red;
	SenseConfig_Hearing->SetMaxAge(1.0f);
	SenseConfig_Hearing->IsEnabled();
	AIPerceptionComponent->ConfigureSense(*SenseConfig_Hearing);*/

	AIPerceptionComponent->SetDominantSense(SenseConfig_Sight->GetSenseImplementation());
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ASOWEnemyCharacter::OnSenseUpdate);

	/* Code below taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:11:59 and 1:27:58 */

	CurrentVelocity = FVector::ZeroVector;
	DistanceSquared = BIG_NUMBER;

	/* Code above taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:11:59 and 1:27:58 */
}

// Called when the game starts or when spawned
void ASOWEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	HomingLocation = GetActorLocation();
	HomingRotation = GetActorRotation();
	//UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, SenseConfig_Sight->GetSenseImplementation(), GetControlledPawn());
}

// Called every frame
void ASOWEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* Code below taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */
	// This code has also been blueprinted for testing purposes

	if (!CurrentVelocity.IsZero())
	{
		/*if (IsStillDamaging == true)
		{
			NewLocation = GetActorLocation();
		}
		else
		{
			NewLocation = GetActorLocation() + CurrentVelocity * DeltaTime;
		}*/

		NewLocation = GetActorLocation() + CurrentVelocity * DeltaTime;

		if (BackToBaseLocation)
		{
			if ((NewLocation - HomingLocation).SizeSquared2D() < DistanceSquared)
			{
				DistanceSquared = (NewLocation - HomingLocation).SizeSquared2D();
			}
			else
			{
				CurrentVelocity = FVector::ZeroVector;
				DistanceSquared = BIG_NUMBER;
				BackToBaseLocation = false;

				SetNewRotation(GetActorForwardVector(), GetActorLocation());
			}
		}

		SetActorLocation(NewLocation);
	}


	/* Code above taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */
}

void ASOWEnemyCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASOWPlayerCharacter* PlayerCharacter = Cast<ASOWPlayerCharacter>(OtherActor);

	if (PlayerCharacter != nullptr)
	{
		IsStillDamaging = true;
		//PlayerCharacter->ReceiveDamage(DamageOut);
	}
}

void ASOWEnemyCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IsStillDamaging = false;
}

void ASOWEnemyCharacter::ReceiveDamage(float Damage)
{
	Health = Health - Damage;

	if (Health <= 0)
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemy dead"));
		
		Destroy();
	}
}

int ASOWEnemyCharacter::GetHealth()
{
	return Health;
}

void ASOWEnemyCharacter::OnSenseUpdate(const TArray<AActor*> &SourceActors)
{
	/* Code below taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */
	for (int i = 0; i < SourceActors.Num(); i++)
	{
		FActorPerceptionBlueprintInfo Info;

		AIPerceptionComponent->GetActorsPerception(SourceActors[i], Info);

		if (Info.LastSensedStimuli[i].WasSuccessfullySensed())
		{
			FVector dir = SourceActors[i]->GetActorLocation() - GetActorLocation();
			dir.Z = 0.0f;

			CurrentVelocity = dir.GetSafeNormal() * Speed;

			SetNewRotation(SourceActors[i]->GetActorLocation(), GetActorLocation());
		}
		else
		{
			FVector dir = HomingLocation - GetActorLocation();

			dir.Z = 0.0f;

			if (dir.SizeSquared2D() > 1.0f)
			{
				CurrentVelocity = dir.GetSafeNormal() * Speed;
				BackToBaseLocation = true;

				SetNewRotation(HomingLocation, GetActorLocation());
			}
		}
	}
	/* Code above taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */
}

/* Code below taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */
void ASOWEnemyCharacter::SetNewRotation(FVector TargetPosition, FVector CurrentPosition)
{
	FVector NewDirection = TargetPosition - CurrentPosition;
	NewDirection.Z = 0.0f;

	NewRotation = NewDirection.Rotation();

	SetActorRotation(NewRotation);
}
/* Code above taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:27:58 and 1:44:34 */

//void ASOWEnemyCharacter::OnHearingUpdate(TArray<AActor*> SourceActors)
//{
//
//}

//// Called to bind functionality to input
//void ASOWEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

