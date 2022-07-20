// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quest.h"
#include "QuestLog.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCQUESTPLUGINV2_API UQuestLog : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestLog();

	UPROPERTY(EditAnywhere, Category = "Quests")
		int32 noOfQuests;

	UPROPERTY(EditAnywhere, Category = "Quests")
		TArray<UQuest*> quests;

	UPROPERTY(EditAnywhere, Category = "Quests")
		TArray<UQuest*> completedQuests;
	UPROPERTY(EditAnywhere, Category = "Quests")
		TArray<UQuest*> abandonedQuests;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddQuest(UQuest* questAdded);

	void RemoveQuest(UQuest* questRemoved);

	UFUNCTION(BlueprintCallable)
	UQuest* GetQuest(int32 questIndex);

	UFUNCTION(BlueprintCallable)
	TArray<UQuest*> GetQuests();

	UFUNCTION(BlueprintCallable)
	void UpdateQuests(UClass* target, int32 noOfTargets);
};
