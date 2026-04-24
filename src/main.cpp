#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <instance.hpp>


int main() {

	Scout::Instance* parent = new Scout::Instance;
	parent->setName("Parent");

	Scout::Instance* child = new Scout::Instance;
	child->setName("Child");

	parent->addChild(child);


	Scout::Instance* grandchild = new Scout::Instance;
	grandchild->setName("Grandchild");
	child->addChild(grandchild);

	child->deleteChild("Grandchild");


	delete parent;

	return 0;

}
