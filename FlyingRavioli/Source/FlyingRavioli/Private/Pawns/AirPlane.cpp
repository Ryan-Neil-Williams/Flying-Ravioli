// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/AirPlane.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AAirPlane::AAirPlane()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f, true);
	Capsule->SetCapsuleRadius(15.f, true);
	SetRootComponent(Capsule);

	AirPlaneMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("AirPlaneMesh"));
	AirPlaneMesh->SetupAttachment(GetRootComponent());
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Capsule);
	SpringArm->TargetArmLength = 600.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	ViewCamera->SetupAttachment(SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AAirPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAirPlane::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		//FVector Forward = GetActorForwardVector();
		//AddMovementInput(Forward, Value);
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(ControlRotation.Pitch, ControlRotation.Yaw, 0.f); // may need pitch to not be zeroed out.

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAirPlane::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AAirPlane::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AAirPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAirPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AAirPlane::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AAirPlane::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AAirPlane::LookUp);

}

