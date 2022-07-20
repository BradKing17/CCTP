// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestTypes.generated.h"

UENUM(BlueprintType)
enum OBJECTIVETYPES
{
	QT_Kill UMETA(DisplayName = "Kill"),
	QT_Fetch UMETA(DisplayName = "Fetch"),
	QT_Deliver UMETA(DisplayName = "Deliver"),
	QT_Explore UMETA(DisplayName = "Explore"),
	QT_Buy UMETA(DisplayName = "Buy"),
	QT_Escort UMETA(DisplayName = "Escort")
};




