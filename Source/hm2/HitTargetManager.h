// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitTargetManager.generated.h"

UCLASS()
class HM2_API AHitTargetManager : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<AActor*> HitTargets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 SpecialTargetCount;
	
public:	
	// Sets default values for this actor's properties
	AHitTargetManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Boost();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
