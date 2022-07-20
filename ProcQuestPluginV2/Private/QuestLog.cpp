// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLog.h"

// Sets default values for this component's properties
UQuestLog::UQuestLog()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestLog::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestLog::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQuestLog::AddQuest(UQuest* questAdded)
{
	noOfQuests++;
	quests.Add(questAdded);
}

void UQuestLog::RemoveQuest(UQuest* questRemoved)
{
	noOfQuests--;
	quests.Remove(questRemoved);
}


UQuest* UQuestLog::GetQuest(int32 questIndex)
{
	return quests[questIndex];
}

TArray<UQuest*> UQuestLog::GetQuests()
{
	return quests;
}

void UQuestLog::UpdateQuests(UClass* target, int32 noOfTargets)
{
	
	for(int i = 0; i < quests.Num(); i++)
	{
		UQuest* curQuest = quests[i];

		if (!curQuest->isComplete)
		{
			if (!curQuest->isAbandoned)
			{
				if (curQuest->questInfo.target == target)
				{
					curQuest->UpdateQuest(noOfTargets);
				}
				if (curQuest->isComplete)
				{
					completedQuests.Add(curQuest);
				}
			}
		}


	}
}


