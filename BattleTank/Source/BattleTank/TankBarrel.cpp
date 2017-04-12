// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::moveBarrel(float pitch) {
	//move barrel the right amount this frame 
	//given max elevation speed and frame time

	auto newPitch = FMath::Clamp<float>(pitch, -1, +1);
	auto elevationChange = newPitch * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto unclampedElevation = RelativeRotation.Pitch + elevationChange;

	auto clampedElevation = FMath::Clamp(unclampedElevation, minElevation, maxElevation);

	SetRelativeRotation(FRotator(clampedElevation, 0, 0));

}


