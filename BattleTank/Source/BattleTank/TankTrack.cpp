// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::setThrottle(float throttle) {
	throttle = FMath::Clamp<float>(throttle, -1, +1);

	auto forceApplied = GetForwardVector() * throttle * maxDrivingForce;
	auto forceLocation = GetComponentLocation();

	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}


