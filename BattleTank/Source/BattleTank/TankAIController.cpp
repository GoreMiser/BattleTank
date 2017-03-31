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

ATank* ATankAIController::getPlayerTank() const {
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerTank) { return nullptr; }

	return Cast<ATank>(playerTank);
}
