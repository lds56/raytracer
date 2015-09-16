#include <memory>

#include "Scene.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("raytracer <input filename> <output filename>\n");
		return 1;
	}

	char* inputName = argv[1];
	char* outputName = argv[2];

	shared_ptr<Scene> scenePtr (inputName);

	printf("Done!\n");

	return 0;
}
