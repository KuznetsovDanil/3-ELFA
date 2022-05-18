#pragma once

namespace MKWMAP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ î÷èñòèòüÃğàôèêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ äàííûåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RASCHET;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåçóëüòàòToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïåğâûéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^ âòîğîéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^ òğåòèéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULTR;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RASCHET = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èñòèòüÃğàôèêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äàííûåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåçóëüòàòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïåğâûéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->âòîğîéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT2 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->òğåòèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT3 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULTR = (gcnew System::Windows::Forms::ToolStripTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(0, 28);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			series1->Color = System::Drawing::Color::Gold;
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::White;
			series1->Name = L"APROCSIMATION";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"FUNCTION";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(608, 350);
			this->chart->TabIndex = 1;
			this->chart->Text = L"chart1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ìåíşToolStripMenuItem,
					this->äàííûåToolStripMenuItem, this->ğåçóëüòàòToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(608, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->RASCHET,
					this->î÷èñòèòüÃğàôèêToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// RASCHET
			// 
			this->RASCHET->Name = L"RASCHET";
			this->RASCHET->Size = System::Drawing::Size(249, 26);
			this->RASCHET->Text = L"Ğàñ÷èòàòü è ïîñòğîèòü";
			this->RASCHET->Click += gcnew System::EventHandler(this, &MyForm::RASCHET_Click);
			// 
			// î÷èñòèòüÃğàôèêToolStripMenuItem
			// 
			this->î÷èñòèòüÃğàôèêToolStripMenuItem->Name = L"î÷èñòèòüÃğàôèêToolStripMenuItem";
			this->î÷èñòèòüÃğàôèêToolStripMenuItem->Size = System::Drawing::Size(249, 26);
			this->î÷èñòèòüÃğàôèêToolStripMenuItem->Text = L"Î÷èñòèòü ãğàôèê";
			this->î÷èñòèòüÃğàôèêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ClearOut);
			// 
			// äàííûåToolStripMenuItem
			// 
			this->äàííûåToolStripMenuItem->Name = L"äàííûåToolStripMenuItem";
			this->äàííûåToolStripMenuItem->Size = System::Drawing::Size(78, 24);
			this->äàííûåToolStripMenuItem->Text = L"Äàííûå";
			this->äàííûåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Open_Param_Window);
			// 
			// ğåçóëüòàòToolStripMenuItem
			// 
			this->ğåçóëüòàòToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->ïåğâûéToolStripMenuItem,
					this->labRESULT1, this->toolStripSeparator2, this->âòîğîéToolStripMenuItem, this->labRESULT2, this->toolStripSeparator3, this->òğåòèéToolStripMenuItem,
					this->labRESULT3, this->toolStripSeparator1, this->toolStripMenuItem1, this->labRESULTR
			});
			this->ğåçóëüòàòToolStripMenuItem->Name = L"ğåçóëüòàòToolStripMenuItem";
			this->ğåçóëüòàòToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->ğåçóëüòàòToolStripMenuItem->Size = System::Drawing::Size(89, 24);
			this->ğåçóëüòàòToolStripMenuItem->Text = L"Ğåçóëüòàò";
			// 
			// ïåğâûéToolStripMenuItem
			// 
			this->ïåğâûéToolStripMenuItem->Name = L"ïåğâûéToolStripMenuItem";
			this->ïåğâûéToolStripMenuItem->Size = System::Drawing::Size(230, 26);
			this->ïåğâûéToolStripMenuItem->Text = L"Ïåğâûé ñïîñîá";
			// 
			// labRESULT1
			// 
			this->labRESULT1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labRESULT1->Name = L"labRESULT1";
			this->labRESULT1->Size = System::Drawing::Size(100, 27);
			this->labRESULT1->Text = L"Ğåçóëüòàò";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(227, 6);
			// 
			// âòîğîéToolStripMenuItem
			// 
			this->âòîğîéToolStripMenuItem->Name = L"âòîğîéToolStripMenuItem";
			this->âòîğîéToolStripMenuItem->Size = System::Drawing::Size(230, 26);
			this->âòîğîéToolStripMenuItem->Text = L"Âòîğîé ñïîñîá";
			// 
			// labRESULT2
			// 
			this->labRESULT2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labRESULT2->Name = L"labRESULT2";
			this->labRESULT2->Size = System::Drawing::Size(100, 27);
			this->labRESULT2->Text = L"Ğåçóëüòàò";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(227, 6);
			// 
			// òğåòèéToolStripMenuItem
			// 
			this->òğåòèéToolStripMenuItem->Name = L"òğåòèéToolStripMenuItem";
			this->òğåòèéToolStripMenuItem->Size = System::Drawing::Size(230, 26);
			this->òğåòèéToolStripMenuItem->Text = L"Òğåòèé ñïîñîá";
			// 
			// labRESULT3
			// 
			this->labRESULT3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labRESULT3->Name = L"labRESULT3";
			this->labRESULT3->Size = System::Drawing::Size(100, 27);
			this->labRESULT3->Text = L"Ğåçóëüòàò";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(227, 6);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(230, 26);
			this->toolStripMenuItem1->Text = L"Èñòèííîå çíà÷åíèå";
			// 
			// labRESULTR
			// 
			this->labRESULTR->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labRESULTR->Name = L"labRESULTR";
			this->labRESULTR->Size = System::Drawing::Size(100, 27);
			this->labRESULTR->Text = L"Ğåçóëüòàò";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(608, 378);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: static double a, b, s, n;
		public: static double x, y;
		public: static int num;

		private: System::Void RASCHET_Click(System::Object^ sender, System::EventArgs^ e);
		private: void OUTGraph_Click();
		private: System::Void ClearOut(System::Object^ sender, System::EventArgs^ e);
		private: void DeffParams();
		private: void ClearOut();
		private: void Open_Param_Window(System::Object^ sender, System::EventArgs^ e);
};
}