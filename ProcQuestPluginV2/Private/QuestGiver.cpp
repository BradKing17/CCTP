// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGiver.h"

// Sets default values for this component's properties
UQuestGiver::UQuestGiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestGiver::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestGiver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsValid(quest))
	{
		if (quest->isComplete)
		{
			canGiveQuest = true;
			
		}
	}

	// ...
}

void UQuestGiver::GenerateQuest(UProcQuestManager* manager)
{
	if (canGiveQuest)
	{
		quest = NewObject<UQuest>(this, "Quest");
		quest->SetQuestInfo(minQuestDifficulty, maxQuestDifficulty, this->GetOwner(), manager);
	}
}

void UQuestGiver::GiveQuest(AActor* player)
{
	if (canGiveQuest)
	{
		UQuestLog* playerLog = player->FindComponentByClass<UQuestLog>();

		if (playerLog != nullptr)
		{
			playerLog->AddQuest(quest);
		}
		canGiveQuest = false;
	}
}

void UQuestGiver::ChangeRating(int32 change)
{
	playerRating += change;
}

int32 UQuestGiver::RetrieveRating()
{
	return playerRating;
}



