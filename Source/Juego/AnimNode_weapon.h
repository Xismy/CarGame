#pragma once

#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "weapon.h"
#include "AnimNode_weapon.generated.h"

/**
 * 
 */
USTRUCT()
struct JUEGO_API FAnimNode_weapon : public FAnimNode_Base {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links)
	FComponentSpacePoseLink ComponentPose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkeletalControl)
	FBoneReference base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkeletalControl)
	FBoneReference arm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (AlwaysAsPin))
	float pitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (AlwaysAsPin))
	float yaw;

	//Interface
	virtual void Initialize(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones(const FAnimationCacheBonesContext & Context) override;
	virtual void Update(const FAnimationUpdateContext & Context) override;
	virtual void EvaluateComponentSpace(FComponentSpacePoseContext & Output) override;
	
	//Constructor
	FAnimNode_weapon();
};