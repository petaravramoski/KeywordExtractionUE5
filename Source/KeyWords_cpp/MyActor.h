#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


UCLASS()
class KEYWORDS_CPP_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

    TArray<FString> IdentifiedKeywords;

    FString SampleSentence = FString(TEXT("walk to the blue box i am also adding extra text so it's a longer input"));

    void IdentifyKeywords(FString SampleSentace);

public:
    // Declare the BlueprintCallable function with a valid return type
    virtual void Tick(float DeltaTime) override;

};