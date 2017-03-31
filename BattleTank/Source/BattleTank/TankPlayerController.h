// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank* getControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void aimTowardsCrosshair();

	bool getSightRayHitLocation(FVector&) const;

	bool getLookDirection(FVector2D, FVector&) const;
	
	bool getLookVectorHitLocation(FVector, FVector&) const;

	UPROPERTY(EDITANYWHERE)
	float crosshairLocationX = 0.5;

	UPROPERTY(EDITANYWHERE)
	float crosshairLocationY = 0.33333;

	UPROPERTY(EDITANYWHERE)
	float lineTraceRange = 1000000.0;
};
