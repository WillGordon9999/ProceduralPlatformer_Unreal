// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintServices.h"
//#include "Public/ObjectVars.h"

bool ABlueprintServices::initState = false;
TMap<AActor*, FObjectVars> ABlueprintServices::states = TMap<AActor*, FObjectVars>();

// Sets default values
ABlueprintServices::ABlueprintServices()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABlueprintServices::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ABlueprintServices::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

UObject* ABlueprintServices::GetObject(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)	
		state = &states.Add(object, FObjectVars());
	
	UObject** ptr = state->objects.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid UObject Variable in GetObject"));
	return nullptr;
}

bool ABlueprintServices::GetBool(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	bool* ptr = state->booleans.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Bool Variable in GetBool"));
	return false;
}

int ABlueprintServices::GetInt(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	int* ptr = state->integers.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Int Variable in GetInt"));
	return 0;
}

double ABlueprintServices::GetFloat(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	double* ptr = state->floats.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Float Variable in GetFloat"));
	return 0.0;
}

FString ABlueprintServices::GetString(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FString* ptr = state->strings.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid String Variable in GetString"));
	return FString("");
}

FVector ABlueprintServices::GetVector(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FVector* ptr = state->vectors.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Vector Variable in GetVariable"));
	return FVector();
}

FRotator ABlueprintServices::Get_Rotator(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FRotator* ptr = state->rotators.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Rotator Variable in GetTransform"));
	return FRotator();
}

FTransform ABlueprintServices::Get_Transform(AActor* object, FString name)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FTransform* ptr = state->transforms.Find(name);

	if (ptr != nullptr)
		return *ptr;

	GLog->Log(TEXT("Invalid Transform Variable in GetTransform"));
	return FTransform();
}

// ========== SETTERS ==============


UObject* ABlueprintServices::SetObject(AActor* object, FString name, UObject* value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	UObject** ptr = state->objects.Find(name);

	if (ptr != nullptr)
	{
		state->objects[name] = value;
		return state->objects[name];
	}

	else
	{
		state->objects.Add(name, value);
		return value;
	}

	return nullptr;
}

bool ABlueprintServices::SetBool(AActor* object, FString name, bool value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	bool* ptr = state->booleans.Find(name);

	if (ptr != nullptr)
	{
		state->booleans[name] = value;
		return state->booleans[name];
	}

	else
	{
		state->booleans.Add(name, value);
		return state->booleans[name];
	}

	//return false;
}

int ABlueprintServices::SetInt(AActor* object, FString name, int value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	int* ptr = state->integers.Find(name);

	if (ptr != nullptr)
	{
		state->integers[name] = value;
		return state->integers[name];
	}

	else
	{
		state->integers.Add(name, value);
		return state->integers[name];
	}
}

double ABlueprintServices::SetFloat(AActor* object, FString name, double value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	double* ptr = state->floats.Find(name);

	if (ptr != nullptr)
	{
		state->floats[name] = value;
		return state->floats[name];
	}

	else
	{
		state->floats.Add(name, value);
		return state->floats[name];
	}	
}

FString ABlueprintServices::SetString(AActor* object, FString name, FString value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FString* ptr = state->strings.Find(name);

	if (ptr != nullptr)
	{
		state->strings[name] = value;
		return state->strings[name];
	}

	else
	{
		state->strings.Add(name, value);
		return state->strings[name];
	}	
}

FVector ABlueprintServices::SetVector(AActor* object, FString name, FVector value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FVector* ptr = state->vectors.Find(name);

	if (ptr != nullptr)
	{
		state->vectors[name] = value;
		return state->vectors[name];
	}

	else
	{
		state->vectors.Add(name, value);
		return state->vectors[name];
	}	
}

FRotator ABlueprintServices::SetRotator(AActor* object, FString name, FRotator value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FRotator* ptr = state->rotators.Find(name);

	if (ptr != nullptr)
	{
		state->rotators[name] = value;
		return state->rotators[name];
	}

	else
	{
		state->rotators.Add(name, value);
		return state->rotators[name];
	}
}

FTransform ABlueprintServices::SetTransform(AActor* object, FString name, FTransform value)
{
	if (!initState)
	{
		states = TMap<AActor*, FObjectVars>();
		initState = true;
	}

	FObjectVars* state = states.Find(object);

	if (state == nullptr)
		state = &states.Add(object, FObjectVars());

	FTransform* ptr = state->transforms.Find(name);

	if (ptr != nullptr)
	{
		state->transforms[name] = value;
		return state->transforms[name];		
	}

	else
	{
		state->transforms.Add(name, value);
		return state->transforms[name];
	}
}
