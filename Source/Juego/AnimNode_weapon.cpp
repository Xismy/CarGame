// Fill out your copyright notice in the Description page of Project Settings.

#include "Juego.h"
#include "Runtime/Engine/Public/Animation/AnimInstanceProxy.h"
#include "weapon.h"
#include "AnimNode_weapon.h"

FAnimNode_weapon::FAnimNode_weapon(): pitch(0), yaw(0){

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
	EvaluateGraphExposedInputs.Execute(Context);
}

void FAnimNode_weapon::EvaluateComponentSpace(FComponentSpacePoseContext& Output) {
	ComponentPose.EvaluateComponentSpace(Output);
	TArray<FBoneTransform> transforms = TArray<FBoneTransform>();

	FCompactPoseBoneIndex index = (FCompactPoseBoneIndex)base.BoneIndex;
	FTransform transform = Output.Pose.GetComponentSpaceTransform(index);
	transform.SetRotation(FQuat(FVector(0, 0, 1), yaw));
	transforms.Add(FBoneTransform(index, transform));

	index = (FCompactPoseBoneIndex)arm.BoneIndex;
	transform = Output.Pose.GetComponentSpaceTransform(index);
	transform.SetRotation(FQuat(FVector(0, 0, 1), yaw));
	transform.ConcatenateRotation(FQuat(FVector(0, -1, 0), pitch));
	transforms.Add(FBoneTransform(index, transform));
	Output.Pose.LocalBlendCSBoneTransforms(transforms, 1);

}

