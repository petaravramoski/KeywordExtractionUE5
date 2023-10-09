#include "MyActor.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Implement the IdentifyKeywords function
void AMyActor::IdentifyKeywords(FString Sentence)
{
    //Predefined action-related keywords
    TArray<FString> ActionKeywords = { TEXT("walk"), TEXT("run"), TEXT("blue"), TEXT("box") };

    //Tokenize the sentence into words
    TArray<FString> Tokens;
    Sentence.ParseIntoArray(Tokens, TEXT(" "), true);

    //Identify keywords
    IdentifiedKeywords.Empty(); // Clear the array before adding new keywords
    for (const FString& Token : Tokens) {
        if (ActionKeywords.Contains(Token)) {
            IdentifiedKeywords.Add(Token);
        }
    }
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    //Call the IdentifyKeywords function with the sample sentence
    IdentifyKeywords(SampleSentence);

    //Construct a string containing the identified keywords
    FString KeywordsString = FString(TEXT("Identified Keywords:\n"));
    for (const FString& Keyword : IdentifiedKeywords) {
        KeywordsString += Keyword + FString(TEXT("\n"));
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, KeywordsString);
    }
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

