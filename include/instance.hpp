#pragma once
#include <scout.hpp>
#include <unordered_map>
#include <string>
#include <string_view>


namespace Scout {

	class Instance;

	/**
	 * @brief The base class for all objects in a game.
	*/
	class Instance {

		private:

		Instance* parent = nullptr;
		std::unordered_map<std::string, Instance*> children;
		std::string name = "Instance";

		bool drawable = false;

		public:

		Instance();
		virtual ~Instance();

		/**
		 * @brief Returns the child `name`
		 * @return The child with the name `name`. Or `nullptr` if it doesn't exist.
		*/
		Instance* getChild(std::string_view name);
		/// Adds an `Instance` to this `Instance`'s children.
		void addChild(Instance* child);
		/**
		 * @brief Removes but does not deallocate a child from the `Instance`'s children.
		 * @return A pointer to the removed `Instance`. 
		*/
		Instance* removeChild(std::string_view name);
		/// Removes and deallocates a child.
		void deleteChild(std::string_view name);

		/**
		 * @brief Returns the parent of this `Instance`.
		 * @return This `Instance`'s parent.
		*/
		Instance* getParent();
		/// Sets the parent of this `Instance`.
		void setParent(Instance* parent);

		/**
		 * @brief Gets the name of this `Instance`.
		 * @return This `Instance`'s name.
		*/
		std::string getName();
		/// Sets the name of this `Instance`.
		void setName(std::string_view name);

		
		/// Per `Instance` behavior each frame.
		virtual void update();
		/// Draws the `Instance`. Does nothing for the base `Instance` class.
		virtual void draw();

		/**
		 * @brief Checks if the instance is drawable.
		 * @return If this `Instance` is drawable.
		*/
		bool isDrawable();


	};

}
