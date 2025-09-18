// Fill out your copyright notice in the Description page of Project Settings.

#include "Ali_CPP_TutCharacter.h"
#include "BetterPressurePlate.h"
#include "Components/SphereComponent.h"

// Sets default values
ABetterPressurePlate::ABetterPressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	PlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateMesh"));
	PlateMesh->SetupAttachment(RootComponent);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(PlateMesh);
	SphereCollision->SetSphereRadius(100.0f);

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABetterPressurePlate::OnPressurePlatePressed);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ABetterPressurePlate::OnPressurePlateReleased);

}

// Called when the game starts or when spawned
void ABetterPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABetterPressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABetterPressurePlate::OnPressurePlatePressed_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
													UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
													bool bFromSweep, const FHitResult& SweepResult)
{
	// Use the correct class name with 'A' prefix
	if (OtherActor->IsA(AAli_CPP_TutCharacter::StaticClass()) && DoorRef)
	{
		DoorRef->OpenDoor();
		PlateMesh->SetMaterial(0, PressedPlateMeshMaterial);
	}
}

void ABetterPressurePlate::OnPressurePlateReleased_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
													UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Use the correct class name with 'A' prefix
	if (OtherActor->IsA(AAli_CPP_TutCharacter::StaticClass()) && DoorRef)
	{
		DoorRef->CloseDoor();
		PlateMesh->SetMaterial(0, DefaultPlateMeshMaterial);
	}
}