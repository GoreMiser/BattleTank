// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::getControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	aimTowardsCrosshair();
}

void ATankPlayerController::aimTowardsCrosshair() {
	if (!getControlledTank()) { return; }

	FVector hitLocation;

	//get world location of linetrace through crosshair
	if (getSightRayHitLocation(hitLocation)) { //line traces and puts that in hit location

		//tell tank to aim at this point
	}

}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::getSightRayHitLocation(FVector &hitLocation) const {
	bool retVal = false;
	hitLocation = FVector(1.0);

	return true;
}