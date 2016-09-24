// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimGraphNode_Base.h"
#include "AnimNode_weapon.h"
#include "AnimGraphNode_weapon.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI)
class UAnimGraphNode_weapon : public UAnimGraphNode_Base
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = SkeletalControl)
	FAnimNode_weapon node;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FString GetNodeCategory() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual void CreateOutputPins() override;
	// End of UEdGraphNode interface

protected:
	virtual FText GetControllerDescription() const;

};
