#include "pch.h"

using namespace System;
#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew  ExternalSorting::Form1());
	return 0;
}