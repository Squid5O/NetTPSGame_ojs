// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "NetPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETTPSGAME_API UNetPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bHasPistol = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Speed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Direction = 0.0f;
	
};
