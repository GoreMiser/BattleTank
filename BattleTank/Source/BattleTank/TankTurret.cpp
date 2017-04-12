// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::moveTurret(float yaw) {
	//move turret the right amount this frame 
	//given max elevation speed and frame time

	auto newYaw = FMath::Clamp<float>(yaw, -1, +1);
	auto rotationChange = newYaw * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rotation = RelativeRotation.Yaw + rotationChange;

	SetRelativeRotation(FRotator(0, rotation, 0));

}

