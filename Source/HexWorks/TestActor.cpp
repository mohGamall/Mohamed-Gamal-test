// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "QuestionOne/Event.h"


// Sets default values
ATestActor::ATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	UEvent* Event = NewObject<UEvent>();
	Event->AddData(TEXT("Health"), FEventData(10));
	Event->AddData(TEXT("Name"), FEventData(FString("Jim")));
	Event->AddData(TEXT("Position"), FEventData(FVector(1, 2, 3)));
	Event->AddData(TEXT("Rotation"), FEventData(FRotator(0, 90, 0)));
	Event->AddData(TEXT("Transform"), FEventData(FTransform(FRotator(0, 90, 0), FVector(1, 2, 3), FVector(1, 1, 1))));
	Event->AddData(TEXT("IsAlive"), FEventData(true));
	
	FGuid NewID = FGuid::NewGuid();
	UE_LOG(LogTemp, Warning, TEXT("PlayerID: %s"), *NewID.ToString());
	Event->AddData(TEXT("PlayerID"), FEventData(NewID));


	//now we can get all data and print it
	FEventData Health;
	if (Event->GetData(TEXT("Health"), Health))
	{
		UE_LOG(LogTemp, Warning, TEXT("Health: %d"), Health.GetInt());
	}
	FEventData Name;
	if(Event->GetData("Name", Name))
	{
		UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *Name.GetString());
	}
	FEventData Position;
	if (Event->GetData("Position", Position))
	{
		UE_LOG(LogTemp, Warning, TEXT("Position: %s"), *Position.GetVector().ToString());
	}
	FEventData Rotation;
	if (Event->GetData("Rotation", Rotation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *Rotation.GetRotator().ToString());
	}
	FEventData Transform;
	if (Event->GetData("Transform", Transform))
	{
		UE_LOG(LogTemp, Warning, TEXT("Transform: %s"), *Transform.GetTransform().ToString());
	}
	FEventData IsAlive;
	if (Event->GetData("IsAlive", IsAlive))
	{
		UE_LOG(LogTemp, Warning, TEXT("IsAlive: %s"), IsAlive.GetBool() ? TEXT("True") : TEXT("False"));
	}
	FEventData PlayerID;
	if (Event->GetData("PlayerID", PlayerID))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerID: %s"), *PlayerID.GetGUID().ToString());
	}

	
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

