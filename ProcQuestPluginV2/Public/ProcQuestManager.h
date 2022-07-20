// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTypes.h"
#include "ProcQuestManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCQUESTPLUGINV2_API UProcQuestManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProcQuestManager();

	UPROPERTY(EditAnywhere, Category = "Entities")
		TArray<UClass*> enemies;

	UPROPERTY(EditAnywhere, Category = "Entities")
		TArray<UClass*> allies;

	UPROPERTY(EditAnywhere, Category = "Entities")
		TArray<UClass*> items;

	UPROPERTY(EditAnywhere, Category = "Entities")
		TArray<UClass*> keyItems;

	UPROPERTY(EditAnywhere, Category = "Entities")
		TArray<UClass*> exploreTriggers;

	UPROPERTY(EditAnywhere, Category = "Quest Givers")
		TArray<AActor*> activeQuestGivers;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UClass* ChooseTarget(OBJECTIVETYPES objType);

	void UpdateRating(int32 change, AActor* questGiver);
};
