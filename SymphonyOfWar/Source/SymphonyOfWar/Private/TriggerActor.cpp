// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "TriggerActor.h"

// Sets default values
ATriggerActor::ATriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// MESH
	// Attaching mesh component to actor
	TriggerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	TriggerMesh->SetupAttachment(RootComponent);

	// MATERIAL
	TriggerMesh->SetMaterial(0, MeshMaterialInstance);

	// COLLISION BOX
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Collision Box");
	CollisionBox->SetupAttachment(TriggerMesh);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATriggerActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATriggerActor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ATriggerActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

