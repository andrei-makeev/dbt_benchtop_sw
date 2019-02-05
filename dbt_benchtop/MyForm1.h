// This graphical application allows to control the digital breast tomosynthesis (DBT)
// benchtop system, we have built at the FDA, and acquire x-ray projection images in one of
// the three pre-set acquisition geometries or in full-field digital mammography (FFDM) mode.
// The purpose of sharing this code is to help developers and students who are putting together
// a similar experimental system for the first time.
// MS Visual Studio 2013 IDE (C++) was used to write this program. The software also makes use of
// the National Instruments NI DAQmx suite to support DAQmx interface board PCIe-6323 used for
// triggering, detector commutation, measuring pulses, etc., as well as, PCommServer Pro2 library
// by Delta Tau, to interact with the Turbo Clipper programmable multi-axis controller (PMAC) that
// produces trajectories for the x-ray tube motion.
// X-ray detector setup, generator settings, and filter selection are all done externally.
// In DBT mode this program establishes communication with the motion controller, allows
// to select and download one the three acquisition geometries motion controller (*.pmc) files
// to the PMAC, move the x-ray tube motorized stages to the beginning of the circular arc, and
// initiate a synchronized DBT acquisition scan. After the scan is completed the code
// in the *.pmc program sends the three motorized stages back to their "home" positions to get
// ready for the next acquisition.
// Angular motion of an x-ray tube (swivel arm in clinical systems) here is realzed in a more complex
// fashion: circular arc trajectory is achieved with the two orthogonal linear stages and the rotary table
// with the x-ray tube mounted on top. Such an implementation was due to the existing setup in the
// laboratory. All currently implemented trajectories are of a step-and-shoot kind.
// Analogic Anrad AXS-2430 amorphous Selenium x-ray detector is used for image registration
// in DBT mode. In FFDM mode another detector - Teledyne Dalsa Xineos-2329 can be used. The user
// has an option of choosing between the Anrad and the Xinoes in FFDM regime.
// PMC scripts for Delta Tau PMAC Turbo clipper controller are included in the repository. As of now
// the absolute paths to these motion programs are hardcoded here under 'Acquisition geometry'.
// Motion controller commands '&1b1r' and '&1b2r' tell the PMAC to execute the pieces of PMC script
// that move the motorized stages to the beginning of the circular arc, and to begin
// the DBT scan.

#include <algorithm>
#include <NIDAQmx.h>
#include <stdio.h>
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else

int32      error= 0;
char       errBuff[2048]={'\0'};
float64    pulse_width[1];
TaskHandle taskHandle0= 0;
TaskHandle taskHandle1= 0;
TaskHandle taskHandle2= 0; 

#pragma once
namespace dbt_benchtop
{    
    using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace PCOMMSERVERLib;

	// summary for MyForm1
	
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		public:  PmacDeviceClass pmacdoc;
		int      dwDevice,status;
		bool     bSuccess,bDeviceOpen;
		private: System::Windows::Forms::Label^  label2;
		public:
		private: System::Windows::Forms::ComboBox^  comboBox1;
		public:
		public: delegate void SetText(String^ str);

		public:
		MyForm1(void)
		{
			InitializeComponent();
			PmacDeviceClass^ pmacdoc=gcnew PmacDeviceClass();
			SetAllEvents();
		}

		protected:
	    ~MyForm1()  // clean up any resources being used
		{
			if (components)
			{
				delete components;
			}
		}

		private: System::Windows::Forms::Button^       button1;
		private: System::Windows::Forms::Button^       button3;
		private: System::Windows::Forms::Button^       button4;
		private: System::Windows::Forms::GroupBox^     groupBox1;
		private: System::Windows::Forms::RichTextBox^  richTextBox1;
		private: System::Windows::Forms::Label^        label1;
		private: System::Windows::Forms::TextBox^      textBox1;
		private: System::Windows::Forms::GroupBox^     groupBox2;
		private: System::Windows::Forms::Button^       button5;
		private: System::Windows::Forms::RadioButton^  radioButton2;
		private: System::Windows::Forms::RadioButton^  radioButton1;
		protected:

		private:
		System::ComponentModel::Container ^components;  // required designer variable

		#pragma region Windows Form Designer generated code
		
		// required method for Designer support - do not modify the contents of this method with the code editor
		
