// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BetterDoor.generated.h"

UCLASS()
class ALI_CPP_TUT_API ABetterDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABetterDoor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorMesh;

	bool ShouldOpenOrClose;
	float YawIncrement;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void OpenDoor();
	
	UFUNCTION(BlueprintCallable, Category = "Actions")
	void CloseDoor();

};
