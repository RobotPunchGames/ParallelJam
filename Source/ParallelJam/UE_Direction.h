// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "UE_Direction.generated.h"

UENUM(BlueprintType)
	enum class Direction : uint8
	{
		Left	UMETA(DisplayName = "Left"),
		Right	UMETA(DisplayName = "Right")
	};