		void InitializeComponent(void)
		{
			this->button1=(gcnew System::Windows::Forms::Button());
			this->button3=(gcnew System::Windows::Forms::Button());
			this->button4=(gcnew System::Windows::Forms::Button());
			this->groupBox1=(gcnew System::Windows::Forms::GroupBox());
			this->label2=(gcnew System::Windows::Forms::Label());
			this->comboBox1=(gcnew System::Windows::Forms::ComboBox());
			this->richTextBox1=(gcnew System::Windows::Forms::RichTextBox());
			this->label1=(gcnew System::Windows::Forms::Label());
			this->textBox1=(gcnew System::Windows::Forms::TextBox());
			this->groupBox2=(gcnew System::Windows::Forms::GroupBox());
			this->button5=(gcnew System::Windows::Forms::Button());
			this->radioButton2=(gcnew System::Windows::Forms::RadioButton());
			this->radioButton1=(gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location=System::Drawing::Point(6,21);
			this->button1->Name=L"button1";
			this->button1->Size=System::Drawing::Size(152,27);
			this->button1->TabIndex=0;
			this->button1->Text=L"Open PMAC";
			this->button1->UseVisualStyleBackColor=true;
			this->button1->Click+=gcnew System::EventHandler(this,&MyForm1::button1_Click);
			// 
			// button3
			// 
			this->button3->Location=System::Drawing::Point(6,101);
			this->button3->Name=L"button3";
			this->button3->Size=System::Drawing::Size(152,27);
			this->button3->TabIndex=2;
			this->button3->Text=L"Move to start position";
			this->button3->UseVisualStyleBackColor=true;
			this->button3->Click+=gcnew System::EventHandler(this,&MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location=System::Drawing::Point(6,134);
			this->button4->Name=L"button4";
			this->button4->Size=System::Drawing::Size(152,27);
			this->button4->TabIndex=3;
			this->button4->Text=L"Begin acquisition";
			this->button4->UseVisualStyleBackColor=true;
			this->button4->Click+=gcnew System::EventHandler(this,&MyForm1::button4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location=System::Drawing::Point(12,12);
			this->groupBox1->Name=L"groupBox1";
			this->groupBox1->Size=System::Drawing::Size(430,169);
			this->groupBox1->TabIndex=4;
			this->groupBox1->TabStop=false;
			this->groupBox1->Text=L"DBT";
			// 
			// label2
			// 
			this->label2->AutoSize=true;
			this->label2->Location=System::Drawing::Point(6,51);
			this->label2->Name=L"label2";
			this->label2->Size=System::Drawing::Size(139,17);
			this->label2->TabIndex=9;
			this->label2->Text=L"Acquisition geometry";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled=true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Hologic (15/15)",L"GE (9/25)",L"Siemens (25/46)"
			});
			this->comboBox1->Location=System::Drawing::Point(6,71);
			this->comboBox1->Name=L"comboBox1";
			this->comboBox1->Size=System::Drawing::Size(152,24);
			this->comboBox1->TabIndex=6;
			this->comboBox1->SelectedIndexChanged+=gcnew System::EventHandler(this,&MyForm1::comboBox1_SelectedIndexChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location=System::Drawing::Point(164,38);
			this->richTextBox1->Name=L"richTextBox1";
			this->richTextBox1->Size=System::Drawing::Size(258,123);
			this->richTextBox1->TabIndex=8;
			this->richTextBox1->Text=L"";
			// 
			// label1
			// 
			this->label1->AutoSize=true;
			this->label1->Location=System::Drawing::Point(193,13);
			this->label1->Name=L"label1";
			this->label1->Size=System::Drawing::Size(137,17);
			this->label1->TabIndex=7;
			this->label1->Text=L"\"STATE\" pulse width";
			// 
			// textBox1
			// 
			this->textBox1->Location=System::Drawing::Point(336,10);
			this->textBox1->Name=L"textBox1";
			this->textBox1->Size=System::Drawing::Size(86,22);
			this->textBox1->TabIndex=6;
			//this->textBox1->TextChanged+=gcnew System::EventHandler(this,&MyForm1::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Location=System::Drawing::Point(448,12);
			this->groupBox2->Name=L"groupBox2";
			this->groupBox2->Size=System::Drawing::Size(162,169);
			this->groupBox2->TabIndex=5;
			this->groupBox2->TabStop=false;
			this->groupBox2->Text=L"FFDM";
			// 
			// button5
			// 
			this->button5->Location=System::Drawing::Point(6,91);
			this->button5->Name=L"button5";
			this->button5->Size=System::Drawing::Size(152,27);
			this->button5->TabIndex=2;
			this->button5->Text=L"Acquire image";
			this->button5->UseVisualStyleBackColor=true;
			this->button5->Click+=gcnew System::EventHandler(this,&MyForm1::button5_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize=true;
			this->radioButton2->Location=System::Drawing::Point(6,64);
			this->radioButton2->Name=L"radioButton2";
			this->radioButton2->Size=System::Drawing::Size(108,21);
			this->radioButton2->TabIndex=1;
			this->radioButton2->Text=L"Xineos 2329";
			this->radioButton2->UseVisualStyleBackColor=true;
			this->radioButton2->CheckedChanged+=gcnew System::EventHandler(this,&MyForm1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize=true;
			this->radioButton1->Checked=true;
			this->radioButton1->Location=System::Drawing::Point(6,37);
			this->radioButton1->Name=L"radioButton1";
			this->radioButton1->Size=System::Drawing::Size(135,21);
			this->radioButton1->TabIndex=0;
			this->radioButton1->TabStop=true;
			this->radioButton1->Text=L"Anrad AXS-2430";
			this->radioButton1->UseVisualStyleBackColor=true;
			this->radioButton1->CheckedChanged+=gcnew System::EventHandler(this,&MyForm1::radioButton1_CheckedChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions=System::Drawing::SizeF(8,16);
			this->AutoScaleMode=System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize=System::Drawing::Size(623,191);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name=L"MyForm1";
			this->Text=L"Benchtop user interface";
			this->Load+=gcnew System::EventHandler(this,&MyForm1::MyForm1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
        #pragma endregion
		
		private: void MyForm1::DisplayResponse(String^ str)
		{
			try
			{
				if(this->InvokeRequired)
				{
					SetText^ d=gcnew SetText(this,&MyForm1::DisplayResponse);
					this->Invoke(d, gcnew Object{str});
					d-=d;
					delete d;
				}
				else
				{
					richTextBox1->ScrollToCaret();
					richTextBox1->SelectedText+= str;
					richTextBox1->ScrollToCaret();
				}
			}
			catch(char *str)
			{
				richTextBox1->SelectedText+= *str + "\r\n";
			}
		}

		private: void OnMessage(int device,String ^ Text,bool linefeed)
		{
			DisplayResponse(Text + "\r\n");
			//richTextBox1->AppendText(Text+"\r\n");
		}
		
		private: void MyForm1::SetAllEvents()
		{
			//if(pmacdoc!= 0)
			{
				_IPmacDeviceEvents_MessageEventHandler ^ DMessageEventE=gcnew _IPmacDeviceEvents_MessageEventHandler(this,&MyForm1::OnMessage);
				pmacdoc.Message+=DMessageEventE;
			}
		}
		
		private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			
		}

		//----- 'Open PMAC' button
		
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			pmacdoc.SelectDevice((int)this->Handle,dwDevice,bSuccess);
			if(bSuccess)
			{
				pmacdoc.Open(dwDevice,bDeviceOpen);
				richTextBox1->AppendText("PMAC communication successful\r\n");
			}
			else
			{
				richTextBox1->AppendText("Could not communicate to PMAC\r\n");
			}
		}
		
		//----- 'Motion Program' button

		/*private: System::Void button2_Click(System::Object^  sender,System::EventArgs^  e)
		{
			//----- invokes OpenFileDialog so the user can select a file

			OpenFileDialog ^ openFileDialog1=gcnew OpenFileDialog();
			openFileDialog1->Filter="Motion program files|*.pmc";
			openFileDialog1->Title="Select motion program to download to PMAC";

			String^ filePath="";
			bool    bSuccess;

			//richTextBox1->Clear();
			if(bDeviceOpen)
			{
				if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					filePath=openFileDialog1->FileName;
					//FileInfo *fiInf = new FileInfo(filePath);

					if(filePath != "")
					{
						pmacdoc.Download(dwDevice,filePath,true,true,true,true,bSuccess);
					}
				}
			}
		}*/

		//----- 'Acquisition geometry' dropdown menu

		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender,System::EventArgs^  e)
		{
			String^ filePath="";
			bool bSuccess;

			if(this->comboBox1->SelectedItem== "Hologic (15/15)")
			{
				richTextBox1->AppendText("Hologic trajectory selected\r\n");
				filePath= "C:/Users/makeev/Desktop/ho_snshoot.pmc";
				if(filePath!= "") pmacdoc.Download(dwDevice, filePath, true, true, true, true, bSuccess);
			}

			if(this->comboBox1->SelectedItem== "GE (9/25)")
			{
				richTextBox1->AppendText("GE trajectory selected\r\n");
				filePath="C:/Users/makeev/Desktop/ge_snshoot.pmc";
				if(filePath!= "") pmacdoc.Download(dwDevice, filePath, true, true, true, true, bSuccess);
			}

			if(this->comboBox1->SelectedItem== "Siemens (25/46)")
			{
				richTextBox1->AppendText("Siemens trajectory selected\r\n");
				filePath="C:/Users/makeev/Desktop/si_snshoot.pmc";
				if(filePath!= "") pmacdoc.Download(dwDevice, filePath, true, true, true, true, bSuccess);
			}
		}

		//----- 'Move to start position' button

		private: System::Void button3_Click(System::Object^  sender,System::EventArgs^  e)
		{
			String^ cmd= "&1b1r";  // move x-ray tube to starting position
			String^ rsp= "";
			Int32   status= 0;
			pmacdoc.GetResponseEx(dwDevice, cmd, false, rsp, status);
		}

		//----- 'Begin acquisition' button
		
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//----- Option 1: use digital output (P0.0, pin 52) to activate Anrad PREP signal
			
			DAQmxErrChk(DAQmxCreateTask("", &taskHandle0));
			DAQmxErrChk(DAQmxCreateDOChan(taskHandle0, "Dev1/port0/line0:7", "", DAQmx_Val_ChanForAllLines));
			DAQmxErrChk(DAQmxStartTask(taskHandle0));
			
			//----- Option 2: use counter CTR0 OUT (PFI12, pin 2) to activate Anrad PREP signal
			
			//DAQmxErrChk (DAQmxCreateTask("",&taskHandle0));
			//DAQmxErrChk (DAQmxCreateCOPulseChanTime(taskHandle0,"Dev1/ctr0","",DAQmx_Val_Seconds,DAQmx_Val_Low,0.00,1.00,19.50));
			
			//----- measure Anrad "STATE" signal pulse width using counter CTR2 GATE (PFI1, pin 10)
			
			DAQmxErrChk(DAQmxCreateTask("", &taskHandle1));
			DAQmxErrChk(DAQmxCreateCIPulseWidthChan(taskHandle1, "Dev1/ctr2", "", 0.150, 0.500, DAQmx_Val_Seconds, DAQmx_Val_Falling, ""));
			DAQmxErrChk(DAQmxStartTask(taskHandle1));
			
			//----- x-ray trigger pulses (instead of PMAC toggle pulses) using counter CTR1 OUT (PFI13, pin 40)
			
			//DAQmxErrChk(DAQmxCreateTask("",&taskHandle2));
			//DAQmxErrChk(DAQmxCreateCOPulseChanFreq(taskHandle2,"Dev1/ctr1","",DAQmx_Val_Hz,DAQmx_Val_Low,2.329,0.55401662049861495844875346260388,0.25));  // period of 1,805 ms
			//DAQmxErrChk(DAQmxCfgImplicitTiming(taskHandle2,DAQmx_Val_ContSamps,9));  // generate 9 x-ray trigger pulses for GE Essential DBT geometry
			
			//----- Option 1: activate Anrad PREP signal using digital output
			
			uInt8 data[8]= {1, 0, 0, 0, 0, 0, 0, 0};
			DAQmxErrChk(DAQmxWriteDigitalLines(taskHandle0, 1, 1, 10.0, DAQmx_Val_GroupByChannel, data, NULL, NULL));
			
			//----- Option 2: activate Anrad PREP signal using counter
			
			//DAQmxErrChk (DAQmxStartTask(taskHandle0));
			
			int n_pulses;
			if(this->comboBox1->SelectedItem== "Hologic (15/15)") n_pulses= 18;
			if(this->comboBox1->SelectedItem== "GE (9/25)")       n_pulses= 21;
			if(this->comboBox1->SelectedItem== "Siemens (25/46)") n_pulses= 28;

			//----- repeatedly measure Anrad "STATE" pulse width
			
			int ctr= 1;
			while(ctr <= n_pulses)
			{
				//----- store Anrad "STATE" pulse width in variable 'pulse_width', in ms

			    DAQmxErrChk(DAQmxReadCounterScalarF64(taskHandle1, 10.0, &pulse_width[0], 0));

			    //----- measure "STATE" pulse width

			    if (pulse_width[0] > 0.190 && pulse_width[0] < 0.220)
			    {
			        if(ctr== 1)  // happens only once: first "STATE" pulse with period less than 480 ms
			        {
			            String^ cmd= "&1b2r";  // start x-ray tube motion upon detecting first 210 ms "STATE" pulse
			            String^ rsp= "";
			            Int32   status= 0;
			            pmacdoc.GetResponseEx(dwDevice, cmd, false, rsp, status);
			            textBox1->Text= Convert::ToString(pulse_width[0]);
						textBox1->Refresh();
						
	                    //----- start generating x-ray trigger pulses (to be used instead of PMAC pulses)

		                //DAQmxErrChk(DAQmxStartTask(taskHandle2));
			        }

			        ctr+= 1;
			    }
			}
            
			//----- de-activate Anrad PREP signal when TOMO acquisition sequence is complete

			uInt8 new_data[8]= {0, 0, 0, 0, 0, 0, 0, 0};
			std::copy(new_data, new_data+8, data);
			DAQmxErrChk(DAQmxWriteDigitalLines(taskHandle0, 1, 1, 10.0, DAQmx_Val_GroupByChannel, data, NULL, NULL));

			Error:
			if(DAQmxFailed(error))
				DAQmxGetExtendedErrorInfo(errBuff, 2048);
			if(taskHandle0!= 0)
			{
				DAQmxStopTask(taskHandle0);
				DAQmxClearTask(taskHandle0);
			}
			if(taskHandle1!= 0)
			{
				DAQmxStopTask(taskHandle1);
				DAQmxClearTask(taskHandle1);
			}
			//if(taskHandle2!= 0)
			//{
			//	DAQmxStopTask(taskHandle2);
			//	DAQmxClearTask(taskHandle2);
			//}
	    }

		//----- FFDM: Anrad detector selected	
		
		private: System::Void radioButton1_CheckedChanged(System::Object^  sender,System::EventArgs^  e)
		{
		}

		//----- FFDM: Teledyne detector selected

		private: System::Void radioButton2_CheckedChanged(System::Object^  sender,System::EventArgs^  e)
		{
		}

		//----- FFDM: acquire image

		private: System::Void button5_Click(System::Object^  sender,System::EventArgs^  e)
		{
			DAQmxErrChk(DAQmxCreateTask("", &taskHandle2));
			
			if(this->radioButton1->Checked== 1)
			{	
				richTextBox1->AppendText("FFDM Anrad selected!\r\n");
				richTextBox1->Refresh();

				//----- pulse widths/delays for Anrad AXS-2430 detector operated in a "Contact Context"

				DAQmxErrChk(DAQmxCreateCOPulseChanTime(taskHandle2, "Dev1/ctr0", "", DAQmx_Val_Seconds,DAQmx_Val_Low, 0.00, 1.00, 8.00));
				DAQmxErrChk(DAQmxCreateCOPulseChanTime(taskHandle2, "Dev1/ctr1", "", DAQmx_Val_Seconds,DAQmx_Val_Low, 3.23, 1.00, 1.50));
				DAQmxErrChk(DAQmxStartTask(taskHandle2));
				DAQmxErrChk(DAQmxWaitUntilTaskDone(taskHandle2, 10.0));

				// last three parameters: initial delay, pulse-low time, 1.5 s x-ray trigger pulse-high time (1500-190)= 1.3 s - long enough to have 1000 ms xray exp.)
			}

			if(this->radioButton2->Checked== 1)
			{
				richTextBox1->AppendText("FFDM Xineos selected!\r\n");
				richTextBox1->Refresh();

				//----- pulses widths/delays for Teledyne Dalsa Xineos-2329 detector operated in "Snapshot Extended Exposure" trigger mode

				DAQmxErrChk(DAQmxCreateCOPulseChanTime(taskHandle2, "Dev1/ctr0", "", DAQmx_Val_Seconds, DAQmx_Val_Low, 0.035, 0.500, 1.500));
				DAQmxErrChk(DAQmxCreateCOPulseChanTime(taskHandle2, "Dev1/ctr1", "", DAQmx_Val_Seconds, DAQmx_Val_Low, 0.000, 0.500, 1.500));
				DAQmxErrChk(DAQmxStartTask(taskHandle2));
				DAQmxErrChk(DAQmxWaitUntilTaskDone(taskHandle2,10.0));

				// ctr0: delay detector "trigger in" by 35 ms with respect to "fire xrays" pulse, pulse-low time,  800 ms "trigger in" pulse sent to Xineos; its rising edge will activate 123 ms-long (1x1 binning) sensor reset
				// ctr1: initial delay, pulse low time, 300 ms pulse to fire xrays; xray exposure will occur ~ 190 ms after rising edge 
			}
			
			Error:
			if(DAQmxFailed(error))
				DAQmxGetExtendedErrorInfo(errBuff, 2048);
			if(taskHandle2!= 0)
			{
				DAQmxStopTask(taskHandle2);
				DAQmxClearTask(taskHandle2);
			}

			//myTask.Start();
			//switch1.Enabled=false;

			//----- wait for the task to complete in another thread so the UI
			//does not freeze.
			//ThreadPool.QueueUserWorkItem(new WaitCallback(WaitMethod));
		}
    };
}
