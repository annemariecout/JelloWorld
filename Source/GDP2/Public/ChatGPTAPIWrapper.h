#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "UObject/Object.h"
#include "UObject/Script.h"
#include "ChatGPTAPIWrapper.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSuccessDelegate, const FString&, GeneratedText);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnErrorDelegate, int32, ResponseCode, const FString&, ErrorMessage);



UCLASS(Blueprintable)
class GDP2_API UChatGPTAPIWrapper : public UObject
{
	GENERATED_BODY()

public:
	UChatGPTAPIWrapper();

	template <typename Signature>
	class TFunction;

	UFUNCTION(BlueprintCallable, Category = "OpenAI")
	void SendRequest(const FString& Prompt, const FOnSuccessDelegate& OnSuccess, const FOnErrorDelegate& OnError);

	UFUNCTION(BlueprintCallable, Category = "OpenAI")
	void SetOpenAIAPIKey(const FString& APIKey);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
	int32 MaxTokens = 2048;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "OpenAI")
	float Temperature = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "OpenAI")
	float TopP = 0.2f;

private:
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnSuccessDelegate OnSuccess, FOnErrorDelegate OnError);

	UFUNCTION(BlueprintCallable, Category = "OpenAI")
	FString GetOpenAIAPIKey();

	FString OpenAIAPIKey;
    
};