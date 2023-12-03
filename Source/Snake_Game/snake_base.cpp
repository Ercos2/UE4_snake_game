// Fill out your copyright notice in the Description page of Project Settings.


#include "snake_base.h"
#include "snake_element_base.h"
#include "Interactable.h"

// Sets default values
Asnake_base::Asnake_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ElementSize = 100.f;
	MovementSpeed = 10.f;
	LastMoveDirection = EMovementDirection::DOWN;
}

// Called when the game starts or when spawned
void Asnake_base::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(MovementSpeed);
	AddSnakeElement(5);
}

// Called every frame
void Asnake_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void Asnake_base::AddSnakeElement(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; ++i) {
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		Asnake_element_base* NewSnakeElem = GetWorld()->SpawnActor<Asnake_element_base>(snake_element_class, NewTransform);
		NewSnakeElem->SnakeOwner = this;
		int32 ElemIndex = SnakeElements.Add(NewSnakeElem);
		if (ElemIndex == 0) {
			NewSnakeElem->SetFirstElemType();
			
		}
	}

}

void Asnake_base::Move()
{
	FVector MovementVector(FVector::ZeroVector);

	switch (LastMoveDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += ElementSize;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= ElementSize;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y += ElementSize;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= ElementSize;
		break;
	default:
		break;
	}

	SnakeElements[0]->ToggleCollision();

	for (int i = SnakeElements.Num() - 1; i > 0; --i) {
		auto CurrentElement = SnakeElements[i];
		auto PrevElement = SnakeElements[i - 1];
		FVector PrevLocation = PrevElement->GetActorLocation();
		CurrentElement->SetActorLocation(PrevLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleCollision();
}

void Asnake_base::SnakeElementOverlap(Asnake_element_base* OverlappedElement, AActor* Other)
{
	if (IsValid(OverlappedElement)) {
		int32 ElemIndex;
		SnakeElements.Find(OverlappedElement, ElemIndex);
		bool bIsFirst = ElemIndex == 0;
		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if (InteractableInterface) {
			InteractableInterface->Interact(this, bIsFirst);
			
		}
	}
}

