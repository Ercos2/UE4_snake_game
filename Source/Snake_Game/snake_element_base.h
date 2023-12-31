// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "snake_element_base.generated.h"


class UStaticMeshComponent;
class Asnake_base;

UCLASS()
class SNAKE_GAME_API Asnake_element_base : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Asnake_element_base();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY()
		Asnake_base* SnakeOwner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
		void SetFirstElemType();
	void SetFirstElemType_Implementation();

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	UFUNCTION()
		void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void ToggleCollision();
};
