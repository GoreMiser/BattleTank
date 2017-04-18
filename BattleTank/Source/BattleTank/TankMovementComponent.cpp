// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::init(UTankTrack *leftToSet, UTankTrack *rightToSet) {
	left = leftToSet;
	right = rightToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	
}

void UTankMovementComponent::intendMoveForward(float Throw) {
	left->setThrottle(Throw);
	right->setThrottle(Throw);
}

void UTankMovementComponent::intendTurnRight(float Throw) {
	left->setThrottle(Throw);
	right->setThrottle(-Throw);
}