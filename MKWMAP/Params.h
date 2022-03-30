#pragma once

namespace MKWMAP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Params
	/// </summary>
	public ref class Params : public System::Windows::Forms::Form
	{
	public:
		Params(void)
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
		~Params()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;
	private: System::Windows::Forms::TextBox^ Stepper;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBoxN;
	private: System::Windows::Forms::Button^ button1;


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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Stepper = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxN = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxA);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 46);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметр а";
			// 
			// textBoxA
			// 
			this->textBoxA->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxA->Location = System::Drawing::Point(3, 18);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(250, 22);
			this->textBoxA->TabIndex = 0;
			this->textBoxA->Text = L"-10";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxB);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point(0, 46);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 46);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметр b";
			// 
			// textBoxB
			// 
			this->textBoxB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxB->Location = System::Drawing::Point(3, 18);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(250, 22);
			this->textBoxB->TabIndex = 0;
			this->textBoxB->Text = L"10";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->Stepper);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(0, 92);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(256, 46);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Шаг";
			// 
			// Stepper
			// 
			this->Stepper->Dock = System::Windows::Forms::DockStyle::Top;
			this->Stepper->Location = System::Drawing::Point(3, 18);
			this->Stepper->Name = L"Stepper";
			this->Stepper->Size = System::Drawing::Size(250, 22);
			this->Stepper->TabIndex = 0;
			this->Stepper->Text = L"0,05";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox1);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Location = System::Drawing::Point(0, 138);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(256, 46);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Интеграл от";
			// 
			// comboBox1
			// 
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" });
			this->comboBox1->Location = System::Drawing::Point(3, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(250, 24);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"1";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBoxN);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(0, 184);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(256, 46);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Количество разбиений";
			// 
			// textBoxN
			// 
			this->textBoxN->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxN->Location = System::Drawing::Point(3, 18);
			this->textBoxN->Name = L"textBoxN";
			this->textBoxN->Size = System::Drawing::Size(250, 22);
			this->textBoxN->TabIndex = 0;
			this->textBoxN->Text = L"1000";
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(0, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(256, 64);
			this->button1->TabIndex = 5;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Params::Translate);
			// 
			// Params
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 294);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Params";
			this->Text = L"Params";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		public: static double a, b, s, n;

		private: void Translate(System::Object^ sender, System::EventArgs^ e);
		private: bool Check(System::Windows::Forms::TextBox^, System::Windows::Forms::TextBox^, System::Windows::Forms::TextBox^, System::Windows::Forms::TextBox^);
		private: bool MKWCHECK(System::Windows::Forms::TextBox^);
		private: void DeffParams();
};
}
