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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ labRESULT;


	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Button^ OUTGraph;
	private: System::Windows::Forms::Button^ RASCHET;


	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBoxGetInt;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ Stepper;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBoxB;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::ProgressBar^ progressBar1;



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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->labRESULT = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->OUTGraph = (gcnew System::Windows::Forms::Button());
			this->RASCHET = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxGetInt = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->Stepper = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->progressBar1);
			this->groupBox1->Controls->Add(this->groupBox7);
			this->groupBox1->Controls->Add(this->groupBox6);
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(232, 485);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры";
			// 
			// progressBar1
			// 
			this->progressBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->progressBar1->Location = System::Drawing::Point(3, 234);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(226, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->labRESULT);
			this->groupBox7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox7->Location = System::Drawing::Point(3, 257);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(226, 51);
			this->groupBox7->TabIndex = 5;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Результат";
			// 
			// labRESULT
			// 
			this->labRESULT->AutoSize = true;
			this->labRESULT->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labRESULT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labRESULT->Location = System::Drawing::Point(3, 18);
			this->labRESULT->Name = L"labRESULT";
			this->labRESULT->Size = System::Drawing::Size(89, 25);
			this->labRESULT->TabIndex = 0;
			this->labRESULT->Text = L"No result";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->OUTGraph);
			this->groupBox6->Controls->Add(this->RASCHET);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox6->Location = System::Drawing::Point(3, 308);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(226, 174);
			this->groupBox6->TabIndex = 4;
			this->groupBox6->TabStop = false;
			// 
			// OUTGraph
			// 
			this->OUTGraph->Dock = System::Windows::Forms::DockStyle::Fill;
			this->OUTGraph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OUTGraph->Location = System::Drawing::Point(3, 79);
			this->OUTGraph->Name = L"OUTGraph";
			this->OUTGraph->Size = System::Drawing::Size(220, 92);
			this->OUTGraph->TabIndex = 1;
			this->OUTGraph->Text = L"Построить график";
			this->OUTGraph->UseVisualStyleBackColor = true;
			this->OUTGraph->Click += gcnew System::EventHandler(this, &MyForm::OUTGraph_Click);
			// 
			// RASCHET
			// 
			this->RASCHET->Dock = System::Windows::Forms::DockStyle::Top;
			this->RASCHET->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RASCHET->Location = System::Drawing::Point(3, 18);
			this->RASCHET->Name = L"RASCHET";
			this->RASCHET->Size = System::Drawing::Size(220, 61);
			this->RASCHET->TabIndex = 0;
			this->RASCHET->Text = L"Расчитать";
			this->RASCHET->UseVisualStyleBackColor = true;
			this->RASCHET->Click += gcnew System::EventHandler(this, &MyForm::RASCHET_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBoxGetInt);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBox5->Location = System::Drawing::Point(3, 154);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(226, 49);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Интеграл от";
			// 
			// textBoxGetInt
			// 
			this->textBoxGetInt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxGetInt->Location = System::Drawing::Point(3, 18);
			this->textBoxGetInt->Name = L"textBoxGetInt";
			this->textBoxGetInt->Size = System::Drawing::Size(220, 22);
			this->textBoxGetInt->TabIndex = 0;
			this->textBoxGetInt->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxGetInt_KeyPress);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->Stepper);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(3, 108);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(226, 46);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Шаг";
			// 
			// Stepper
			// 
			this->Stepper->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Stepper->Location = System::Drawing::Point(3, 18);
			this->Stepper->Name = L"Stepper";
			this->Stepper->Size = System::Drawing::Size(220, 22);
			this->Stepper->TabIndex = 0;
			this->Stepper->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Stepper_KeyPress);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBoxB);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(3, 62);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(226, 46);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Параметр b";
			// 
			// textBoxB
			// 
			this->textBoxB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxB->Location = System::Drawing::Point(3, 18);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(220, 22);
			this->textBoxB->TabIndex = 0;
			this->textBoxB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxB_KeyPress);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxA);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(3, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(226, 44);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметр а";
			// 
			// textBoxA
			// 
			this->textBoxA->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxA->Location = System::Drawing::Point(3, 18);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(220, 22);
			this->textBoxA->TabIndex = 0;
			this->textBoxA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxA_KeyPress);
			// 
			// chart
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea2);
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chart->Legends->Add(legend2);
			this->chart->Location = System::Drawing::Point(232, 0);
			this->chart->Name = L"chart";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series4->Legend = L"Legend1";
			series4->Name = L"Series2";
			this->chart->Series->Add(series3);
			this->chart->Series->Add(series4);
			this->chart->Size = System::Drawing::Size(748, 485);
			this->chart->TabIndex = 1;
			this->chart->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 485);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: double a, b, s;
		private: double x, y;

		private: System::Void RASCHET_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OUTGraph_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void textBoxA_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		private: System::Void textBoxB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		private: System::Void Stepper_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		private: System::Void textBoxGetInt_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
		private: bool MKWCHECK(System::Windows::Forms::TextBox^);
		private: bool MKWCHECK(System::Windows::Forms::TextBox^, bool);
		private: long double MKWFUNC(System::Windows::Forms::TextBox^, long double);
		private: long double MKWFUNC(System::Windows::Forms::TextBox^, long double, int&);
		private: long double MKWpow(System::Windows::Forms::TextBox^, long double, int&);
		private: void DeffParams();
		private: void ClearOut();
};
}
