// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCharacter.h"

// Sets default values
AMovingCharacter::AMovingCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FString MyString = "My String Value";

	UE_LOG(LogTemp, Display, TEXT("Here's my string : %s"), *MyString);

}

// Called when the game starts or when spawned
void AMovingCharacter::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveCharacter(DeltaTime); 
	RotateCharacter(DeltaTime);
}

void AMovingCharacter::MoveCharacter(float DeltaTime)
{

	if(ShouldCharacterReturn())
	{
		
		FVector MoveDirection = ObjectVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection*MovedDistance);
		SetActorLocation(StartLocation);
		ObjectVelocity = -ObjectVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
	    CurrentLocation = CurrentLocation + (ObjectVelocity * DeltaTime);
        SetActorLocation(CurrentLocation);
    }
}
void AMovingCharacter::RotateCharacter(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}
bool AMovingCharacter::ShouldCharacterReturn() const
{
	return GetDistanceMoved() > MovedDistance;
}
float AMovingCharacter::GetDistanceMoved() const 
{
	return FVector::Dist(StartLocation , GetActorLocation());
}