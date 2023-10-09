// Copyright Epic Games, Inc. All Rights Reserved.

#include "KeyWords_cppGameMode.h"
#include "KeyWords_cppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKeyWords_cppGameMode::AKeyWords_cppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
