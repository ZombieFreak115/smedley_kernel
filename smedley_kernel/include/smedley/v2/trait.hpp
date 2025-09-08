#pragma once
#include "../clausewitz/persistent.hpp"


namespace smedley::v2
{
	/*
	
	Represents a trait that a general or admiral can have two of, one background trait, and one personality trait.
	*/
	class CTrait : public clausewitz::CPersistent {
	protected:
		uint32_t _uk_0x8;
		uint32_t _uk_0xc;
		uint32_t _uk_0x10;
		uint32_t _uk_0x14;
		uint32_t _uk_0x18;
		uint32_t _uk_0x1c;
		uint32_t _uk_0x20;
		uint32_t _uk_0x24;
		int _localisation_key; // 0x28, not sure about this one
		sstd::string _name; // 0x2c
		uint32_t _uk_0x48;
	};
	static_assert(sizeof(CTrait) == 0x4c);


}