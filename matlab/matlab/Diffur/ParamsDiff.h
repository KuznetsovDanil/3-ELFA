#pragma once

namespace matlab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Params1
	/// </summary>
	public ref class Params1 : public System::Windows::Forms::Form
	{
	public:
		Params1(void)
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
		~Params1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBoxA;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBoxB;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBoxX0;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBoxY0;

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBoxS;

	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Button^ button1;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxX0 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxY0 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxS = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
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
			this->groupBox1->Text = L"Параметр a";
			// 
			// textBoxA
			// 
			this->textBoxA->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxA->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxA->Location = System::Drawing::Point(3, 18);
			this->textBoxA->Multiline = true;
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(276, 39);
			this->textBoxA->TabIndex = 0;
			this->textBoxA->Text = L"0,5";
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
			this->textBoxB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->groupBox3->Controls->Add(this->textBoxX0);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(0, 120);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(282, 60);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Параметр x0";
			// 
			// textBoxX0
			// 
			this->textBoxX0->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxX0->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxX0->Location = System::Drawing::Point(3, 18);
			this->textBoxX0->Multiline = true;
			this->textBoxX0->Name = L"textBoxX0";
			this->textBoxX0->Size = System::Drawing::Size(276, 39);
			this->textBoxX0->TabIndex = 0;
			this->textBoxX0->Text = L"1";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxY0);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Location = System::Drawing::Point(0, 180);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(282, 60);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Параметр y0";
			// 
			// textBoxY0
			// 
			this->textBoxY0->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxY0->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxY0->Location = System::Drawing::Point(3, 18);
			this->textBoxY0->Multiline = true;
			this->textBoxY0->Name = L"textBoxY0";
			this->textBoxY0->Size = System::Drawing::Size(276, 39);
			this->textBoxY0->TabIndex = 0;
			this->textBoxY0->Text = L"10";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBoxS);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(0, 240);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(282, 60);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Шаг построения";
			// 
			// textBoxS
			// 
			this->textBoxS->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxS->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxS->Location = System::Drawing::Point(3, 18);
			this->textBoxS->Multiline = true;
			this->textBoxS->Name = L"textBoxS";
			this->textBoxS->Size = System::Drawing::Size(276, 39);
			this->textBoxS->TabIndex = 0;
			this->textBoxS->Text = L"0,01";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->comboBox1);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox6->Location = System::Drawing::Point(0, 300);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(282, 50);
			this->groupBox6->TabIndex = 5;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Диффур";
			// 
			// comboBox1
			// 
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"(-x*x-x*y+y)/x" });
			this->comboBox1->Location = System::Drawing::Point(3, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(276, 24);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"(-x*x-x*y+y)/x";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->comboBox2);
			this->groupBox7->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox7->Location = System::Drawing::Point(0, 350);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(282, 50);
			this->groupBox7->TabIndex = 6;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Константа интегралла [x - x0]";
			// 
			// comboBox2
			// 
			this->comboBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"(y+x)/(e^(-x)*x)" });
			this->comboBox2->Location = System::Drawing::Point(3, 18);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(276, 24);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->Text = L"(y+x)/(e^(-x)*x)";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->comboBox3);
			this->groupBox8->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox8->Location = System::Drawing::Point(0, 400);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(282, 50);
			this->groupBox8->TabIndex = 7;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Интеграл ДУ [x-x0][y-y0]";
			// 
			// comboBox3
			// 
			this->comboBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"c*e^(-x)*x-x" });
			this->comboBox3->Location = System::Drawing::Point(3, 18);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(276, 24);
			this->comboBox3->TabIndex = 0;
			this->comboBox3->Text = L"c*e^(-x)*x-x";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->comboBox4);
			this->groupBox9->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox9->Location = System::Drawing::Point(0, 450);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(282, 50);
			this->groupBox9->TabIndex = 8;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Метод вычисления";
			// 
			// comboBox4
			// 
			this->comboBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Эйлера", L"Предиктор корректор", L"Рюнге Кут 3",
					L"Рюнге Кут 4"
			});
			this->comboBox4->Location = System::Drawing::Point(3, 18);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(276, 24);
			this->comboBox4->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(0, 500);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 86);
			this->button1->TabIndex = 9;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Params1::OK);
			// 
			// Params1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 586);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Params1";
			this->Text = L"Params";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OK(System::Object^, System::EventArgs^);
};
}
