// Fill out your copyright notice in the Description page of Project Settings.


#include "snake_element_base.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "snake_base.h"

// Sets default values
Asnake_element_base::Asnake_element_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
}

// Called when the game starts or when spawned
void Asnake_element_base::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void Asnake_element_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Asnake_element_base::SetFirstElemType_Implementation()
{
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &Asnake_element_base::HandleBeginOverlap);
}

void Asnake_element_base::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<Asnake_base>(Interactor);
	if (IsValid(Snake)) {
		Snake->Destroy();
	}
}

void Asnake_element_base::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(SnakeOwner)) {
		SnakeOwner->SnakeElementOverlap(this, OtherActor);
	}
}

void Asnake_element_base::ToggleCollision()
{
	if (MeshComponent->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
		MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	else
		MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

