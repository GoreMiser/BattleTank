// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

}

void ATank::setBarrelReference(UTankBarrel *barrelToSet) {
	tankAimingComponent->setBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::setTurretReference(UTankTurret *turretToSet) {
	tankAimingComponent->setTurretReference(turretToSet);
}

void ATank::fire() {
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTime;

	if (barrel && isReloaded) {
		//spawn projectile at socket place
		auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBP, barrel->GetSocketLocation(FName("Projectile")), barrel->GetSocketRotation(FName("Projectile")));

		projectile->launch(launchSpeed);

		lastFireTime = FPlatformTime::Seconds();
	}
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::aimAt(FVector hitLocation) {
	tankAimingComponent->aimAt(hitLocation, launchSpeed);
}

