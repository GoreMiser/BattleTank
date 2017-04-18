// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto controlledTank = Cast<ATank>(GetPawn());

	if (playerTank) {
		//move towards player
		MoveToActor(playerTank, 5000);

		//aim towards player
		controlledTank->aimAt(playerTank->GetActorLocation());

		//fire when ready
		controlledTank->fire();
	}
}