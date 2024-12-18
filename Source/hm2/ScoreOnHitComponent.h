// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreOnHitComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HM2_API UScoreOnHitComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreOnHitComponent();

    // Points awarded for hitting this object
    UPROPERTY(EditAnywhere, Category = "Score")
    int32 PointsAwarded = 10;

protected:
    bool IsHit = false;

    UPROPERTY(EditAnywhere, Category = "Score")
    float ScalingFactor = 0.5;

	// Called when the game starts
	virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

    // Reference to the owning actor's collision component
    UPrimitiveComponent* CollisionComponent = nullptr;
};
