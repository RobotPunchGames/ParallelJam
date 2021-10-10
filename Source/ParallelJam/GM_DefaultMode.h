// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_DefaultMode.generated.h"

/**
 * 
 */
UCLASS()
class PARALLELJAM_API AGM_DefaultMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_DefaultMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Time)
	float gameTimeElapsed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Time)
	float gameTimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameManager)
	FString currentMapName;
};
