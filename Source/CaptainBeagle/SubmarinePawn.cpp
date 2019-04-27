// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarinePawn.h"

// Sets default values
ASubmarinePawn::ASubmarinePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASubmarinePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASubmarinePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASubmarinePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAxis("MoveUpDown", this, &ASubmarinePawn::MoveUpDown);
	PlayerInputComponent->BindAxis("MoveRightLeft", this, &ASubmarinePawn::MoveRightLeft);

// 	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASubmarinePawn::TouchStarted);
// 	PlayerInputComponent->BindTouch(IE_Released, this, &ASubmarinePawn::TouchStopped);

}

void ASubmarinePawn::MoveUpDown(float value)
{
	AddMovementInput(FVector(0.0f, 0.0f, 1.0f), value);
}

void ASubmarinePawn::MoveRightLeft(float value)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value);
}

