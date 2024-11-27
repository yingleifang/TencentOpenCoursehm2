// Fill out your copyright notice in the Description page of Project Settings.


#include "HitTargetManager.h"
#include "ScoreOnHitComponent.h"
#include <Kismet/GameplayStatics.h>

AHitTargetManager::AHitTargetManager()
{
}

// Called when the game starts or when spawned
void AHitTargetManager::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsWithTag(this->GetWorld(), "HitTarget", HitTargets);
	Boost();
}

void AHitTargetManager::Boost()
{
	for (int i = HitTargets.Num() - 1; i >= 0; i--)
	{
		int32 index = FMath::RandRange(0, i);
		HitTargets.Swap(i, index);
	}

	for (int i = 0; i < std::min(SpecialTargetCount, HitTargets.Num()); i++)
	{
		HitTargets[i]->FindComponentByClass<UScoreOnHitComponent>()->PointsAwarded *= 2;
		UMeshComponent* MeshComponent = HitTargets[i]->FindComponentByClass<UMeshComponent>();
		UMaterialInstanceDynamic* DynamicMaterial = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
		if (DynamicMaterial != nullptr)
		{
			DynamicMaterial->SetVectorParameterValue("Base Color", FLinearColor::Red);
		}
	}
}

// Called every frame
void AHitTargetManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

