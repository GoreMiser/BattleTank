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
		getControlledTank()->aimAt(hitLocation);
	}

}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::getSightRayHitLocation(FVector &hitLocation) const {
	bool retVal = false;

	//find crosshair
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	auto crosshairScreenLocation = FVector2D(viewportSizeX*crosshairLocationX, viewportSizeY*crosshairLocationY);

	//de-project the screen position of the crosshair to a world direction
	FVector lookDirection;
	if (getLookDirection(crosshairScreenLocation, lookDirection)) {
		//line trace along that and see what we hit
		getLookVectorHitLocation(lookDirection, hitLocation);
		retVal = true;
	}



	return retVal;
}

bool ATankPlayerController::getLookDirection(FVector2D screenLocation, FVector &lookDirection) const {

	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}

bool ATankPlayerController::getLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const {

	bool retVal = false;

	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * lineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)){
		hitLocation = hitResult.Location;
		retVal = true;
	}
	else {
		hitLocation = FVector(0);
	}

	return retVal;
}