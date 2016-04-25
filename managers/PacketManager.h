/****************************************************************************
**
** PacketManager.h
**
** Copyright (C) September 2015 Hotride
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
*****************************************************************************
*/
//---------------------------------------------------------------------------
#ifndef PacketManagerH
#define PacketManagerH
//---------------------------------------------------------------------------
class TPacketManager;
typedef void (TPacketManager::*PACKET_FUNCTION)(PBYTE buf, const int &size);
//---------------------------------------------------------------------------
//!����������� ������
enum PACKET_DIRECTION
{
	DIR_SEND = 0,	//!�� ������� �������
	DIR_RECV,		//!�� ������� �������
	DIR_BOTH		//!� ��� �������
};
//---------------------------------------------------------------------------
//!����� ��� �������� ���������� � �������
class TMessageType
{
public:
	//!�������� ������
	const char *Name;

	//!������ ������
	int Size;

	//!����������� ������
	PACKET_DIRECTION Direction;

	//!���������� ������
	PACKET_FUNCTION Handler;
};
//---------------------------------------------------------------------------
#define HANDLER_PACKET(name)void Handle ##name (PBYTE buf, const int &size);
//---------------------------------------------------------------------------
//!����� ��������� �������
class TPacketManager
{
private:
	//!������ ��������
	static TMessageType m_MessageTypes[];

	//!������ ���������
	CLIENT_VERSION m_ClientVersion;

	//!��������� �� ������ ������
	PBYTE Ptr;

	/*!
	����������� �� ������ ������
	@param [__in] offset ��������
	@return 
	*/
	inline void Move(__in int offset) { Ptr += offset; }

	/*!
	��������� ���� (1 ����)
	@return ������
	*/
	BYTE ReadByte();

	/*!
	��������� ����� (2 �����)
	@return ������
	*/
	WORD ReadWord();

	/*!
	��������� ������� ����� (4 �����)
	@return ������
	*/
	DWORD ReadDWord();

	/*!
	��������� ������ (1 ����)
	@return ������
	*/
	char ReadChar();

	/*!
	��������� �������� �������� (2 �����)
	@return ������
	*/
	short ReadShort();

	/*!
	��������� ����� �������� (4 �����)
	@return ������
	*/
	int ReadInt();

	/*!
	��������� ASCII ������
	@param [__in] size ������ ������, ���� ������ 0 - ������ �� ����
	@return 
	*/
	string ReadString(__in int size);

	/*!
	��������� Unicode ������
	@param [__in] size ������ ������, ���� ������ 0 - ������ �� ����
	@return ������
	*/
	wstring ReadUnicodeString(__in int size);

