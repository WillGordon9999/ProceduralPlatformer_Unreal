// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectVars.generated.h"

/**
 * 
 */
UCLASS()
class PCGHYPE_API UObjectVars1 : public UObject
{
	GENERATED_BODY()

public:
	TMap<FString, bool> booleans;
	TMap<FString, int> integers;
	TMap<FString, double> floats;
	TMap<FString, FString> strings;
	TMap<FString, FVector> vectors;
	TMap<FString, FTransform> transforms;
	TMap<FString, UObject*> objects;	
};


USTRUCT(BlueprintType) struct FObjectVars
{
	GENERATED_BODY()

	FObjectVars();
	~FObjectVars();

	TMap<FString, bool> booleans;
	TMap<FString, int> integers;
	TMap<FString, double> floats;
	TMap<FString, FString> strings;
	TMap<FString, FVector> vectors;
	TMap<FString, FTransform> transforms;
	TMap<FString, FRotator> rotators;
	TMap<FString, UObject*> objects;
};