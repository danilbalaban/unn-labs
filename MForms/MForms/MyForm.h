#pragma once
#include <string>
#include "MyForm.h"
#include "TSet.h"

namespace MForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	TSet A;
	TSet B;

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
		std::string& Convert_String_to_string(String^ s, std::string& os); //конвертируем System::string^ в std::string

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
	private: System::Windows::Forms::Button^ buttonOr;
	private: System::Windows::Forms::Button^ buttonNotA;

	protected:

	protected:

	protected:


	private: System::Windows::Forms::Button^ buttonAnd;

	private: System::Windows::Forms::TextBox^ textBoxSetA;
	private: System::Windows::Forms::TextBox^ textBoxSetB;
	private: System::Windows::Forms::TextBox^ textBoxResult;












	private: System::Windows::Forms::Label^ labelUniverse;



	private: System::Windows::Forms::Label^ labelResult;

	private: System::Windows::Forms::Label^ labelA;
	private: System::Windows::Forms::Label^ labelB;





	private: System::Windows::Forms::Button^ buttonNotB;


	private: System::Windows::Forms::TextBox^ textBoxUniverse;



	private:
		int u_size = 0;
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
			this->labelUniverse = (gcnew System::Windows::Forms::Label());
			this->textBoxUniverse = (gcnew System::Windows::Forms::TextBox());
			this->labelA = (gcnew System::Windows::Forms::Label());
			this->textBoxSetA = (gcnew System::Windows::Forms::TextBox());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->buttonOr = (gcnew System::Windows::Forms::Button());
			this->buttonAnd = (gcnew System::Windows::Forms::Button());
			this->buttonNotA = (gcnew System::Windows::Forms::Button());
			this->buttonNotB = (gcnew System::Windows::Forms::Button());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->textBoxSetB = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// labelUniverse
			// 
			this->labelUniverse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUniverse->Location = System::Drawing::Point(392, 34);
			this->labelUniverse->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->labelUniverse->Name = L"labelUniverse";
			this->labelUniverse->Size = System::Drawing::Size(103, 36);
			this->labelUniverse->TabIndex = 6;
			this->labelUniverse->Text = L"Универс:";
			// 
			// textBoxUniverse
			// 
			this->textBoxUniverse->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxUniverse->Location = System::Drawing::Point(505, 34);
			this->textBoxUniverse->Margin = System::Windows::Forms::Padding(5);
			this->textBoxUniverse->Name = L"textBoxUniverse";
			this->textBoxUniverse->Size = System::Drawing::Size(181, 30);
			this->textBoxUniverse->TabIndex = 1;
			this->textBoxUniverse->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxUniverse_TextChanged);
			// 
			// labelA
			// 
			this->labelA->AutoSize = true;
			this->labelA->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->labelA->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelA->Location = System::Drawing::Point(13, 108);
			this->labelA->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->labelA->Name = L"labelA";
			this->labelA->Size = System::Drawing::Size(132, 23);
			this->labelA->TabIndex = 2;
			this->labelA->Text = L"Множество А:";
			// 
			// textBoxSetA
			// 
			this->textBoxSetA->Location = System::Drawing::Point(155, 108);
			this->textBoxSetA->Margin = System::Windows::Forms::Padding(5);
			this->textBoxSetA->Name = L"textBoxSetA";
			this->textBoxSetA->Size = System::Drawing::Size(531, 30);
			this->textBoxSetA->TabIndex = 3;
			this->textBoxSetA->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxSetA_TextChanged);
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->labelB->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelB->Location = System::Drawing::Point(13, 172);
			this->labelB->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(131, 23);
			this->labelB->TabIndex = 4;
			this->labelB->Text = L"Множество В:";
			// 
			// buttonOr
			// 
			this->buttonOr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOr->Location = System::Drawing::Point(341, 245);
			this->buttonOr->Name = L"buttonOr";
			this->buttonOr->Size = System::Drawing::Size(346, 30);
			this->buttonOr->TabIndex = 7;
			this->buttonOr->Text = L"Объединение";
			this->buttonOr->UseVisualStyleBackColor = true;
			this->buttonOr->Click += gcnew System::EventHandler(this, &MyForm::buttonOr_Click);
			// 
			// buttonAnd
			// 
			this->buttonAnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAnd->Location = System::Drawing::Point(341, 299);
			this->buttonAnd->Name = L"buttonAnd";
			this->buttonAnd->Size = System::Drawing::Size(346, 30);
			this->buttonAnd->TabIndex = 8;
			this->buttonAnd->Text = L"Пересечение";
			this->buttonAnd->UseVisualStyleBackColor = true;
			this->buttonAnd->Click += gcnew System::EventHandler(this, &MyForm::buttonAnd_Click);
			// 
			// buttonNotA
			// 
			this->buttonNotA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNotA->Location = System::Drawing::Point(12, 245);
			this->buttonNotA->Name = L"buttonNotA";
			this->buttonNotA->Size = System::Drawing::Size(139, 84);
			this->buttonNotA->TabIndex = 9;
			this->buttonNotA->Text = L"Отрицание А";
			this->buttonNotA->UseVisualStyleBackColor = true;
			this->buttonNotA->Click += gcnew System::EventHandler(this, &MyForm::buttonNotA_Click);
			// 
			// buttonNotB
			// 
			this->buttonNotB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNotB->Location = System::Drawing::Point(182, 245);
			this->buttonNotB->Name = L"buttonNotB";
			this->buttonNotB->Size = System::Drawing::Size(139, 84);
			this->buttonNotB->TabIndex = 10;
			this->buttonNotB->Text = L"Отрицание В";
			this->buttonNotB->UseVisualStyleBackColor = true;
			this->buttonNotB->Click += gcnew System::EventHandler(this, &MyForm::buttonNotB_Click);
			// 
			// textBoxResult
			// 
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(17, 363);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(670, 30);
			this->textBoxResult->TabIndex = 11;
			this->textBoxResult->Visible = false;
			// 
			// labelResult
			// 
			this->labelResult->Location = System::Drawing::Point(0, 0);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(100, 23);
			this->labelResult->TabIndex = 0;
			// 
			// textBoxSetB
			// 
			this->textBoxSetB->Location = System::Drawing::Point(155, 172);
			this->textBoxSetB->Margin = System::Windows::Forms::Padding(5);
			this->textBoxSetB->Name = L"textBoxSetB";
			this->textBoxSetB->Size = System::Drawing::Size(532, 30);
			this->textBoxSetB->TabIndex = 5;
			this->textBoxSetB->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxSetB_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(697, 466);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->buttonNotB);
			this->Controls->Add(this->buttonNotA);
			this->Controls->Add(this->buttonAnd);
			this->Controls->Add(this->buttonOr);
			this->Controls->Add(this->textBoxSetB);
			this->Controls->Add(this->labelB);
			this->Controls->Add(this->textBoxSetA);
			this->Controls->Add(this->labelA);
			this->Controls->Add(this->textBoxUniverse);
			this->Controls->Add(this->labelUniverse);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Location = System::Drawing::Point(-2, 9);
			this->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void ChangeVisible(bool vis) {
		this->textBoxSetA->Visible = vis;
		this->labelA->Visible = vis;

		this->labelB->Visible = vis;
		this->textBoxSetB->Visible = vis;

		this->buttonAnd->Visible = vis;
		this->buttonOr->Visible = vis;

		this->textBoxResult->Visible = vis;
		this->labelResult->Visible = vis;

		// ~ A
		this->buttonNotA->Visible = vis;

		// ~ B
		this->buttonNotB->Visible = vis;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxUniverse_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxUniverse_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);

    private: System::Void textBoxSetA_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxA_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxSetB_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxB_TextChanged(System::Object^ sender, System::EventArgs^ e);

    private: System::Void buttonOr_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonAnd_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonNotA_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonNotB_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void textBoxSetA_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar)) && e->KeyChar != ' ') {
			if (this->textBoxSetA->Text[0] != ' ') {
				e->Handled = true;
			}
		}
	}
    private: System::Void textBoxSetB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar)) && e->KeyChar != ' ') {
			if (this->textBoxSetB->Text[0] != ' ') {
				e->Handled = true;
			}
		}
	}
};
}