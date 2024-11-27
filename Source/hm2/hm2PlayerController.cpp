// Copyright Epic Games, Inc. All Rights Reserved.


#include "hm2PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void Ahm2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	// Initialize score
	PlayerScore = 0;
}

// Called when the player hits a target
void Ahm2PlayerController::OnTargetHit(AActor* HitTarget, int32 PointsAwarded)
{
	// Add points to the player's score
	PlayerScore += PointsAwarded;

	// Log the updated score
	FString ScoreMessage = FString::Printf(TEXT("Current Score: %d"), PlayerScore);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, ScoreMessage);

	// Optionally destroy the target
	if (HitTarget)
	{
		HitTarget->Destroy();
	}
}