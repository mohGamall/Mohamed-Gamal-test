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
	EventCPP = NewObject<UEvent>();
	EventCPP->SetEventType(EEventType::TakeDamage);
	
	EventCPP->AddData(TEXT("Damage"), FEventData(10));
	EventCPP->AddData(TEXT("DamageDealerName"), FEventData(FString("Jim")));
	EventCPP->AddData(TEXT("DamageDealerID"), FEventData(FGuid::NewGuid()));
	EventCPP->AddData(TEXT("Position"), FEventData(FVector(1, 2, 3)));
	EventCPP->AddData(TEXT("Rotation"), FEventData(FRotator(0, 90, 0)));
	EventCPP->AddData(TEXT("Transform"), FEventData(FTransform(FRotator(0, 90, 0), FVector(1, 2, 3), FVector(1, 1, 1))));
	EventCPP->AddData(TEXT("IsAlive"), FEventData(true));
	EventCPP->AddData(TEXT("PlayerID"), FEventData(FGuid::NewGuid()));


	//now we can get all data and print it

	//print event type
	UE_LOG(LogTemp, Warning, TEXT("Event Type: %d"), (uint8)EventCPP->GetEventType());
	
	FEventData Health;
	if (EventCPP->GetData(TEXT("Damage"), Health))
	{
		UE_LOG(LogTemp, Warning, TEXT("Damage: %d"), Health.GetInt());
	}
	FEventData Name;
	if(EventCPP->GetData("DamageDealerName", Name))
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageDealerName: %s"), *Name.GetString());
	}
	FEventData DealerID;
	if (EventCPP->GetData("DamageDealerID", DealerID))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerID: %s"), *DealerID.GetGUID().ToString());
	}
	FEventData Position;
	if (EventCPP->GetData("Position", Position))
	{
		UE_LOG(LogTemp, Warning, TEXT("Position: %s"), *Position.GetVector().ToString());
	}
	FEventData Rotation;
	if (EventCPP->GetData("Rotation", Rotation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *Rotation.GetRotator().ToString());
	}
	FEventData Transform;
	if (EventCPP->GetData("Transform", Transform))
	{
		UE_LOG(LogTemp, Warning, TEXT("Transform: %s"), *Transform.GetTransform().ToString());
	}
	FEventData IsAlive;
	if (EventCPP->GetData("IsAlive", IsAlive))
	{
		UE_LOG(LogTemp, Warning, TEXT("IsAlive: %s"), IsAlive.GetBool() ? TEXT("True") : TEXT("False"));
	}
	FEventData PlayerID;
	if (EventCPP->GetData("PlayerID", PlayerID))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerID: %s"), *PlayerID.GetGUID().ToString());
	}

	
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

