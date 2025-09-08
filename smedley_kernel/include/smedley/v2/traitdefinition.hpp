#pragma once


namespace smedley::v2
{
	/*

	Represents a trait definition which are hardcoded for each trait effect (such as organization, attack, defence, reconasance etc)
	*/
	class CTraitDefinition {
	protected:
		uint32_t _vtpr; // 0x0
		sstd::string _name; // 0x4
		int id; // not sure
		int ordinal; // not sure
		uint32_t _uk_0x28;
	};
	static_assert(sizeof(CTraitDefinition) == 0x2c);


}