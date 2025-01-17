// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void init(UTankTrack *leftToSet, UTankTrack *rightToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void intendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void intendTurnRight(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
	
private:
	UTankTrack *left = nullptr;

	UTankTrack *right = nullptr;
};
