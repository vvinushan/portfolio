// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "IOnlineSubsystemEOS.h"
#include "Interfaces/OnlineStatsInterface.h"
#include "Interfaces/OnlineLeaderboardInterface.h"
#include "SOWGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SYMPHONYOFWAR_API USOWGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	/*struct {
		int32 PlayerRank;
		FString PlayerName;
		int32 PlayerScore;
	} LeaderboardEntry;*/


	// Total time in level (to be used for leaderboard stats)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	int TotalTimeTaken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EOS)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EOS)
	FString Token;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EOS)
	bool IsLoggedIn = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EOS)
	int32 RetrievedStat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EOS)
	TArray<int32> LeaderboardPlayerRank;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EOS)
	TArray<FString> LeaderboardPlayerName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EOS)
	TArray<int32> LeaderboardPlayerScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EOS)
	int LeaderboardEntry;

	//FOnlineLeaderboardReadRef LeaderboardReadRef;

	/*FOnlineAccountCredentials AccountPortalLogin;

	FOnlineAccountCredentials DeveloperLogin;

	FOnlineAccountCredentials ExchangeCodeLogin;*/

	// General login
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSLogin();

	// Developer login (future development)
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSLoginDeveloper();

	// Launching through Epic Games Launcher (future development)
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSLoginExchangeCode();

	// Read Full Leaderboard
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSReadLeaderboard(FString LeaderboardId);

	// Read Friend Leaderboard
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSReadFriendLeaderboard(FString LeaderboardId);

	// Read Player Leaderboard
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSReadPlayerLeaderboard(FString LeaderboardId);

	// Update Leaderboard (stats)
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSUpdateStat(FString Stat, int32 Value);

	// Receive stat from EOS
	UFUNCTION(BlueprintCallable, Category = EOS)
	void EOSRetrieveStat(TArray<FString> Stats);

	void SetRetrievedStat(int32 Stat);

	void UpdateLeaderboardEntry(TArray<int32> PlayerRank, TArray<FString> PlayerName, TArray<int32> PlayerScore);

	// Login complete (OnLoginComplete delegate callback)
	void EOSAddOnLoginCompleteDelegate(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	// Leaderboard read complete (OnLeaderboardReadComplete delegate callback)
	void EOSAddOnLeaderboardReadCompleteDelegate(bool bWasSuccessful, FOnlineLeaderboardReadRef InLeaderboardReadRef);

	// Leaderboard read complete (OnLeaderboardReadComplete delegate callback)
	void EOSClearOnLeaderboardReadCompleteDelegate(const bool bWasSuccessful);

	//void EOSQueryUsersStatsCompleteDelegate(const FOnlineError& Error, const TArray<TSharedRef<const FOnlineStatsUserStats>>& UserStats);

	/*UFUNCTION(BlueprintCallable, Category = EOS)
	int32 ReturnPlayerRank(int Count);

	UFUNCTION(BlueprintCallable, Category = EOS)
	FString ReturnPlayerName(int Count);

	UFUNCTION(BlueprintCallable, Category = EOS)
	int32 ReturnPlayerScore(int Count);*/

	//void EOSUpdateStatsCompleteFunction(const FOnlineError& Error);

	//// Leaderboard stat update complete
	//void EOSUpdateStatsCompleteDelegate(const FOnlineError& Error);

protected:


private:

	
};
