// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorExtension.h"
#include "Editor/AnimGraph/Private/AnimGraphPrivatePCH.h"
#include "AnimationGraphSchema.h"
#include "AnimGraphNode_weapon.h"

#define LOCTEXT_NAMESPACE "AnimGraph_weapon"


FText UAnimGraphNode_weapon::GetNodeTitle(ENodeTitleType::Type TitleType) const{
	FFormatNamedArguments Args;
	Args.Add(TEXT("ControllerDescription"), GetControllerDescription());


	if (TitleType == ENodeTitleType::ListView)
	{
		return FText::Format(LOCTEXT("AnimGraphNode_weapon_Title", "{ControllerDescription}"), Args);
	}
	else
	{
		Args.Add(TEXT("BaseBoneName"), FText::FromName(node.base.BoneName));
		Args.Add(TEXT("ArmBoneName"), FText::FromName(node.arm.BoneName));
		return FText::Format(LOCTEXT("AnimGraphNode_weapon_Title", "{ControllerDescription}\nBase Bone: {BaseBoneName}\nArm Bone: {ArmBoneName}"), Args);
	}
}

FText UAnimGraphNode_weapon::GetTooltipText() const{
	return FText::FromString(TEXT("Add control to weapon."));
}

FString UAnimGraphNode_weapon::GetNodeCategory() const{
	return FString("Skeletal Controls");
}

FLinearColor UAnimGraphNode_weapon::GetNodeTitleColor() const{
	return FLinearColor(0.75f, 0.75f, 0.10f);
}

void UAnimGraphNode_weapon::CreateOutputPins() {
	const UAnimationGraphSchema* Schema = GetDefault<UAnimationGraphSchema>();
	CreatePin(EGPD_Output, Schema->PC_Struct, TEXT(""), FComponentSpacePoseLink::StaticStruct(), /*bIsArray=*/ false, /*bIsReference=*/ false, TEXT("Pose"));
}

FText UAnimGraphNode_weapon::GetControllerDescription() const{
	return LOCTEXT("weapon", "weapon_control");
}

#undef LOCTEXT_NAMESPACE
