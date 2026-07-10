#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[MTAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	SnakeGame::GameForm form;
	Application::Run(% form);
}