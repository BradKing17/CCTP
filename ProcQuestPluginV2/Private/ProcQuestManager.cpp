// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcQuestManager.h"

// Sets default values for this component's properties
UProcQuestManager::UProcQuestManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProcQuestManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProcQuestManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UClass* UProcQuestManager::ChooseTarget(OBJECTIVETYPES objType)
{
	UPROPERTY()
	UClass* target = nullptr;
	switch (objType)
	{
	case OBJECTIVETYPES::QT_Kill:
		target = enemies[FMath::RandRange(0, enemies.Num()-1)];
			break;
	case OBJECTIVETYPES::QT_Fetch:
		target = items[FMath::RandRange(0, items.Num()-1)];
		break;
	case OBJECTIVETYPES::QT_Deliver:
		target = keyItems[FMath::RandRange(0, keyItems.Num()-1)];
		break;

	case OBJECTIVETYPES::QT_Explore:
		target = exploreTriggers[FMath::RandRange(0, exploreTriggers.Num()-1)];
		break;
	case OBJECTIVETYPES::QT_Buy:
		target = items[FMath::RandRange(0, items.Num()-1)];
		break;
	case OBJECTIVETYPES::QT_Escort:
		target = allies[FMath::RandRange(0, allies.Num()-1)];;
		break;
	}

	return target;
}

void UProcQuestManager::UpdateRating(int32 change, AActor* questGiver)
{
	AActor* curGiver = activeQuestGivers[activeQuestGivers.Find(questGiver)];
}

