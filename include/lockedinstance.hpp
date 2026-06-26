#pragma once
#include <instance.hpp>


namespace Scout {

	class LockedInstance : public Instance {
	
		public:

		LockedInstance(std::string_view name, const BasicInstPtr& parent);

		virtual void setParent(const BasicInstPtr& parent) override;		
		virtual void setName(std::string_view name) override;

	};

}
