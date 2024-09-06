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
USTRUCT(BlueprintType)
struct FEventData
{
	GENERATED_BODY()

	//type of stored data
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
	//Constructors
	FEventData() : Type(EDataType::None) {}
	FEventData(int32 InValue) : Type(EDataType::Int), IntData(InValue) {}
	FEventData(float InValue) : Type(EDataType::Float), FloatData(InValue) {}
	FEventData(const FString& InValue) : Type(EDataType::String), StringData(InValue) {}
	FEventData(bool InValue) : Type(EDataType::Bool), IntData(InValue) {}
	FEventData(const FVector& InValue) : Type(EDataType::Vector), VectorData(InValue) {}
	FEventData(const FRotator& InValue) : Type(EDataType::Rotator), RotatorData(InValue) {}
	FEventData(const FTransform& InValue) : Type(EDataType::Transform), TransformData(InValue) {}
	FEventData(const FGuid& InValue) : Type(EDataType::GUID), StringData(InValue.ToString()) {}

	//Getter Functions
	int32 GetInt() const { check(Type == EDataType::Int); return IntData; }
	float GetFloat() const { check(Type == EDataType::Float); return FloatData; }
	const FString& GetString() const { check(Type == EDataType::String); return StringData; }
	bool GetBool() const { check(Type == EDataType::Bool); return BoolData; }
	const FVector& GetVector() const { check(Type == EDataType::Vector); return VectorData; }
	const FRotator& GetRotator() const { check(Type == EDataType::Rotator); return RotatorData; }
	const FTransform& GetTransform() const { check(Type == EDataType::Transform); return TransformData; }
	FGuid GetGUID() const { check(Type == EDataType::GUID); return GUIDData; }
	

	// Data members
	EDataType Type;

	// Union-like storage for different types of data
	int32 IntData;
	float FloatData;
	FString StringData;
	bool BoolData;
	FVector VectorData;
	FRotator RotatorData;
	FTransform TransformData;
	FGuid GUIDData;
	
};



UCLASS(Blueprintable)
class HEXWORKS_API UEvent : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Event")
	void AddData(const FString& Key,const FEventData& Value);

	UFUNCTION(BlueprintCallable, Category = "Event")
	bool GetData(const FString & Key, FEventData& RetValue) const;

	UFUNCTION(BlueprintCallable, Category = "Event")
	bool HasData(const FString & Key) const;

private:
	TMap<FString, FEventData> Data;
};
