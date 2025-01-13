// Copyright (C) 2024, Vinushan Vickneswaran. All rights reserved.


#include "SOWGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "IOnlineSubsystemEOS.h"
#include "Interfaces/OnlineStatsInterface.h"
#include "Interfaces/OnlineLeaderboardInterface.h"


void USOWGameInstance::EOSLogin()
{
	FOnlineAccountCredentials AccountPortalLogin;

	//FOnlineAccountCredentials DeveloperLogin;

	//FOnlineAccountCredentials ExchangeCodeLogin;
	
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();
		
		if (IdentityPointer != nullptr)
		{
			AccountPortalLogin.Type = "AccountPortal";
			AccountPortalLogin.Id = Id; // blueprint edit this value at login
			AccountPortalLogin.Token = Token; // blueprint edit this value at login

			//IdentityPointer->OnLoginCompleteDelegates();
			IdentityPointer->Login(0, AccountPortalLogin);

			FDelegateHandle LoginComplete;
			IdentityPointer->AddOnLoginCompleteDelegate_Handle(0, FOnLoginComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLoginCompleteDelegate));
		}
	}
}


void USOWGameInstance::EOSLoginDeveloper()
{
	//FOnlineAccountCredentials AccountPortalLogin;

	FOnlineAccountCredentials DeveloperLogin;

	//FOnlineAccountCredentials ExchangeCodeLogin;
	
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			DeveloperLogin.Type = "Developer";
			DeveloperLogin.Id = Id;
			DeveloperLogin.Token = Token;

			IdentityPointer->Login(0, DeveloperLogin);
			IdentityPointer->AddOnLoginCompleteDelegate_Handle(0, FOnLoginComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLoginCompleteDelegate));
		}
	}
	
	
}

void USOWGameInstance::EOSLoginExchangeCode()
{
	//FOnlineAccountCredentials AccountPortalLogin;

	//FOnlineAccountCredentials DeveloperLogin;

	FOnlineAccountCredentials ExchangeCodeLogin;
	
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			ExchangeCodeLogin.Type = "ExchangeCode";
			ExchangeCodeLogin.Id = Id; // blueprint edit this value at login
			ExchangeCodeLogin.Token = Token;

			IdentityPointer->Login(0, ExchangeCodeLogin);
			IdentityPointer->AddOnLoginCompleteDelegate_Handle(0, FOnLoginComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLoginCompleteDelegate));
			//IdentityPointer->
		}
	}
	
	
}

void USOWGameInstance::EOSReadLeaderboard(FString LeaderboardId)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineLeaderboardsPtr LeaderboardsPointer = SubsystemEOS->GetLeaderboardsInterface();

			if (LeaderboardsPointer != nullptr)
			{
				///*FOnlineLeaderboardRead LeaderboardRead;

				//LeaderboardRead.LeaderboardName = FName(LeaderboardId);

				//LeaderboardsPointer->ReadLeaderboardsAroundRank(0, 100, LeaderboardRead);

				//TArray<FOnlineStatsRow> LeaderboardArray;*/
				////FOnlineLeaderboardRead FOnlineLeaderboardRead2;
				////FOnlineLeaderboardRead2

				FOnlineLeaderboardReadRef LeaderboardReadRef;
				//FOnlineLeaderboardReadRef LeaderboardReadRef = TSharedRef<FOnlineLeaderboardRead, ESPMode::ThreadSafe>();

				//FOnlineLeaderboardReadRef LeaderboardReadRef;

				//FOnlineLeaderboardReadPtr LeaderboardReadPointer = TSharedPtr<FOnlineLeaderboardRead, ESPMode::ThreadSafe>();

				/*LeaderboardReadPointer = LeaderboardReadRef.ToSharedPtr();*/

				//LeaderboardReadPointer->LeaderboardName = FName(LeaderboardId);

				LeaderboardReadRef->LeaderboardName = FName(LeaderboardId);

				LeaderboardsPointer->ReadLeaderboardsAroundRank(0, 50, LeaderboardReadRef);

				////LeaderboardsPointer->ReadLeaderboardsAroundRank(0, 50, FOnlineLeaderboardRead2);
				LeaderboardsPointer->AddOnLeaderboardReadCompleteDelegate_Handle(FOnLeaderboardReadComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLeaderboardReadCompleteDelegate, LeaderboardReadRef));

				///*sizeof(LeaderboardReadRef->Rows);
				//LeaderboardReadRef->Rows[1].Rank;*/


				////LeaderboardEntryRank[sizeof(LeaderboardReadRef->Rows)];

				////LeaderboardEntry LeaderboardEntryArray[sizeof(LeaderboardReadRef->Rows)]{};
				

				///*for (int i = 0; i <= sizeof(LeaderboardReadRef->Rows); i++)
				//{

				//}
				//*/


			}
		}
	}
}

