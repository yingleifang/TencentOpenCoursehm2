// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "hm2PlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class HM2_API Ahm2PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 PlayerScore;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void OnTargetHit(AActor* HitTarget, int32 PointsAwarded);
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

	// End Actor interface
};
