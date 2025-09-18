// Fill out your copyright notice in the Description page of Project Settings.


#include "BetterDoor.h"

// Sets default values
ABetterDoor::ABetterDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABetterDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABetterDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ShouldOpenOrClose)
	{
		FRotator CurrentRotation = GetActorRotation();
		FRotator NewRotation;
		NewRotation.Roll = CurrentRotation.Roll;
		NewRotation.Pitch = CurrentRotation.Pitch;
		NewRotation.Yaw = CurrentRotation.Yaw + YawIncrement;
		SetActorRotation(NewRotation);

		if ((YawIncrement > 0 && NewRotation.Yaw >= 90) || (YawIncrement < 90 && NewRotation.Yaw <= 0))
		{
			ShouldOpenOrClose = false;
		}

	}

}

void ABetterDoor::OpenDoor()
{
	if (GetActorRotation().Yaw < 90)
	{
		YawIncrement = 2.0f;
		ShouldOpenOrClose = true;
	}
}

void ABetterDoor::CloseDoor()
{
	if (GetActorRotation().Yaw > 90)
	{
		YawIncrement = -2.0f;
		ShouldOpenOrClose = true;
	}
}