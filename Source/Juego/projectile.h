// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "projectile.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JUEGO_API Uprojectile : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	uint32 velocity = 30000;

	UPROPERTY(EditAnywhere)
	float mass = 0.01;

	UPROPERTY(EditAnywhere)
	uint8 explossionRadius = 0;

	UPROPERTY(EditAnywhere)
	UStaticMesh* mesh;

	// Sets default values for this component's properties
	Uprojectile();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void shot();
};
