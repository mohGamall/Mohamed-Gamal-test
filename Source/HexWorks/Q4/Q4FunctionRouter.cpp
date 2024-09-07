


#include "Q4FunctionRouter.h"


// Sets default values
AQ4FunctionRouter::AQ4FunctionRouter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQ4FunctionRouter::BeginPlay()
{
	Super::BeginPlay();
	some_type Obj;
	ForwardingFunction(Obj);// this will call the Lvalue ref version
	ForwardingFunction(some_type()); // this will call the Rvalue ref version
	
}

// Called every frame
void AQ4FunctionRouter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

