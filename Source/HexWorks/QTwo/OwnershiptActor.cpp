


#include "OwnershiptActor.h"


// Sets default values
AOwnershiptActor::AOwnershiptActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOwnershiptActor::BeginPlay()
{
	Super::BeginPlay();
	// Create a shared instance of B
	TSharedPtr<B> BSharedPTR = MakeShared<B>();
	// Create an instance of A, passing a weak pointer to B
	TSharedPtr<A> ASharedPTR = MakeShared<A>(BSharedPTR);
	// C also owns A (shared ownership)
	C c;
	c.SetA(ASharedPTR);
	// A accesses information from B
	ASharedPTR->AccessB(); //should output "Accessing B" and "Printing info from B"
	// destruction of B
	BSharedPTR.Reset();
	// Then A tries to access B again after B has been destroyed
	ASharedPTR->AccessB(); //so it outputs "B is no longer valid"
}

// Called every frame
void AOwnershiptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

