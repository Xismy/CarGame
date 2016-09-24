// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "projectile.h"
#include "weapon.generated.h"

UENUM()
enum class FireMode : uint8 {
	SEMIAUTOMATIC	UMETA(DisplayName = "Semiautomatic"),
	AUTOMATIC		UMETA(DisplayName = "Automatic"),
	BURST			UMETA(DisplayName = "Burst")
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JUEGO_API Uweapon : public UActorComponent
{
	GENERATED_BODY()

private:
	USkeletalMeshComponent* mesh;
	USpringArmComponent* spring;
	UInputComponent* input;
	float pitch, yaw;

public:	
	UPROPERTY(EditAnywhere)
	FireMode fireMode = FireMode::AUTOMATIC;

	UPROPERTY(EditAnywhere)
	uint16 fireRate = 300;

	UPROPERTY(EditAnywhere)
	Uprojectile* projectile;

	UPROPERTY(EditAnywhere)
	FName armBone;

	// Sets default values for this component's properties
	Uweapon();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void setCamera(USpringArmComponent* spring);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void setYaw(float angle);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void setPitch(float angle);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float getYaw();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float getPitch();
	
};
