// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperHero.h"
#include "UE_Direction.h"

APaperHero::APaperHero()
{
	PrimaryActorTick.bCanEverTick = true;
	direction = Direction::Right;
	bIsMoving = false;
}

void APaperHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Move"), this, &APaperHero::Move);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ACharacter::StopJumping);
}

void APaperHero::BeginPlay()
{
	Super::BeginPlay();
}

void APaperHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APaperHero::Move(float value)
{
	if (value != 0.0f)
	{
		FVector Direction = FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, value);
		SetDirection(value);
		bIsMoving = true;
	}
	else 
	{
		if (bIsMoving) // Will execute once before being skipped each frame until movement occurs again.
		{
			SetDirection(value);
			bIsMoving = false;
		}
	}
}

void APaperHero::SetDirection(float value)
{
	if (value > 0.0f)
	{
		direction = Direction::Right;
		UE_LOG(LogTemp, Warning, TEXT("Setting direction: Right"));
	}
	else
	{
		if (value < 0.0f)
		{
			direction = Direction::Left;
			UE_LOG(LogTemp, Warning, TEXT("Setting direction: Left"));
		}
		
	}
}

void APaperHero::Fire()
{
}

void APaperHero::StopFire()
{
}


