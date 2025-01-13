// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "SOWBulletProjectile.generated.h"

UCLASS()
class SYMPHONYOFWAR_API ASOWBulletProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Bullet mesh
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UMaterialInstanceDynamic* BulletMaterial;
	
	// Box collision component (box component around bullet with collision detection)
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UBoxComponent* CollisionComponent;

	// Projectile movement component (movement of bullet at fire)
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

	// Bullet damage to enemies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float BulletDamage = 0.05f;
	
	// Sets default values for this actor's properties
	ASOWBulletProjectile();

	// Projectile collision function
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Launches projectile in the forward direction
	void ProjectileLaunch(const FVector& BulletDirection);
};
