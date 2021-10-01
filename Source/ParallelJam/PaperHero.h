// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE_Direction.h"
#include "PaperCharacter.h"
#include "PaperHero.generated.h"

/**
 * 
 */
UCLASS()
class PARALLELJAM_API APaperHero : public APaperCharacter
{
	GENERATED_BODY()	

public: 
	APaperHero();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Direction)
	TEnumAsByte<Direction> direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Direction)
	bool bIsMoving;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetDirection(float value);

	virtual void Fire();

	virtual void StopFire();

private:
	UFUNCTION()
	void Move(float value);
};
