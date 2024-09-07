#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Q4FunctionRouter.generated.h"

class some_type {};

UCLASS()
class HEXWORKS_API AQ4FunctionRouter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQ4FunctionRouter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void func(const some_type &Param){ UE_LOG(LogTemp, Warning, TEXT("called Lvalue ref version")) }
	void func( some_type &&Param){ UE_LOG(LogTemp, Warning, TEXT("called Rvalue ref version")) }

	//the universal forwarding function
	template<typename T>
	void ForwardingFunction(T &&Param)
	{
		func(Forward<T>(Param));
	}
};
