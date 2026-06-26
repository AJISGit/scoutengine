#pragma once
#include <scout.hpp>
#include <unordered_map>
#include <string>
#include <string_view>
#include <utility>
#include <vector>


namespace Scout {

	class Instance;
	template <typename T>
	class InstancePtr;

	using BasicInstPtr = InstancePtr<Instance>;

	/**
	 * @brief The base class for all objects in a game.
	*/
	class Instance {

		private:

		Instance* parent = nullptr;
		std::unordered_map<std::string, Instance*> children;

		protected:

		std::string name = "Instance";
		bool drawable = false;
		bool destroyable = true;

		
		void _setParent(const BasicInstPtr& parent);

		public:

		Instance(std::string_view name, BasicInstPtr parent);
		virtual ~Instance();

		/**
		 * @brief Returns the child `name`
		 * @return The child with the name `name`. Or `nullptr` if it doesn't exist.
		*/
		BasicInstPtr getChild(std::string_view name) const;
		std::vector<BasicInstPtr> getChildren() const;
		/// Adds an `Instance` to this `Instance`'s children.
		void addChild(const BasicInstPtr& child);
		/**
		 * @brief Removes but does not deallocate a child from the `Instance`'s children.
		 * @return A pointer to the removed `Instance`. 
		*/
		BasicInstPtr removeChild(std::string_view name);
		/// Removes and deallocates a child.
		void deleteChild(std::string_view name);

		/**
		 * @brief Returns the parent of this `Instance`.
		 * @return This `Instance`'s parent.
		*/
		virtual BasicInstPtr getParent() const;
		/// Sets the parent of this `Instance`.
		virtual void setParent(const BasicInstPtr& parent);

		/**
		 * @brief Gets the name of this `Instance`.
		 * @return This `Instance`'s name.
		*/
		std::string getName() const;
		/// Sets the name of this `Instance`.
		virtual void setName(std::string_view name);

		
		/// Per `Instance` behavior each frame.
		virtual void update();
		/// Draws the `Instance`. Does nothing for the base `Instance` class.
		virtual void draw();

		/**
		 * @brief Checks if the instance is drawable.
		 * @return If this `Instance` is drawable.
		*/
		bool isDrawable() const;
		bool isDestroyable() const;

	};

}
