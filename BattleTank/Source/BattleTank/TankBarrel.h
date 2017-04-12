// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void moveBarrel(float);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevation = 0;
	
};
