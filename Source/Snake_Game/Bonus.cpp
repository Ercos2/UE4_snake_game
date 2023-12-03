// Fill out your copyright notice in the Description page of Project Settings.


#include "Bonus.h"
#include "snake_base.h"
#include "Food.h"

// Sets default values
ABonus::ABonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonus::Interact(AActor* Interactor, bool bIsHead)
{
	auto* snake = Cast<Asnake_base>(Interactor);
	snake->ElementSize *= 1.1;
	
	FVector NewLocation;
	srand(time(0));

	int32 spawn_start = -401;
	int32 spawn_end = 401;
	NewLocation.X = rand() % (spawn_end - spawn_start + 1) + spawn_start;
	NewLocation.Y = rand() % (spawn_end - spawn_start + 1) + spawn_start;

	this->SetActorLocation(NewLocation);
}