void USOWGameInstance::EOSReadFriendLeaderboard(FString LeaderboardId)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineLeaderboardsPtr LeaderboardsPointer = SubsystemEOS->GetLeaderboardsInterface();

			if (LeaderboardsPointer != nullptr)
			{
				FOnlineLeaderboardReadRef LeaderboardReadRef;
				
				//FOnlineLeaderboardReadRef LeaderboardReadRef = TSharedRef<FOnlineLeaderboardRead, ESPMode::ThreadSafe>();

				LeaderboardReadRef->LeaderboardName = FName(LeaderboardId);

				LeaderboardsPointer->ReadLeaderboardsForFriends(0, LeaderboardReadRef);

				LeaderboardsPointer->AddOnLeaderboardReadCompleteDelegate_Handle(FOnLeaderboardReadComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLeaderboardReadCompleteDelegate, LeaderboardReadRef));

				///*sizeof(LeaderboardReadRef->Rows);
				//LeaderboardReadRef->Rows[1].Rank;*/


				////LeaderboardEntryRank[sizeof(LeaderboardReadRef->Rows)];

				////LeaderboardEntry LeaderboardEntryArray[sizeof(LeaderboardReadRef->Rows)]{};


				///*for (int i = 0; i <= sizeof(LeaderboardReadRef->Rows); i++)
				//{

				//}
				//*/
			}
		}
	}
}

void USOWGameInstance::EOSReadPlayerLeaderboard(FString LeaderboardId)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineLeaderboardsPtr LeaderboardsPointer = SubsystemEOS->GetLeaderboardsInterface();

			if (LeaderboardsPointer != nullptr)
			{
				FOnlineLeaderboardReadRef LeaderboardReadRef;

				FOnlineLeaderboardReadPtr LeaderboardReadPointer = TSharedPtr<FOnlineLeaderboardRead, ESPMode::ThreadSafe>();

				LeaderboardReadPointer = LeaderboardReadRef.ToSharedPtr();
				
				//FOnlineLeaderboardReadRef LeaderboardReadRef = TSharedRef<FOnlineLeaderboardRead, ESPMode::ThreadSafe>();

				LeaderboardReadRef->LeaderboardName = FName(LeaderboardId);

				LeaderboardsPointer->ReadLeaderboardsAroundUser(IdentityPointer->GetUniquePlayerId(0).ToSharedRef(), 50, LeaderboardReadRef);

				LeaderboardsPointer->AddOnLeaderboardReadCompleteDelegate_Handle(FOnLeaderboardReadComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSAddOnLeaderboardReadCompleteDelegate, LeaderboardReadRef));
			}
		}
	}
}

// Following function was inspired from https://www.youtube.com/watch?v=m-WbIqIq_UQ
void USOWGameInstance::EOSUpdateStat(FString Stat, int32 Value)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineStatsPtr StatsPointer = SubsystemEOS->GetStatsInterface();

			if (StatsPointer != nullptr)
			{
				FOnlineStatsUserUpdatedStats StatToUpdate = FOnlineStatsUserUpdatedStats(IdentityPointer->GetUniquePlayerId(0).ToSharedRef());
				StatToUpdate.Stats.Add(Stat, FOnlineStatUpdate(Value, FOnlineStatUpdate::EOnlineStatModificationType::Unknown));

				TArray<FOnlineStatsUserUpdatedStats> StatArray;
				StatArray.Add(StatToUpdate);
				//StatsPointer->UpdateStats(IdentityPointer->GetUniquePlayerId(0).ToSharedRef(), StatArray, FOnlineStatsUpdateStatsComplete::CreateUObject(this, &USOWGameInstance::EOSUpdateStatsCompleteDelegate));
				StatsPointer->UpdateStats(IdentityPointer->GetUniquePlayerId(0).ToSharedRef(), StatArray, FOnlineStatsUpdateStatsComplete::CreateLambda([](
				const FOnlineError& Error)
					{
						if (Error == FOnlineError::Success())
						{
							check(GEngine != nullptr);
							GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Stat uploaded"));
						}
						else
						{
							check(GEngine != nullptr);
							GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *Error.ToLogString());
						}
					}));
			}
		}
	}

}

