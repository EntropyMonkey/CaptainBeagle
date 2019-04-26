// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CaptainBeagleGameMode.h"
#include "CaptainBeagleCharacter.h"

ACaptainBeagleGameMode::ACaptainBeagleGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACaptainBeagleCharacter::StaticClass();	
}
