#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>
#include <draw.hpp>

#include <instanceptr.hpp>
#include <lockedinstance.hpp>

#include <texture.hpp>
#include <stb_image.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


int main() {

	Scout::InstancePtr<Scout::LockedInstance> instptr = Scout::newInstance<Scout::LockedInstance>("ParentInst", Scout::BasicInstPtr(nullptr));
	Scout::BasicInstPtr childptr1 = Scout::newInstance<Scout::Instance>("ChildInst", instptr);
	Scout::BasicInstPtr childptr2 = Scout::newInstance<Scout::Instance>("ChildInst2", instptr);


	std::cout << instptr->getName() << '\n';

	std::cout << "---------------\n";
	for (Scout::BasicInstPtr child : instptr->getChildren()) {
		std::cout << child->getName() << '\n';
	}

	return 0;

}
