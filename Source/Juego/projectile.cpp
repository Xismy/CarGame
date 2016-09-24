// Fill out your copyright notice in the Description page of Project Settings.

#include "Juego.h"
#include "projectile.h"


// Sets default values for this component's properties
Uprojectile::Uprojectile()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	//((UStaticMeshComponent*)mesh)->AttachTo(GetOwner()->GetRootComponent());
}


// Called when the game starts
void Uprojectile::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Uprojectile::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void Uprojectile::shot(){
	FVector velocity = FVector(this->velocity, 0, 0);
	((UStaticMeshComponent*)GetOwner())->SetPhysicsLinearVelocity(velocity);
}

