// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreOnHitComponent.h"
#include "hm2PlayerController.h"

UScoreOnHitComponent::UScoreOnHitComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // No need to tick
}

void UScoreOnHitComponent::BeginPlay()
{
    Super::BeginPlay();
    // Get the owning actor's collision component
    AActor* Owner = GetOwner();
    if (Owner)
    {
        CollisionComponent = Owner->FindComponentByClass<UPrimitiveComponent>();
        if (CollisionComponent)
        {
            // Bind to the OnComponentHit event
            CollisionComponent->OnComponentHit.AddDynamic(this, &UScoreOnHitComponent::OnHit);
        }
    }
}

void UScoreOnHitComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor)
    {

        Ahm2PlayerController* PlayerController = Cast<Ahm2PlayerController>(OtherActor->GetInstigatorController());
        if (PlayerController)
        {
            // Award points to the player
            PlayerController->OnTargetHit(GetOwner(), PointsAwarded);

            // Optionally destroy the actor after scoring
            GetOwner()->Destroy();
        }
    }
}

