// Fill out your copyright notice in the Description page of Project Settings.

#include "Juego.h"
#include "Runtime/Engine/Public/Animation/AnimInstanceProxy.h"
#include "weapon.h"
#include "AnimNode_weapon.h"

FAnimNode_weapon::FAnimNode_weapon(){

}


void FAnimNode_weapon::Initialize(const FAnimationInitializeContext& Context) {
	ComponentPose.Initialize(Context);
}

void FAnimNode_weapon::CacheBones(const FAnimationCacheBonesContext & Context) {
	FBoneContainer bones = Context.AnimInstanceProxy->GetRequiredBones();
	base.Initialize(bones);
	arm.Initialize(bones);
	ComponentPose.CacheBones(Context);
}

void FAnimNode_weapon::Update(const FAnimationUpdateContext & Context) {
	ComponentPose.Update(Context);
}

void FAnimNode_weapon::EvaluateComponentSpace(FComponentSpacePoseContext& Output) {
	ComponentPose.EvaluateComponentSpace(Output);
	float pitch = 0;//weapon->getPitch();
	float yaw = 1.57;//weapon->getYaw();

	FCompactPoseBoneIndex index = (FCompactPoseBoneIndex)base.BoneIndex;
	FTransform transform = Output.Pose.GetComponentSpaceTransform(index);
	transform.SetRotation(FQuat(cos(yaw/2), 0, 0, cos(yaw/2)));
	Output.Pose.SetComponentSpaceTransform(index, transform);

	/*index = (FCompactPoseBoneIndex)arm.BoneIndex;
	transform = Output.Pose.GetComponentSpaceTransform(index);
	transform.SetRotation(FQuat(cos(yaw / 2), 0, sin(yaw / 2),0));
	Output.Pose.SetComponentSpaceTransform(index, transform);*/
}
