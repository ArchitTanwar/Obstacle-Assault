// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCharacter.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	private:

	UPROPERTY(EditAnywhere , Category = "Moving");
	FVector ObjectVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere , Category = "Moving");
	float MovedDistance = 100;
	UPROPERTY(EditAnywhere , Category = "Rotation");
	FRotator RotationVelocity;

	 FVector StartLocation;

	void MoveCharacter(float DeltaTime);

	void RotateCharacter(float DeltaTime);

	bool ShouldCharacterReturn() const;

	float GetDistanceMoved() const;

};
