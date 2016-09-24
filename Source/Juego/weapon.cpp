// Fill out your copyright notice in the Description page of Project Settings.

#include "Juego.h"
#include "weapon.h"


// Sets default values for this component's properties
Uweapon::Uweapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uweapon::BeginPlay()
{
	Super::BeginPlay();

	//Get weapon components
	TSet<UActorComponent*> components = GetOwner()->GetComponents();
	
	//Get mesh
	for (int i = 0; i < components.Num(); i++) {
		mesh = Cast<USkeletalMeshComponent>(components.Array()[i]);
		if (mesh)
			break;
	}

	//Attach to mesh bone
	if (spring)
		spring->AttachToComponent(mesh, FAttachmentTransformRules::KeepWorldTransform, armBone);
	
	//Bind inputs
	GetOwner()->InputComponent->BindAxis("Vertical Camera", this, &Uweapon::setPitch);
	GetOwner()->InputComponent->BindAxis("Horizontal Camera", this, &Uweapon::setYaw);
}


// Called every frame
void Uweapon::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void Uweapon::setCamera(USpringArmComponent * spring){
	this->spring = spring;

	if(mesh)
		spring->AttachToComponent(mesh, FAttachmentTransformRules::KeepWorldTransform, armBone);
}

void Uweapon::setYaw(float angle) {
	this->yaw = angle;
}

void Uweapon::setPitch(float angle) {
	this->pitch = angle;
}

float Uweapon::getYaw() {
	return yaw;
}


float Uweapon::getPitch() {
	return pitch;
}

