// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineKeyValuePair.h"
#include "Event.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDataType : uint8
{
	None,
	Int,
	Float,
	String,
	Bool,
	Vector,
	Rotator,
	Transform,
	GUID
};
// Enum for different event types in the game
UENUM(BlueprintType)
enum class EEventType : uint8
{
	None,
	TakeDamage,
	OpenDoor,
	PlayerDeath,
	ItemPickedUp,
	CustomEvent
};
USTRUCT(BlueprintType)
struct FEventData
{
	GENERATED_BODY()

	//type of stored data
	
	
	//Constructors
	FEventData() : Type(EDataType::None) {}
	FEventData(int32 InValue) : Type(EDataType::Int), IntData(InValue) {}
	FEventData(float InValue) : Type(EDataType::Float), FloatData(InValue) {}
	FEventData(const FString& InValue) : Type(EDataType::String), StringData(InValue) {}
	FEventData(bool InValue) : Type(EDataType::Bool), BoolData(InValue) {}
	FEventData(const FVector& InValue) : Type(EDataType::Vector), VectorData(InValue) {}
	FEventData(const FRotator& InValue) : Type(EDataType::Rotator), RotatorData(InValue) {}
	FEventData(const FTransform& InValue) : Type(EDataType::Transform), TransformData(InValue) {}
	FEventData(const FGuid& InValue) : Type(EDataType::GUID), GUIDData(InValue.ToString()) {}

	//Getter Functions for safety and compile checks
	
	int32 GetInt() const { check(Type == EDataType::Int); return IntData; }
	float GetFloat() const { check(Type == EDataType::Float); return FloatData; }
	const FString& GetString() const { check(Type == EDataType::String); return StringData; }
	bool GetBool() const { check(Type == EDataType::Bool); return BoolData; }
	const FVector& GetVector() const { check(Type == EDataType::Vector); return VectorData; }
	const FRotator& GetRotator() const { check(Type == EDataType::Rotator); return RotatorData; }
	const FTransform& GetTransform() const { check(Type == EDataType::Transform); return TransformData; }
	const FGuid GetGUID() const { check(Type == EDataType::GUID); return GUIDData; }
	

	// Data members
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	EDataType Type;

	// Union-like storage for different types of data
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	int32 IntData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	float FloatData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	FString StringData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	bool BoolData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	FVector VectorData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	FRotator RotatorData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	FTransform TransformData;
	UPROPERTY(BlueprintReadWrite, Category = "Event Data")
	FGuid GUIDData;
	
	
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventTriggered, UEvent*, TriggeredEvent);

UCLASS(Blueprintable)
class HEXWORKS_API UEvent : public UObject
{
	GENERATED_BODY()

public:
	//event type
	// Constructor to initialize the event type
	UEvent() : EventType(EEventType::None) {}
	
	UFUNCTION(BlueprintCallable, Category = "Event")
	void SetEventType(EEventType NewEventType) { EventType = NewEventType; }

	// Get the event type
	UFUNCTION(BlueprintCallable, Category = "Event")
	EEventType GetEventType() const { return EventType; }
	UFUNCTION(BlueprintCallable, Category = "Event")
	void TriggerEvent(){ OnEventTriggered.Broadcast(this); }
	// Delegate for subscribing to the event
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnEventTriggered OnEventTriggered;
//--------------------------------------------------------------------------------------------
	//event data
	UFUNCTION(BlueprintCallable, Category = "Event")
	void AddData(const FString& Key,const FEventData& Value);

	UFUNCTION(BlueprintCallable, Category = "Event")
	bool GetData(const FString & Key, FEventData& RetValue) const;

	UFUNCTION(BlueprintCallable, Category = "Event")
	bool HasData(const FString & Key) const;
//--------------------------------------------------------------------------------------------
private:
	TMap<FString, FEventData> Data;
	// Store event type
	UPROPERTY(BlueprintReadWrite, Category = "Event", meta = (AllowPrivateAccess = "true"))
	EEventType EventType;
};
