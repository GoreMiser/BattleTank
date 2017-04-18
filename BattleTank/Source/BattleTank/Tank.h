// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; //forward declaration
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void aimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelReference(UTankBarrel *barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTurretReference(UTankTurret *turretToSet);

protected:
	UTankAimingComponent *tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float launchSpeed = 4000;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> projectileBP;

	UTankBarrel *barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float reloadTime = 3;
	double lastFireTime = 0;

};
