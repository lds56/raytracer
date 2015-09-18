#include "Scene.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("raytracer <input filename> <output filename>\n");
		return 1;
	}

	char* inputName = argv[1];
	char* outputName = argv[2];

	ScenePtr scenePtr = ScenePtr(new Scene(inputName));

    //string s_cwd(getcwd(NULL,0));
    //cout << "CWD is: " << s_cwd << endl;

	cout << "done!" << endl;

	return 0;
}
