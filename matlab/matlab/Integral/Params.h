#pragma once

namespace matlab {

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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBoxA;
	protected:

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBoxB;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ Stepper;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox5;



	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::ComboBox^ methodBox;


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
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->methodBox = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxA);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(282, 60);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметр а";
			// 
			// textBoxA
			// 
			this->textBoxA->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxA->Location = System::Drawing::Point(3, 18);
			this->textBoxA->Multiline = true;
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(276, 39);
			this->textBoxA->TabIndex = 0;
			this->textBoxA->Text = L"-10";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxB);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point(0, 60);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(282, 60);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметр b";
			// 
			// textBoxB
			// 
			this->textBoxB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxB->Location = System::Drawing::Point(3, 18);
			this->textBoxB->Multiline = true;
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(276, 39);
			this->textBoxB->TabIndex = 0;
			this->textBoxB->Text = L"10";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->Stepper);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(0, 120);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(282, 60);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Шаг построения";
			// 
			// Stepper
			// 
			this->Stepper->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Stepper->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Stepper->Location = System::Drawing::Point(3, 18);
			this->Stepper->Multiline = true;
			this->Stepper->Name = L"Stepper";
			this->Stepper->Size = System::Drawing::Size(276, 39);
			this->Stepper->TabIndex = 0;
			this->Stepper->Text = L"0,01";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox1);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Location = System::Drawing::Point(0, 180);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(282, 51);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Интегралл от";
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"(2*x+1)*e^(-x)", L"sin(x)+cos(x)", L"x^4-x^2+4",
					L"(2*x^3+1)^4*x^2", L"(1 + sin(x))^3*cos(x)*x", L"(x+3)/(x^2-5*x+6)", L"3/x^2", L"x^2*ln(x)"
			});
			this->comboBox1->Location = System::Drawing::Point(3, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(276, 24);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"sin(x)";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->comboBox2);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(0, 231);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(282, 48);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Проинтегрированная функция";
			// 
			// comboBox2
			// 
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"-(2*b+3)*e^(-b)-(-(2*a+3)*e^(-a))", L"(-cos(b)+sin(b))-(-cos(a)+sin(a))",
					L"b^5/5-b^3/3+4*b-(a^5/5-a^3/3+4*a)", L"((2*b^3+1)^5)-((2*a^3+1)^5)", L"(((1+sin(b))^4)/4)-(((1+sin(a))^4)/4)", L"-5/(b-2)+6/(b-3)-(-5/(a-2)+6/(a-3))",
					L"-3/b-(-3/a)", L"(b^3)/3*ln(b)-(b^3)/9-(a^3)/3*ln(a)-(a^3)/9"
			});
			this->comboBox2->Location = System::Drawing::Point(3, 18);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(276, 24);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->Text = L"-cos(b)+cos(a)";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->methodBox);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox6->Location = System::Drawing::Point(0, 279);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(282, 52);
			this->groupBox6->TabIndex = 6;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"График метода";
			// 
			// methodBox
			// 
			this->methodBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->methodBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->methodBox->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->methodBox->FormattingEnabled = true;
			this->methodBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Треугольник", L"Трапецевидный", L"Симпсона" });
			this->methodBox->Location = System::Drawing::Point(3, 18);
			this->methodBox->Name = L"methodBox";
			this->methodBox->Size = System::Drawing::Size(276, 30);
			this->methodBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(0, 331);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 82);
			this->button1->TabIndex = 7;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Params::OK);
			// 
			// Params
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 413);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Params";
			this->Text = L"Params";
			this->Enter += gcnew System::EventHandler(this, &Params::OK);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void OK(System::Object^, System::EventArgs^);
	private: bool MKWCHECK(System::Windows::Forms::TextBox^);
	private: bool MKWCHECK(System::Windows::Forms::ComboBox^);
	private: bool Check(System::Windows::Forms::TextBox^,
						System::Windows::Forms::TextBox^,
						System::Windows::Forms::TextBox^,
						System::Windows::Forms::ComboBox^,
						double&, int&, double&, double&);
};
}
