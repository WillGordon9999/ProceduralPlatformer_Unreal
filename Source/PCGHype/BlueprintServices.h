// Fill out your copyright notice in the Description page of Project Settings.
//CTRL+ALT+F11 To RECOMPILE
#pragma once
//#include "Public/ObjectState.h"
#include "Public/ObjectVars.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlueprintServices.generated.h"

UCLASS()
class PCGHYPE_API ABlueprintServices : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlueprintServices();
	//static ABlueprintServices* instance;	
	static TMap<AActor*, FObjectVars> states;
	static bool initState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Object"))
	static UObject* GetObject(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Bool"))
	static bool GetBool(AActor* object, FString name);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Int"))
	static int GetInt(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Float"))
	static double GetFloat(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String"))
	static FString GetString(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Vector"))
	static FVector GetVector(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Transform"))
	static FTransform Get_Transform(AActor* object, FString name);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DislayName = "Get Rotator"))
	static FRotator Get_Rotator(AActor* object, FString name);

	//Setters

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Object"))
	static UObject* SetObject(AActor* object, FString name, UObject* value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Bool"))
	static bool SetBool(AActor* object, FString name, bool value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Int"))
	static int SetInt(AActor* object, FString name, int value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Float"))
	static double SetFloat(AActor* object, FString name, double value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set String"))
	static FString SetString(AActor* object, FString name, FString value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Vector"))
	static FVector SetVector(AActor* object, FString name, FVector value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Transform"))
	static FTransform SetTransform(AActor* object, FString name, FTransform value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set Rotator"))
	static FRotator SetRotator(AActor* object, FString name, FRotator value);

};
