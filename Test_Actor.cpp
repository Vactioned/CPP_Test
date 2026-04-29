// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Actor.h"

// Sets default values
ATest_Actor::ATest_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATest_Actor::BeginPlay()
{
	Super::BeginPlay();

	// 0 0 50에서 시작
	SetActorLocation(FVector(0, 0, 50));
	for (int32 i = 0; i < 10; ++i)
		Move();

	for (int32 i = 0; i < 10; ++i)
		Turn();
	
}

void ATest_Actor::Move()
{
	FVector Target;

	// -50~50까지 Random인 수
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;

	AddActorWorldOffset(Target);

	FVector CurrentLocation = GetActorLocation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, CurrentLocation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("Location = %s"), *CurrentLocation.ToString());
	
}

void ATest_Actor::Turn()
{
	FRotator DeltaRotation;
	DeltaRotation.Yaw = FMath::FRandRange(-180.0, 180.0);
	DeltaRotation.Pitch = 0;
	DeltaRotation.Roll= 0;

	AddActorWorldRotation(DeltaRotation);

	FRotator CurrentRotation = GetActorRotation();
	if (GEngine)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, CurrentRotation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("Rotation = %s"), *CurrentRotation.ToString());

}