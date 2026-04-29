// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AirPlane.generated.h"

UCLASS()
class FLYINGRAVIOLI_API AAirPlane : public APawn
{
	GENERATED_BODY()

public:
	AAirPlane();
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

};
