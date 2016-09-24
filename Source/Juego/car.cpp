// Fill out your copyright notice in the Description page of Project Settings.

#include "Juego.h"
#include "car.h"

void Acar::BeginPlay(){
	Super::BeginPlay();

	//Get car components
	TSet<UActorComponent*> components = GetComponents();

	//Get camera arm
	USpringArmComponent* spring = 0;
	for (int i = 0; i < components.Num(); i++) {
		spring = Cast<USpringArmComponent>(components.Array()[i]);
		if (spring)
			break;
	}

	//Get weapon
	UChildActorComponent* child = 0;
	for (int i = 0; i < components.Num(); i++) {
		child = Cast<UChildActorComponent>(components.Array()[i]);
		if (child) {
			components = child->GetChildActor()->GetComponents();

			//Get weapon component and add camera
			for (int j = 0; j < components.Num(); j++) {
				weapon = Cast<Uweapon>(components.Array()[j]);
				if (weapon && spring) {
					weapon->setCamera(spring);
					break;
				}
			}
			break;
		}
	}
}

void Acar::nitro(float force, float cooldown, float time) {
	nitroForce = force;
	nitroCooldown = cooldown;
	nitroTime = -time;
	nitroState = nitroTime * getNitroLoad();
	if (flare1 != 0)
		flare1->Activate();
	if (flare2 != 0)
		flare2->Activate();
}

float Acar::getNitroLoad() {
	if (nitroState >= 0)
		return 1.0 - (nitroState / nitroCooldown);
	else
		return nitroState / nitroTime;
}

void Acar::addFlare(UParticleSystemComponent* flare1, UParticleSystemComponent* flare2) {
	this->flare1 = flare1;
	this->flare2 = flare2;
	if (flare1 != 0)
		flare1->Deactivate();
	if (flare2 != 0)
		flare2->Deactivate();
}

void Acar::Tick(float DeltaSeconds){
	if (nitroState != 0) {
		if (nitroState > 0) {
			nitroState -= DeltaSeconds;
			if (nitroState < 0) nitroState = 0;
		}
		else {
			nitroState += DeltaSeconds;
			GetMesh()->AddForce(GetActorForwardVector() * nitroForce);
			if (nitroState >= 0) {
				nitroState = nitroCooldown;
				if (flare1 != 0)
					flare1->Deactivate();
				if (flare2 != 0)
					flare2->Deactivate();
			}
		}
	}
}



