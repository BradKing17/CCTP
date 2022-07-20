// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTypes.h"
#include "ProcQuestManager.h"
#include "QuestLog.h"
#include "Quest.h"
#include "QuestGiver.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCQUESTPLUGINV2_API UQuestGiver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestGiver();

	UPROPERTY(EditAnywhere, Category = "Ratings")
		int32 playerRating = 0;
	UPROPERTY(EditAnywhere, Category = "Quests")
		int32 minQuestDifficulty = 0;
	UPROPERTY(EditAnywhere, Category = "Quests")
		int32 maxQuestDifficulty = 15;
	UPROPERTY(EditAnywhere, Category = "Quests")
		UQuest* quest;

	UPROPERTY(EditAnywhere, Category = "Quests")
	bool canGiveQuest = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void GenerateQuest(UProcQuestManager* manager);

	UFUNCTION(BlueprintCallable)
		void GiveQuest(AActor* player);

	UFUNCTION(BlueprintCallable)
		void ChangeRating(int32 change);

	UFUNCTION(BlueprintCallable)
		int32 RetrieveRating();


};
