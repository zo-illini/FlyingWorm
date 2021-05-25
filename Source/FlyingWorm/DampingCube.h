// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "DampingCube.generated.h"

UCLASS()
class FLYINGWORM_API ADampingCube : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADampingCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		AActor* SourceCube;

	UPROPERTY(VisibleAnywhere)
		float OriginalDistance;
	
	//UPROPERTY(VisibleAnywhere)
		//FRotator OriginalRotation;

	UPROPERTY(VisibleAnywhere)
		bool isValid;
	
	UPROPERTY(EditAnywhere)
		float DampingTranslationWeight;
	UPROPERTY(EditAnywhere)
		float DampingRollWeight;
	UPROPERTY(EditAnywhere)
		float RollSpeed;

};