	vector<DWORD> m_MegaClilocRequests;
protected:
	//!����������� �������
	HANDLER_PACKET(ClientTalk)
	HANDLER_PACKET(LoginError)
	HANDLER_PACKET(ServerList)
	HANDLER_PACKET(RelayServer)
	HANDLER_PACKET(CharacterList)
	HANDLER_PACKET(ResendCharacterList)
	HANDLER_PACKET(LoginComplete)
	HANDLER_PACKET(SetTime)
	HANDLER_PACKET(EnterWorld)
	HANDLER_PACKET(UpdateHitpoints)
	HANDLER_PACKET(UpdateMana)
	HANDLER_PACKET(UpdateStamina)
	HANDLER_PACKET(UpdatePlayer)
	HANDLER_PACKET(CharacterStatus)
	HANDLER_PACKET(UpdateItem)
	HANDLER_PACKET(UpdateItemSA)
	HANDLER_PACKET(UpdateObject)
	HANDLER_PACKET(EquipItem)
	HANDLER_PACKET(UpdateContainedItem)
	HANDLER_PACKET(UpdateContainedItems)
	HANDLER_PACKET(DenyMoveItem)
	HANDLER_PACKET(DeleteObject)
	HANDLER_PACKET(UpdateCharacter)
	HANDLER_PACKET(Warmode)
	HANDLER_PACKET(PauseControl)
	HANDLER_PACKET(OpenPaperdoll)
	HANDLER_PACKET(ClientVersion)
	HANDLER_PACKET(Ping)
	HANDLER_PACKET(SetWeather)
	HANDLER_PACKET(PersonalLightLevel)
	HANDLER_PACKET(LightLevel)
	HANDLER_PACKET(EnableLockedFeatures)
	HANDLER_PACKET(OpenContainer)
	HANDLER_PACKET(UpdateSkills)
	HANDLER_PACKET(ExtendedCommand)
	HANDLER_PACKET(DenyWalk)
	HANDLER_PACKET(ConfirmWalk)
	HANDLER_PACKET(OpenUrl)
	HANDLER_PACKET(Target)
	HANDLER_PACKET(Talk)
	HANDLER_PACKET(UnicodeTalk)
	HANDLER_PACKET(OpenMenuGump)
	HANDLER_PACKET(SecureTrading)
	HANDLER_PACKET(TextEntryDialog)
	HANDLER_PACKET(OpenGump)
	HANDLER_PACKET(OpenCompressedGump)
	HANDLER_PACKET(TipWindow)
	HANDLER_PACKET(MultiPlacement)
	HANDLER_PACKET(GraphicEffect)
	HANDLER_PACKET(BuyList)
	HANDLER_PACKET(SellList)
	HANDLER_PACKET(BuyReply)
	HANDLER_PACKET(DeathScreen)
	HANDLER_PACKET(PlaySoundEffect)
	HANDLER_PACKET(PlayMusic)
	HANDLER_PACKET(DragAnimation)
	HANDLER_PACKET(CorpseEquipment)
	HANDLER_PACKET(ASCIIPrompt)
	HANDLER_PACKET(UnicodePrompt)
	HANDLER_PACKET(CharacterAnimation)
	HANDLER_PACKET(DisplayQuestArrow)
	HANDLER_PACKET(DisplayMap)
	HANDLER_PACKET(MapData)
	HANDLER_PACKET(DyeData)
	HANDLER_PACKET(CharacterProfile)
	HANDLER_PACKET(ClientViewRange)
	HANDLER_PACKET(OpenBook)
	HANDLER_PACKET(OpenBookNew)
	HANDLER_PACKET(BookData)
	HANDLER_PACKET(KarriosClientSpecial)
	HANDLER_PACKET(AssistVersion)
	HANDLER_PACKET(CharacterListNotification)
	HANDLER_PACKET(ErrorCode)
	HANDLER_PACKET(AttackCharacter)
	HANDLER_PACKET(Season)
	HANDLER_PACKET(BulletinBoardData)
	HANDLER_PACKET(DisplayDeath)
	HANDLER_PACKET(OpenChat)
	HANDLER_PACKET(DisplayClilocString)
	HANDLER_PACKET(MegaCliloc)
	HANDLER_PACKET(Damage)

//�� ����������
/*
0x15 BMSG("Follow", 0x09),
0x2D RMSG("Mob Attributes", 0x11),
0x2F RMSG("Combat Notification", 0x0a),
0x97 RMSG("Move Player", 0x02),
0xB2 BMSG("Chat Data", SIZE_VARIABLE),
0xB3 RMSG("Chat Text ?", SIZE_VARIABLE),
0xB5 BMSG("Open Chat Window", 0x40),
0xB7 RMSG("Popup Help Data", SIZE_VARIABLE),
0xD7 BMSG("+AoS command",SIZE_VARIABLE),
0xD8 RMSG("+Custom house",SIZE_VARIABLE),
0xDC RMSG("OPL Info Packet", 9),
0xDF RMSG("Buff/Debuff", SIZE_VARIABLE),
0xE2 RMSG("New Character Animation", 0xa),
*/

public:
	TPacketManager();
	~TPacketManager() {}

	/*!
	�������� ������ ������
	@param [__in] msg ������ ������
	@return ������ ������
	*/
	int GetPacketSize(__in const BYTE &msg) const { return m_MessageTypes[msg].Size; }

	/*!
	���������� ���������� ���������
	@param [__in] buf �����
	@param [__in] size ������ ���������
	@return 
	*/
	void ReceiveHandler(__in PBYTE buf, __in const int &size);

	/*!
	���������� ���������� ��������� �� �������
	@param [__in] buf �����
	@param [__in] size ������ ���������
	@return
	*/
	void PluginReceiveHandler(__in PBYTE buf, __in const int &size);

	/*!
	���������� ������ ��������� ������� � ��������� ����������� ��������������� �������
	@param [__in] val ����� ������ ��������� �������
	@return 
	*/
	void SetClientVersion(__in CLIENT_VERSION val);
	CLIENT_VERSION GetClientVersion() const { return m_ClientVersion; }

	/*!
	�������� ��������� �� ��������� � ����������� � ������
	@param [__in] id ������ ������
	@return ������ � ������
	*/
	TMessageType GetType(__in const BYTE &id) const { return m_MessageTypes[id]; }

	void SendMegaClilocRequests();
};
//---------------------------------------------------------------------------
extern TPacketManager PacketManager;
//---------------------------------------------------------------------------
#endif