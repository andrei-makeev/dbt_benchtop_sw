#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String ^> ^args)
{
    //----- enable Windows visual effects before any controls are created

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//----- create main window and run it

	dbt_benchtop::MyForm1 form;
	Application::Run(%form);
}
