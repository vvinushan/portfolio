// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Components/BoxComponent.h>
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "SOWEnemyCharacter.generated.h"

UCLASS()
class SYMPHONYOFWAR_API ASOWEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Enemy mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* EnemyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAISenseConfig_Sight* SenseConfig_Sight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAISenseConfig_Hearing* SenseConfig_Hearing;

	// Enemy health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Health = 1.0f;

	// Enemy damage to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float DamageOut = 0.05f;

	// Enemy is overlapping player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool IsStillDamaging = false;

	// Enemy speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Speed = 100.0f;

	// Starting location of enemy and one that enemy will return to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector HomingLocation;

	// Starting rotation of enemy and one that enemy will return to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FRotator HomingRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector PlayerLocation;

	// Location that enemy will travel to (position of player when sensed)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector NewLocation;

	// Rotate enemy towards angle of player location when sensed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FRotator NewRotation;

	/* Code below taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:11:59 and 1:27:58 */
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool BackToBaseLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float DistanceSquared;

	/* Code above taken from/inspired by Fahir from Awesome Tuts at https://www.youtube.com/watch?v=4HoJIgyclZ4 between 1:11:59 and 1:27:58 */

	// Sets default values for this character's properties
	ASOWEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnSenseUpdate(const TArray<AActor*> &SourceActors);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void SetNewRotation(const FVector TargetPosition, FVector CurrentPosition);

	UFUNCTION()
	void ReceiveDamage(float Damage);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	int GetHealth();

	//// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
