// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/AirPlane.h"

// Sets default values
AAirPlane::AAirPlane()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AAirPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAirPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAirPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

