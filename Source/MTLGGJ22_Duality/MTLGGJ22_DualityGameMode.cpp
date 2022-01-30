// Copyright Epic Games, Inc. All Rights Reserved.

#include "MTLGGJ22_DualityGameMode.h"
#include "MTLGGJ22_DualityCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMTLGGJ22_DualityGameMode::AMTLGGJ22_DualityGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Karlyel_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
