// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "snake_base.generated.h"

class Asnake_element_base;

UENUM()
enum class EMovementDirection {
	UP, DOWN, LEFT, RIGHT
};

UCLASS()
class SNAKE_GAME_API Asnake_base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Asnake_base();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<Asnake_element_base> snake_element_class;

	UPROPERTY(EditDefaultsOnly)
		float ElementSize;

	UPROPERTY(EditDefaultsOnly)
		float MovementSpeed;

	UPROPERTY()
		TArray<Asnake_element_base*> SnakeElements;

	UPROPERTY()
		EMovementDirection LastMoveDirection;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void AddSnakeElement(int ElementsNum = 1);
	UFUNCTION(BlueprintCallable)
		void Move();
	UFUNCTION()
		void SnakeElementOverlap(Asnake_element_base* OverlappedElement, AActor* Other);

};
