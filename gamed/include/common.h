/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2012  Intline9 <Intline9@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _COMMON_H
#define _COMMON_H

#include "stdafx.h"

enum GameCmd : uint8
{
	PKT_S2C_MoveAns                 = 0x61,
};

//Currently attuned to Live 4.12.0.356
enum PacketCmd : uint8
{                                            
   PKT_KeyCheck = 0x00, 

   PKT_S2C_EndSpawn = 0x11,
   PKT_C2S_QueryStatusReq = 0x14,
   PKT_S2C_SkillUp = 0x15,   // 4.12
   PKT_C2S_Ping_Load_Info = 0x16,

   PKT_S2C_ViewAns = 0x2C,   // 4.12
   PKT_C2S_ViewReq = 0x2E,   // 4.12

   PKT_C2S_SkillUp = 0x39,   // 4.12
   PKT_S2C_AttentionPing = 0x3F,

   PKT_S2C_Emotion = 0x42,
   PKT_C2S_Emotion = 0x47,
   PKT_S2C_HeroSpawn = 0x4C,  // 4.12
   PKT_S2C_Announce = 0x4D,   // 4.12

   PKT_S2C_GameTimer = 0xC0,
   PKT_S2C_GameTimerUpdate = 0xC1,

   PKT_C2S_StartGame = 0x52,    // 4.12
   PKT_S2C_SynchVersion = 0x54, // 4.12
   PKT_C2S_ScoreBord = 0x56,
   PKT_C2S_AttentionPing = 0x57,
   PKT_S2C_StartGame = 0x5C,    // 4.12

   PKT_S2C_StartSpawn = 0x62,
   PKT_C2S_ClientReady = 0x64,
   PKT_S2C_LoadHero = 0x65,    // 4.12
   PKT_S2C_LoadName = 0x66,    // 4.12
   PKT_S2C_LoadScreenInfo = 0x67,
   PKT_ChatBoxMessage = 0x68,
   PKT_S2C_Unk2 = 0x6E,
   PKT_S2C_BuyItemAns = 0x6E,

   PKT_C2S_MoveReq = 0x72,
   PKT_C2S_MoveConfirm = 0x77,

   PKT_C2S_LockCamera = 0x81,
   PKT_C2S_BuyItemReq = 0x82,
   PKT_S2C_QueryStatusAns = 0x88, // 4.12
   PKT_C2S_Exit = 0x8F,

   PKT_World_SendGameNumber = 0x92,
   PKT_S2C_Ping_Load_Info = 0x95, // 4.12
   PKT_C2S_CastSpell = 0x9A,      // 4.12
   PKT_S2C_TurretSpawn = 0x9D,    // 4.12

   PKT_C2S_Surrender = 0xA4,
   PKT_C2S_StatsConfirm = 0xA8, 
   PKT_C2S_Click = 0xAF, 

   PKT_S2C_CastSpellAns = 0xB5,
   PKT_S2C_MinionSpawn = 0xBA,
   PKT_C2S_SynchVersion = 0xBD, // 4.12
   PKT_C2S_CharLoaded = 0xBE,   // 4.12

   PKT_S2C_CharStats = 0xC4,
   PKT_S2C_FogUpdate2 = 0x23,
   PKT_S2C_LevelPropSpawn = 0xD0,

   PKT_S2C_UNK          = 0xFE, // Change target ??

   PKT_Batch = 0xFF
};

enum MoveType : uint8
{
   EMOTE = 1,
   MOVE = 4,
   STOP = 10,
};

enum ChatType : uint32
{
   CHAT_ALL = 0,
   CHAT_TEAM = 1,
};

#define CHL_MAX = 7
enum Channel : uint8
{
   CHL_HANDSHAKE = 0,
   CHL_C2S = 1,
   CHL_GAMEPLAY =2,
   CHL_S2C = 3,
   CHL_LOW_PRIORITY = 4,
   CHL_COMMUNICATION = 5,
   CHL_LOADING_SCREEN = 7,
};

enum Spell : uint32
{
   SPL_Revive = 0x05C8B3A5,
   SPL_Smite = 0x065E8695,
   SPL_Exhaust = 0x08A8BAE4,
   SPL_Barrier = 0x0CCFB982,
   SPL_Teleport = 0x004F1364,
   SPL_Ghost = 0x064ACC95,
   SPL_Heal = 0x0364AF1C,
   SPL_Cleanse = 0x064D2094,
   SPL_Clarity = 0x03657421,
   SPL_Ignite = 0x06364F24,
   SPL_Promote = 0x0410FF72,
   SPL_Clair = 0x09896765,
   SPL_Flash = 0x06496EA8, 
   SPL_Test = 0x0103D94C,
};

enum MasterMask : uint8
{
   MM_One          = 0x01,
   MM_Two          = 0x02,
   MM_Three        = 0x04,
   MM_Four         = 0x08,
   MM_Five         = 0x10,
};

enum FieldMaskOne : uint32
{
   FM1_Gold        = 0x00000001,
   FM1_Gold_2      = 0x00000002,
   FM1_SPELL       = 0x00000004 // Sending short 0x108[1248] activates spells 1/2/3/4
};

enum FieldMaskTwo : uint32
{
   FM2_Base_Ad       = 0x00000020, // champ's base ad that increase every level. No item bonus should be added here
   FM2_Armor         = 0x00000100,
   FM2_Hp5           = 0x00000800,
   FM2_Mp5           = 0x00001000,
   FM2_Bonus_Ad_Flat = 0x00004000, // AD flat bonuses
   FM2_Bonus_Ad_Pct  = 0x00008000, // AD percentage bonuses. 0.5 = 50%
   FM2_Bonus_Ap_Flat = 0x00010000, // AP flat bonuses
   FM2_Bonus_Ats     = 0x00080000, // Attack speed bonus. If set to 2 and champ's base attack speed is 0.600, then his new AtkSpeed becomes 1.200
   FM2_cdr           = 0x00800000, // Cooldown reduction. 0.5 = 50%
};

enum FieldMaskThree : uint32
{
   FM3_Armor_Pen = 0x00000001,
   FM3_Magic_Pen = 0x00000002
   
};

enum FieldMaskFour : uint32
{
   FM4_CurrentHp   = 0x00000001,
   FM4_CurrentMana = 0x00000002,
   FM4_MaxHp       = 0x00000004,
   FM4_MaxMp       = 0x00000008,
   FM4_exp         = 0x00000010,
   FM4_Vision1     = 0x00000100,
   FM4_Vision2     = 0x00000200,
   FM4_Speed       = 0x00000400,
   FM4_ModelSize   = 0x00000800,
};

enum FieldMaskFive : uint32
{
};
#endif