// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; //forward declaration
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void setBarrelReference(UTankBarrel*);

	void setTurretReference(UTankTurret*);

	void aimAt(FVector, float);
	
private:
	UTankBarrel *barrel = nullptr;

	UTankTurret *turret = nullptr;

	void MoveBarrelTowards(FVector);

};
