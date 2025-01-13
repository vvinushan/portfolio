// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

// Testing integration between Visual Studio and UE5.3 with a floating actor, starter  code from UE5.3 documentation

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include <Components/PointLightComponent.h>
#include "FloatingActor.generated.h"

UCLASS()
class SYMPHONYOFWAR_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	// Static mesh for floating actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
	UStaticMeshComponent* FloatingMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
	UMaterialInstance* MeshMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloatMesh)
	UPointLightComponent* PointLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	float RotationSpeed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	float FloatingSpeed = 20.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fixed Values")
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
	float Scale = 20.0f;

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
};
