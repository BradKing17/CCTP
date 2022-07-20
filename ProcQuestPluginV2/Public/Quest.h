// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTypes.h"
#include "ProcQuestManager.h"
#include "Quest.generated.h"


USTRUCT(BlueprintType)
struct FQuestInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		AActor* questGiver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		TEnumAsByte<OBJECTIVETYPES> curObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		int32 questDifficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		FString questName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		int32 noOfStages = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		UClass* target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		int32 noOfTargets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		int32 rewardGold;
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCQUESTPLUGINV2_API UQuest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuest();

	UPROPERTY(EditAnywhere, Category = "Quests")
		FQuestInfo questInfo;

	UPROPERTY(EditAnywhere, Category = "Quests")
		UProcQuestManager* questManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		bool isComplete = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		bool isAbandoned = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		int32 curTargetCount = 0;

		int32 curStage = 1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetQuestInfo(int32 minDifficulty, int32 maxDifficulty, AActor* questGiver, UProcQuestManager* manager);

	UFUNCTION(BlueprintCallable)
	FQuestInfo RetrieveCurrentInfo();

	void UpdateQuest(int32 input);	

	void AbandonQuest();
	//Debug	
	UFUNCTION(BlueprintCallable)
	void CompleteQuest();
};


