#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OwnershiptActor.generated.h"

class B
{
public:
	static void PrintInfoFromB()
	{
		UE_LOG(LogTemp, Warning, TEXT("Printing Info from B"));
	}
};

class A
{
public:
	A(TWeakPtr<B> InB) : BWeakPtr(InB) {}

	void AccessB() const
	{
		//lock the weak pointer to access the object if it is still valid
		if (TSharedPtr<B> BSharedPtr = BWeakPtr.Pin())
		{
			//access the object
			UE_LOG(LogTemp, Warning, TEXT("Accessing B"));
			BSharedPtr->PrintInfoFromB();
		} 
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("B is no longer valid"));
		}
	}


private:
	TWeakPtr<B> BWeakPtr;
	
};


class C
{
public:
	// C holds a shared pointer to A, sharing ownership with B
	void SetA(TSharedPtr<A> InA )
	{
		APtr = InA;
	}
private:
	TSharedPtr<A> APtr;
};

UCLASS()
class HEXWORKS_API AOwnershiptActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOwnershiptActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
