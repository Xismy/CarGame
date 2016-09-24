// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WheeledVehicle.h"
#include "weapon.h"
#include "car.generated.h"

/**
 * 
 */
UCLASS()
class JUEGO_API Acar : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Car")
	void nitro(float force, float cooldown, float time);

	UFUNCTION(BlueprintCallable, Category = "Car")
	float getNitroLoad();

	UFUNCTION(BlueprintCallable, Category = "Car")
		void addFlare(UParticleSystemComponent* flare1, UParticleSystemComponent* flare2);

private:
	float nitroForce = 0;
	float nitroCooldown = 1;
	float nitroTime = 0;
	float nitroState = 0;//0->Ready, >0->Time to cooldown, <0->Working, time to finish
	UParticleSystemComponent* flare1,* flare2;
	Uweapon* weapon;
};
