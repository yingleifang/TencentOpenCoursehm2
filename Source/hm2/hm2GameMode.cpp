// Copyright Epic Games, Inc. All Rights Reserved.

#include "hm2GameMode.h"
#include "hm2Character.h"
#include "UObject/ConstructorHelpers.h"

Ahm2GameMode::Ahm2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
