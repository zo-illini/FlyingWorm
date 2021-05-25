// Fill out your copyright notice in the Description page of Project Settings.


#include "DampingCube.h"

// Sets default values
ADampingCube::ADampingCube()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADampingCube::BeginPlay()
{
	Super::BeginPlay();

	isValid = (SourceCube != nullptr);

	if (isValid)
	{
		OriginalDistance = (SourceCube->GetActorLocation() - GetActorLocation()).Size();
		//OriginalRotation = (SourceCube->GetActorRotation() - GetActorRotation());
	}
}

// Called every frame
void ADampingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isValid)
	{
		FVector TargetedLocation = SourceCube->GetActorRotation().Vector() * (-OriginalDistance) + SourceCube->GetActorLocation();
		FRotator TargetedRotation = UKismetMathLibrary::MakeRotFromX((SourceCube->GetActorLocation() - GetActorLocation()).GetSafeNormal());

		// Add X Rotation component to the targeted rotation
		//TargetedRotation = FRotator(TargetedRotation.Pitch, TargetedRotation.Yaw, 0);
		//TargetedRotation.Roll = FMath::Lerp<float, float>(GetActorRotation().Roll, SourceCube->GetActorRotation().Roll, DampingRollWeight);
		TargetedRotation.Roll = SourceCube->GetActorRotation().Roll;
		/*float MyRoll = GetActorRotation().Roll;
		float step = RollSpeed * DeltaTime;
		if (FMath::Abs(MyRoll - SourceCube->GetActorRotation().Roll) > step) 
		{
			TargetedRotation.Roll = MyRoll + FMath::Sign(SourceCube->GetActorRotation().Roll - MyRoll) * step;
		}
		else 
		{
			TargetedRotation.Roll = SourceCube->GetActorRotation().Roll;
		}*/

		//TargetedRotation.Roll = FMath::Clamp(TargetedRotation.Roll, SourceCube->GetActorRotation().Roll + 90, SourceCube->GetActorRotation().Roll - 90);


		this->SetActorLocation((FMath::Lerp<FVector, float>(GetActorLocation(), TargetedLocation, DampingTranslationWeight)));
		//this->SetActorRotation(FMath::Lerp<FRotator, float>(GetActorRotation(), TargetedRotation, DampingRotationWeight));
		this->SetActorRotation(TargetedRotation);



	}


}

// Called to bind functionality to input
void ADampingCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

