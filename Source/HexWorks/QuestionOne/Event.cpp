// Fill out your copyright notice in the Description page of Project Settings.


#include "Event.h"

void UEvent::AddData(const FString& Key, const FEventData& Value)
{
	Data.Add(Key, Value);	
}

bool UEvent::GetData(const FString& Key, FEventData& RetValue) const
{
	if (const FEventData* FoundValue = Data.Find(Key))
	{
		RetValue = *FoundValue;
		return true;
	}
	return false;
}


bool  UEvent::HasData(const FString& Key) const
{
	return Data.Contains(Key);
}
