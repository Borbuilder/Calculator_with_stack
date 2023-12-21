#pragma once
//#define DllExport  __declspec(dllexport)
//#define DllImport  __declspec(dllimport)
#include<string>
#include<msclr\marshal_cppstd.h>
#include "../FwrdList_Stack/TLCalc.h"


	namespace Calculator {

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
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Button^ button2;

		protected:

		private:
			/// <summary>
			/// Обязательная переменная конструктора.
			/// </summary>
			System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Требуемый метод для поддержки конструктора — не изменяйте 
			/// содержимое этого метода с помощью редактора кода.
			/// </summary>
			void InitializeComponent(void)
			{
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// button1
				// 
				this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->button1->Font = (gcnew System::Drawing::Font(L"Playbill", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button1->ForeColor = System::Drawing::Color::White;
				this->button1->Location = System::Drawing::Point(443, 0);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(76, 38);
				this->button1->TabIndex = 0;
				this->button1->Text = L"Закрыть\r\n";
				this->button1->UseVisualStyleBackColor = false;
				this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				// 
				// textBox1
				// 
				this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->textBox1->Location = System::Drawing::Point(12, 80);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(264, 26);
				this->textBox1->TabIndex = 1;
				this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label1->ForeColor = System::Drawing::Color::Black;
				this->label1->Location = System::Drawing::Point(294, 80);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(22, 22);
				this->label1->TabIndex = 2;
				this->label1->Text = L"=";
				this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				this->label1->UseWaitCursor = true;
				this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->ForeColor = System::Drawing::Color::Black;
				this->label2->Location = System::Drawing::Point(333, 80);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(0, 25);
				this->label2->TabIndex = 3;
				this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
				// 
				// button2
				// 
				this->button2->Font = (gcnew System::Drawing::Font(L"Playbill", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button2->ForeColor = System::Drawing::Color::Black;
				this->button2->Location = System::Drawing::Point(12, 12);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(120, 37);
				this->button2->TabIndex = 4;
				this->button2->Text = L"Вычислить";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(520, 190);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->button1);
				this->ForeColor = System::Drawing::Color::White;
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			//Закрыть окно
			this->Close();
		}

		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			//Вычисление
			try
			{
				std::string infix;
				infix = msclr::interop::marshal_as<std::string>(textBox1->Text); //Конвертирование String^ в std::string
				TLCalc calculator(infix);
				double result = calculator.CalculateNoPostfix();

				label2->Text = Convert::ToString(result);
			}
			catch (const std::exception& ex)
			{
				label2->Text = "Error";
			}
		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		};
	};


