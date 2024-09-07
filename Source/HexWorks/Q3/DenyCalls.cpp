


#include "DenyCalls.h"


// Sets default values
ADenyCalls::ADenyCalls()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADenyCalls::BeginPlay()
{
	Super::BeginPlay();

	Stuff _stuff;

	int a= 42;
	int* Intptr = &a;
	_stuff.Look_At_PointerWithAssert(Intptr);//this work and will print "Looking At the pointer from static_assert"
	_stuff.Look_At_PointerWithEnableIf(Intptr);//this work and will print "Looking At the pointer from EnableIf"

	void *Voidptr = nullptr;
	
	//_stuff.Look_At_PointerWithAssert(Voidptr); //this will not compile and will give static_assert error message "You cannot pass void* to this function"
												//and also give error message "You cannot pass nullptr to this function"

	//_stuff.Look_At_PointerWithEnableIf(Voidptr); //this will not compile because of Substitution failure error in the template function
	
}

// Called every frame
void ADenyCalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

