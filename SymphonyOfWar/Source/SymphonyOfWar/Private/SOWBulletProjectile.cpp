// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWBulletProjectile.h"
#include "SOWEnemyCharacter.h"

// Sets default values
ASOWBulletProjectile::ASOWBulletProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// COLLISION
	// Create box for collision detection around bullet
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ProjectileBoxComponent"));

	// Collision profile for projectile as created in engine project settings
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

	// Collision function called on bullet hit
	CollisionComponent->OnComponentHit.AddDynamic(this, &ASOWBulletProjectile::OnHit);

	// Set box component collision bounds
	CollisionComponent->InitBoxExtent(FVector(10.0f, 10.0f, 10.0f));

	// Set collision component as root component (location, rotation, scale and all other components must be attached to this)
	RootComponent = CollisionComponent;

	//UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, UAISense_Hearing::StaticClass(), this);

	// MESH
	// Create static mesh component for bullet
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	check(BulletMesh != nullptr);
	BulletMesh->SetMaterial(0, BulletMaterial);
	BulletMesh->SetupAttachment(CollisionComponent);

	// MOVEMENT
	// Create projectile movement component for bullet movement
	if (ProjectileMovementComponent == nullptr)
	{
		// Create component
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		
		// Set velocity of projectile and max lock
		ProjectileMovementComponent->InitialSpeed = 4000.0f;
		ProjectileMovementComponent->MaxSpeed = 4000.0f;

		// Assign the component to move and update
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);

		// Rotation updated every frame to match velocity
		ProjectileMovementComponent->bRotationFollowsVelocity = true;

		// Added behaviour to make the bullet behave more realistically
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.01f;
		ProjectileMovementComponent->ProjectileGravityScale = 5.0f;

		// Life span in world
		InitialLifeSpan = 0.3f;
	}

}

void ASOWBulletProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);

	ASOWEnemyCharacter* EnemyCharacter = Cast<ASOWEnemyCharacter>(OtherActor);
	if (EnemyCharacter != nullptr)
	{
		EnemyCharacter->ReceiveDamage(BulletDamage);
	}
}

// Called when the game starts or when spawned
void ASOWBulletProjectile::BeginPlay()
{
	Super::BeginPlay();

	/*check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Bullet fired"));*/
	
}

// Called every frame
void ASOWBulletProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASOWBulletProjectile::ProjectileLaunch(const FVector& BulletDirection)
{
	ProjectileMovementComponent->Velocity = BulletDirection * ProjectileMovementComponent->InitialSpeed;
}

