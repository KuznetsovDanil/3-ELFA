#pragma once

namespace matlab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GraphIntegr
	/// </summary>
	public ref class GraphIntegr : public System::Windows::Forms::Form
	{
	public:
		GraphIntegr(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GraphIntegr()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ результатToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ первыйСпособToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT1;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ второйСпособToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT2;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^ третийСпособToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT3;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^ истинноеЗначениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULTR;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->результатToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->первыйСпособToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->второйСпособToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT2 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->третийСпособToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULT3 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->истинноеЗначениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labRESULTR = (gcnew System::Windows::Forms::ToolStripTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(0, 28);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->Name = L"Aprocsimation";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"Function";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(920, 544);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"Graphics";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->результатToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(920, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// результатToolStripMenuItem
			// 
			this->результатToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->первыйСпособToolStripMenuItem,
					this->labRESULT1, this->toolStripSeparator1, this->второйСпособToolStripMenuItem, this->labRESULT2, this->toolStripSeparator2,
					this->третийСпособToolStripMenuItem, this->labRESULT3, this->toolStripSeparator3, this->истинноеЗначениеToolStripMenuItem, this->labRESULTR
			});
			this->результатToolStripMenuItem->Name = L"результатToolStripMenuItem";
			this->результатToolStripMenuItem->Size = System::Drawing::Size(89, 24);
			this->результатToolStripMenuItem->Text = L"Результат";
			// 
			// первыйСпособToolStripMenuItem
			// 
			this->первыйСпособToolStripMenuItem->Name = L"первыйСпособToolStripMenuItem";
			this->первыйСпособToolStripMenuItem->Size = System::Drawing::Size(574, 26);
			this->первыйСпособToolStripMenuItem->Text = L"Первый способ";
			// 
			// labRESULT1
			// 
			this->labRESULT1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labRESULT1->Name = L"labRESULT1";
			this->labRESULT1->ReadOnly = true;
			this->labRESULT1->Size = System::Drawing::Size(500, 27);
			this->labRESULT1->Text = L"Результат";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(571, 6);
			// 
			// второйСпособToolStripMenuItem
			// 
			this->второйСпособToolStripMenuItem->Name = L"второйСпособToolStripMenuItem";
			this->второйСпособToolStripMenuItem->Size = System::Drawing::Size(574, 26);
			this->второйСпособToolStripMenuItem->Text = L"Второй способ";
			// 
			// labRESULT2
			// 
			this->labRESULT2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labRESULT2->Name = L"labRESULT2";
			this->labRESULT2->ReadOnly = true;
			this->labRESULT2->Size = System::Drawing::Size(500, 27);
			this->labRESULT2->Text = L"Результат";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(571, 6);
			// 
			// третийСпособToolStripMenuItem
			// 
			this->третийСпособToolStripMenuItem->Name = L"третийСпособToolStripMenuItem";
			this->третийСпособToolStripMenuItem->Size = System::Drawing::Size(574, 26);
			this->третийСпособToolStripMenuItem->Text = L"Третий способ";
			// 
			// labRESULT3
			// 
			this->labRESULT3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labRESULT3->Name = L"labRESULT3";
			this->labRESULT3->ReadOnly = true;
			this->labRESULT3->Size = System::Drawing::Size(500, 27);
			this->labRESULT3->Text = L"Результат";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(571, 6);
			// 
			// истинноеЗначениеToolStripMenuItem
			// 
			this->истинноеЗначениеToolStripMenuItem->Name = L"истинноеЗначениеToolStripMenuItem";
			this->истинноеЗначениеToolStripMenuItem->Size = System::Drawing::Size(574, 26);
			this->истинноеЗначениеToolStripMenuItem->Text = L"Истинное значение";
			// 
			// labRESULTR
			// 
			this->labRESULTR->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labRESULTR->Name = L"labRESULTR";
			this->labRESULTR->ReadOnly = true;
			this->labRESULTR->Size = System::Drawing::Size(500, 27);
			this->labRESULTR->Text = L"Результат";
			// 
			// GraphIntegr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 572);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GraphIntegr";
			this->Text = L"GraphIntegr";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//public: double a, b, s, n;
		//public: double x, y;
		//public: int num;

		public: System::Void Расчёт(System::Object^, System::EventArgs^, double, double, double, double, double);
};
}
