// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::getControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (getPlayerTank()) {
		//move towards player

		//aim towards player
		getControlledTank()->aimAt(getPlayerTank()->GetActorLocation());

		//fire when ready
	}
}


ATank* ATankAIController::getPlayerTank() const {
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerTank) { return nullptr; }

	return Cast<ATank>(playerTank);
}
