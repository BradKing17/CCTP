#include "Quest.h"


// Sets default values for this component's properties
UQuest::UQuest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UQuest::BeginPlay()
{
	Super::BeginPlay();
}

void UQuest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UQuest::SetQuestInfo(int32 minDifficulty, int32 maxDifficulty, AActor* questGiver, UProcQuestManager* manager)
{	
	questInfo.curObjective = OBJECTIVETYPES(FMath::RandRange(0, (int)OBJECTIVETYPES::QT_Escort));


	questManager = manager;
	questInfo.target = questManager->ChooseTarget(questInfo.curObjective);
	questInfo.questDifficulty = FMath::RandRange(minDifficulty, maxDifficulty);
	questInfo.noOfStages = 1;
	questInfo.noOfTargets = FMath::RandRange((int)minDifficulty, (int)maxDifficulty/2);
	questInfo.questGiver = questGiver;
	questInfo.rewardGold = FMath::RandRange((int)minDifficulty * 10, (int)maxDifficulty * 10);

	questInfo.questName = questGiver->GetFName().ToString() + "'s Request";
	const TCHAR* questName = *questInfo.questName;
	this->Rename(questName);

	questManager->activeQuestGivers.Add(questInfo.questGiver);
}

FQuestInfo UQuest::RetrieveCurrentInfo()
{
	return questInfo;
}

void UQuest::UpdateQuest(int32 input)
{

	switch (questInfo.curObjective)
	{
	case OBJECTIVETYPES::QT_Kill:
		curTargetCount += input;
		break;
	case OBJECTIVETYPES::QT_Fetch:
		curTargetCount += input;
		break;
	case OBJECTIVETYPES::QT_Deliver:
		switch (input)
		{
		case 0:
			//NPC has reached area
			CompleteQuest();
			break;
		case 1:
			//NPC has died
			AbandonQuest();
			break;
		}
		break;

	case OBJECTIVETYPES::QT_Explore:
		curTargetCount += input;
		break;
	case OBJECTIVETYPES::QT_Buy:
		curTargetCount += input;
		break;
	case OBJECTIVETYPES::QT_Escort:
		switch (input)
		{
		case 0:
			//NPC has reached area
			curStage++;
			break;
		case 1:
			//NPC has died
			AbandonQuest();
			break;
		}
		break;
	}
	
	if (curTargetCount >= questInfo.noOfTargets)
	{
		if (curStage < questInfo.noOfStages)
		{
			curStage++;
			questInfo.curObjective = OBJECTIVETYPES(FMath::RandRange(0, (int)OBJECTIVETYPES::QT_Escort));
			questInfo.target = questManager->ChooseTarget(questInfo.curObjective);
		}
		else
		{
			CompleteQuest();
		}
	}

}

void UQuest::AbandonQuest()
{
	questManager->activeQuestGivers.Remove(questInfo.questGiver);

	isAbandoned = true;
}

void UQuest::CompleteQuest()
{
	questManager->UpdateRating(10, questInfo.questGiver);
	questManager->activeQuestGivers.Remove(questInfo.questGiver);
	isComplete = true;
}
