#pragma once

namespace MKWMAP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OUTGraph;


	private: System::Windows::Forms::ToolStripMenuItem^ очиститьГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ данныеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ параметрАToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ textBoxA;


	private: System::Windows::Forms::ToolStripMenuItem^ параметрBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ textBoxB;
	private: System::Windows::Forms::ToolStripMenuItem^ textBoxI;







	private: System::Windows::Forms::ToolStripMenuItem^ способВычесленияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ textBoxN;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ шагГрафикаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ Stepper;
	private: System::Windows::Forms::ToolStripTextBox^ labRESULT;



	private: System::Windows::Forms::ToolStripMenuItem^ RASCHET;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;












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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OUTGraph = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RASCHET = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->данныеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->параметрАToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxA = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->параметрBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxB = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->способВычесленияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxN = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->textBoxI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->шагГрафикаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Stepper = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->labRESULT = (gcnew System::Windows::Forms::ToolStripTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea3);
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend3->Name = L"Legend1";
			this->chart->Legends->Add(legend3);
			this->chart->Location = System::Drawing::Point(0, 31);
			this->chart->Name = L"chart";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series5->Color = System::Drawing::Color::Gold;
			series5->Legend = L"Legend1";
			series5->MarkerColor = System::Drawing::Color::White;
			series5->Name = L"Series2";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Legend = L"Legend1";
			series6->Name = L"Series1";
			this->chart->Series->Add(series5);
			this->chart->Series->Add(series6);
			this->chart->Size = System::Drawing::Size(608, 347);
			this->chart->TabIndex = 1;
			this->chart->Text = L"chart1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->менюToolStripMenuItem,
					this->данныеToolStripMenuItem, this->labRESULT
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(608, 31);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->OUTGraph,
					this->очиститьГрафикToolStripMenuItem, this->RASCHET
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(65, 27);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// OUTGraph
			// 
			this->OUTGraph->Name = L"OUTGraph";
			this->OUTGraph->Size = System::Drawing::Size(219, 26);
			this->OUTGraph->Text = L"Построить график";
			this->OUTGraph->Click += gcnew System::EventHandler(this, &MyForm::OUTGraph_Click);
			// 
			// очиститьГрафикToolStripMenuItem
			// 
			this->очиститьГрафикToolStripMenuItem->Name = L"очиститьГрафикToolStripMenuItem";
			this->очиститьГрафикToolStripMenuItem->Size = System::Drawing::Size(219, 26);
			this->очиститьГрафикToolStripMenuItem->Text = L"Очистить график";
			this->очиститьГрафикToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ClearOut);
			// 
			// RASCHET
			// 
			this->RASCHET->Name = L"RASCHET";
			this->RASCHET->Size = System::Drawing::Size(219, 26);
			this->RASCHET->Text = L"Расчитать";
			this->RASCHET->Click += gcnew System::EventHandler(this, &MyForm::RASCHET_Click);
			// 
			// данныеToolStripMenuItem
			// 
			this->данныеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->параметрАToolStripMenuItem,
					this->параметрBToolStripMenuItem, this->способВычесленияToolStripMenuItem, this->textBoxI, this->toolStripSeparator1, this->шагГрафикаToolStripMenuItem
			});
			this->данныеToolStripMenuItem->Name = L"данныеToolStripMenuItem";
			this->данныеToolStripMenuItem->Size = System::Drawing::Size(78, 27);
			this->данныеToolStripMenuItem->Text = L"Данные";
			// 
			// параметрАToolStripMenuItem
			// 
			this->параметрАToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->textBoxA });
			this->параметрАToolStripMenuItem->Name = L"параметрАToolStripMenuItem";
			this->параметрАToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->параметрАToolStripMenuItem->Text = L"Параметр а";
			// 
			// textBoxA
			// 
			this->textBoxA->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(100, 27);
			this->textBoxA->Text = L"-10";
			this->textBoxA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			// 
			// параметрBToolStripMenuItem
			// 
			this->параметрBToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->textBoxB });
			this->параметрBToolStripMenuItem->Name = L"параметрBToolStripMenuItem";
			this->параметрBToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->параметрBToolStripMenuItem->Text = L"Параметр b";
			// 
			// textBoxB
			// 
			this->textBoxB->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(100, 27);
			this->textBoxB->Text = L"10";
			this->textBoxB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			// 
			// способВычесленияToolStripMenuItem
			// 
			this->способВычесленияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->textBoxN });
			this->способВычесленияToolStripMenuItem->Name = L"способВычесленияToolStripMenuItem";
			this->способВычесленияToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->способВычесленияToolStripMenuItem->Text = L"Параметр n";
			// 
			// textBoxN
			// 
			this->textBoxN->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->textBoxN->Name = L"textBoxN";
			this->textBoxN->Size = System::Drawing::Size(100, 27);
			this->textBoxN->Text = L"1";
			this->textBoxN->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			// 
			// textBoxI
			// 
			this->textBoxI->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripTextBox1 });
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(252, 26);
			this->textBoxI->Text = L"Вычеслить интеграл от";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 27);
			this->toolStripTextBox1->Text = L"1";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(249, 6);
			// 
			// шагГрафикаToolStripMenuItem
			// 
			this->шагГрафикаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Stepper });
			this->шагГрафикаToolStripMenuItem->Name = L"шагГрафикаToolStripMenuItem";
			this->шагГрафикаToolStripMenuItem->Size = System::Drawing::Size(252, 26);
			this->шагГрафикаToolStripMenuItem->Text = L"Шаг графика";
			// 
			// Stepper
			// 
			this->Stepper->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Stepper->Name = L"Stepper";
			this->Stepper->Size = System::Drawing::Size(100, 27);
			this->Stepper->Text = L"0,5";
			this->Stepper->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			// 
			// labRESULT
			// 
			this->labRESULT->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labRESULT->Name = L"labRESULT";
			this->labRESULT->Size = System::Drawing::Size(100, 27);
			this->labRESULT->Text = L"Результат";
			this->labRESULT->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			this->labRESULT->Click += gcnew System::EventHandler(this, &MyForm::ClearOut);
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
		private: double a, b, s;
		private: double x, y;

		private: System::Void RASCHET_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OUTGraph_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ClearOut(System::Object^ sender, System::EventArgs^ e);
		private: System::Void textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		private: bool MKWCHECK(System::Windows::Forms::ToolStripTextBox^);
		private: bool MKWCHECK(System::Windows::Forms::ToolStripTextBox^, bool);
		private: long double MKWFUNC(System::Windows::Forms::ToolStripTextBox^, long double);
		private: long double MKWFUNC(System::Windows::Forms::ToolStripTextBox^, long double, int&);
		private: long double MKWpow(System::Windows::Forms::ToolStripTextBox^, long double, int&);
		private: long double MKWMAP::MyForm::MKWZP(System::Windows::Forms::ToolStripTextBox^, int&);
		private: long double MKWMAP::MyForm::MKWQsi(System::Windows::Forms::ToolStripTextBox^, long double, long double, int&);
		private: long double MKWMAP::MyForm::MKWSQB(System::Windows::Forms::ToolStripTextBox^, long double, int&, long double);
		private: long double MKWMAP::MyForm::MKWIntg(System::Windows::Forms::ToolStripTextBox^, double, double, double, double);
		private: void MKWMAP::MyForm::MKWER();
		private: void DeffParams();
		private: void ClearOut();
};
}