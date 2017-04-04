// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::setBarrelReference(UTankBarrel *barrelToSet) {
	barrel = barrelToSet;
}

void UTankAimingComponent::aimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel) { return; }

	FVector launchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

	//calculate launch velocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, launchVelocity, startLocation, hitLocation, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		auto aimDirection = launchVelocity.GetSafeNormal();
		barrel->moveBarrel(aimDirection.Rotation().Pitch);

	}

}
