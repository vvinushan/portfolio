// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// MESH
	// Attaching mesh component to actor
	FloatingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	FloatingMesh->SetupAttachment(RootComponent);

	// MATERIAL
	FloatingMesh->SetMaterial(0, MeshMaterialInstance);

	// POINT LIGHT
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	PointLight->SetLightBrightness(50.f);
	PointLight->SetLightFalloffExponent(8);
	PointLight->SetupAttachment(FloatingMesh);

	// COLLISION BOX
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Collision Box");
	CollisionBox->SetupAttachment(FloatingMesh);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AFloatingActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AFloatingActor::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = GetActorLocation();

	// Rotation
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * FloatingSpeed;
	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
	CurrentLocation = NewLocation;
}

void AFloatingActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AFloatingActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