// Following function was inspired from https://www.youtube.com/watch?v=m-WbIqIq_UQ
void USOWGameInstance::EOSRetrieveStat(TArray<FString> Stats)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineStatsPtr StatsPointer = SubsystemEOS->GetStatsInterface();

			if (StatsPointer != nullptr)
			{
				//int32 Value;
				TArray<TSharedRef<const FUniqueNetId>> UniqueNetId;
				UniqueNetId.Add(IdentityPointer->GetUniquePlayerId(0).ToSharedRef());
				StatsPointer->QueryStats(IdentityPointer->GetUniquePlayerId(0).ToSharedRef(), UniqueNetId, Stats, FOnlineStatsQueryUsersStatsComplete::CreateLambda([](const FOnlineError& Error, const TArray<TSharedRef<const FOnlineStatsUserStats>>& UserStats)
					{
						if (Error.WasSuccessful())
						{
							check(GEngine != nullptr);
							GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Stats retrieved"));

							int32 Value;

							for (auto Stats : UserStats)
							{
								for (auto StoredValueRef : Stats->Stats)
								{
									FString Key = StoredValueRef.Key;
									//int32 Value;
									StoredValueRef.Value.GetValue(Value);

									FString ValueinFString = "Your all-time fastest completion time in seconds is " + FString::FromInt(Value);
									check(GEngine != nullptr);
									GEngine->AddOnScreenDebugMessage(-1, 120.0f, FColor::White, ValueinFString);
									//UE_LOG(LogTemp, Warning, TEXT("The all-time fastest completion time is"));
									//RetrievedStat = *Key.Value;
								}
							}
						}
						else
						{
							check(GEngine != nullptr);
							GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *Error.ToLogString());
						}
					}));
				//StatsPointer->QueryStats(IdentityPointer->GetUniquePlayerId(0).ToSharedRef(), UniqueNetId, Stats, FOnlineStatsQueryUsersStatsComplete::CreateUObject(this, &USOWGameInstance::EOSQueryUsersStatsCompleteDelegate));
			}
		}
	}
}

void USOWGameInstance::SetRetrievedStat(int32 Stat)
{
	RetrievedStat = Stat;
}

void USOWGameInstance::UpdateLeaderboardEntry(TArray<int32> PlayerRank, TArray<FString> PlayerName, TArray<int32> PlayerScore)
{

}

void USOWGameInstance::EOSAddOnLoginCompleteDelegate(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	if (bWasSuccessful == true)
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Login completed"));

		IsLoggedIn = true;
	}
	else
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *Error);

		IsLoggedIn = false;
	}
}

void USOWGameInstance::EOSAddOnLeaderboardReadCompleteDelegate(bool bWasSuccessful, FOnlineLeaderboardReadRef InLeaderboardReadRef)
{
	IOnlineSubsystem* SubsystemEOS = Online::GetSubsystem(GetWorld());

	if (SubsystemEOS != nullptr)
	{
		IOnlineIdentityPtr IdentityPointer = SubsystemEOS->GetIdentityInterface();

		if (IdentityPointer != nullptr)
		{
			IOnlineLeaderboardsPtr LeaderboardsPointer = SubsystemEOS->GetLeaderboardsInterface();

			if (LeaderboardsPointer != nullptr)
			{
				//LeaderboardsPointer->ClearOnLeaderboardReadCompleteDelegate_Handle(FOnLeaderboardReadComplete::FDelegate::CreateUObject(this, &USOWGameInstance::EOSClearOnLeaderboardReadCompleteDelegate));
			}
		}
	}
	
	if (bWasSuccessful == true)
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Leaderboard read"));

		LeaderboardPlayerRank.Empty();
		LeaderboardPlayerName.Empty();
		LeaderboardPlayerScore.Empty();

		for (int i = 0; i < sizeof(InLeaderboardReadRef->Rows); i++)
		{
			LeaderboardPlayerRank[i] = InLeaderboardReadRef->Rows[i].Rank;
			LeaderboardPlayerName[i] = InLeaderboardReadRef->Rows[i].NickName;

			int32 Value;
			InLeaderboardReadRef->Rows[i].Columns[TEXT("Score")].GetValue(Value);
			LeaderboardPlayerScore[i] = Value;
		}
	}
	else
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Leaderboard not read"));
	}
}

void USOWGameInstance::EOSClearOnLeaderboardReadCompleteDelegate(const bool bWasSuccessful)
{
	if (bWasSuccessful == true)
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Leaderboard delegate cleared"));
	}
	else
	{
		check(GEngine != nullptr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Leaderboard delegate not cleared"));
	}
}

//void USOWGameInstance::EOSQueryUsersStatsCompleteDelegate(const FOnlineError& Error, const TArray<TSharedRef<const FOnlineStatsUserStats>>& UserStats)
//{
//	if (Error == FOnlineError::Success())
//	{
//		check(GEngine != nullptr);
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Stats retrieved"));
//
//		int32 Value;
//
//		for (auto Stats : UserStats)
//		{
//			for (auto StoredValueRef : Stats->Stats)
//			{
//				FString Key = StoredValueRef.Key;
//				StoredValueRef.Value.GetValue(Value);
//				RetrievedStat = Value;
//			}
//		}
//	}
//	else
//	{
//		check(GEngine != nullptr);
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *Error.ToLogString());
//	}
//}

//int32 USOWGameInstance::ReturnPlayerRank(int Count)
//{
//	//return LeaderboardReadRef->Rows[Count].Rank;
//}
//FString USOWGameInstance::ReturnPlayerName(int Count)
//{
//	//return LeaderboardReadRef->Rows[Count].NickName;
//}
//int32 USOWGameInstance::ReturnPlayerScore(int Count)
//{
//	int32 PlayerScore;
//	//LeaderboardReadRef->Rows[Count].Columns[TEXT("Score")].GetValue(PlayerScore);
//	
//	return PlayerScore;
//}

