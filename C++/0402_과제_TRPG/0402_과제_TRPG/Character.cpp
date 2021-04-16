#include "stdafx.h"
#include "Character.h"


CCharacter::CCharacter()
	:m_pStatus(nullptr)
{
}


CCharacter::~CCharacter()
{
}

void CCharacter::Attck(CCharacter * Attacker, CCharacter * Attacked_side)
{
	int damage = Attacked_side->m_pStatus->m_iDEF - Attacker->m_pStatus->m_iATK;
	if (damage < 0)
	{
		Attacked_side->GetStatus()->m_iHP += damage;
	}
}

STATUS * CCharacter::GetStatus()
{
	return this->m_pStatus;
}
