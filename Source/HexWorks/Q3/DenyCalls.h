#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DenyCalls.generated.h"

class Stuff
{
public:
	template <typename T>
	static void Look_At_PointerWithAssert(T* ptr)
	{
		static_assert(!std::is_same_v<T,void>, "You cannot pass void* to this function");
		
		if(!ptr)return;
		
		UE_LOG(LogTemp, Warning, TEXT("Looking At the pointer from static_assert"));
		
	}

	template <typename T, typename = std::enable_if_t<!std::is_same_v<T,void>>>
	static void Look_At_PointerWithEnableIf(T* ptr)
	{
		if (ptr == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("Pointer is nullptr"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Pointer is not nullptr"));
			UE_LOG(LogTemp, Warning, TEXT("Looking At the pointer from EnableIf"));
		}
	}
};


UCLASS()
class HEXWORKS_API ADenyCalls : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADenyCalls();
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
