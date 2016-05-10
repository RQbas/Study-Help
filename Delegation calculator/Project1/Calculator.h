#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string>
#include <fstream>  
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		delegation_base *tmp;
	private: System::Windows::Forms::Button^  button2;
	public:
		delegate *t_del;
		departure *t_dep;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;

	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TextBox^  textBox14;
			 


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(394, 303);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Submit and  calculate";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->ForeColor = System::Drawing::Color::Black;
			this->checkBox1->Location = System::Drawing::Point(320, 145);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(139, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Possess Hotel/Motel bill";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(69, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Basic Informations";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(6, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Delegation number";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(124, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Delegate";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(111, 31);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 15);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Exposure data";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(37, 95);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 15);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Name";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(132, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 15);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Surname";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(239, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 15);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Position";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(104, 144);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 15);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Delegation data";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(16, 177);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 15);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Aim of travel";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(124, 177);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 15);
			this->label10->TabIndex = 11;
			this->label10->Text = L"Initial city";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(217, 177);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 15);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Destination city";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(234, 233);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(51, 15);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Distance";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(12, 268);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(88, 15);
			this->label13->TabIndex = 14;
			this->label13->Text = L"Day of departure";
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(132, 268);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(32, 15);
			this->label14->TabIndex = 15;
			this->label14->Text = L"Hour";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(16, 326);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(93, 15);
			this->label15->TabIndex = 16;
			this->label15->Text = L"Day of comeback";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(132, 326);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 15);
			this->label16->TabIndex = 17;
			this->label16->Text = L"Hour";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label17->ForeColor = System::Drawing::Color::Black;
			this->label17->Location = System::Drawing::Point(403, 73);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(114, 15);
			this->label17->TabIndex = 18;
			this->label17->Text = L"Additional informations";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Control;
			this->comboBox1->ForeColor = System::Drawing::Color::Black;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"car", L"bus", L"train", L"motorcycle", L"other" });
			this->comboBox1->Location = System::Drawing::Point(412, 113);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(95, 21);
			this->comboBox1->TabIndex = 20;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label18->ForeColor = System::Drawing::Color::Black;
			this->label18->Location = System::Drawing::Point(415, 95);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(92, 15);
			this->label18->TabIndex = 19;
			this->label18->Text = L"Mode of transport";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 50);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(77, 20);
			this->textBox1->TabIndex = 21;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 114);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(77, 20);
			this->textBox2->TabIndex = 22;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(114, 113);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(77, 20);
			this->textBox3->TabIndex = 23;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(221, 113);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(77, 20);
			this->textBox4->TabIndex = 24;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(16, 195);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(77, 20);
			this->textBox5->TabIndex = 25;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(111, 195);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(77, 20);
			this->textBox6->TabIndex = 26;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(221, 195);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(77, 20);
			this->textBox7->TabIndex = 27;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(221, 251);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(77, 20);
			this->textBox8->TabIndex = 28;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(16, 291);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(77, 20);
			this->textBox9->TabIndex = 29;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(114, 291);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(77, 20);
			this->textBox10->TabIndex = 30;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(16, 353);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(77, 20);
			this->textBox11->TabIndex = 31;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(111, 353);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(77, 20);
			this->textBox12->TabIndex = 32;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(114, 51);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(123, 20);
			this->dateTimePicker1->TabIndex = 34;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(412, 202);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(143, 13);
			this->label20->TabIndex = 36;
			this->label20->Text = L"Daily accomodation payment";
			this->label20->Visible = false;
			this->label20->Click += gcnew System::EventHandler(this, &MyForm::label20_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::Color::Transparent;
			this->checkBox2->ForeColor = System::Drawing::Color::Black;
			this->checkBox2->Location = System::Drawing::Point(475, 144);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(166, 17);
			this->checkBox2->TabIndex = 37;
			this->checkBox2->Text = L"Don\'t possess Hotel/Motel bill";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(448, 218);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(77, 20);
			this->textBox14->TabIndex = 38;
			this->textBox14->Visible = false;
			this->textBox14->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox14_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(412, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 25);
			this->button2->TabIndex = 39;
			this->button2->Text = L"Accept bill";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(696, 385);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

	public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		tmp = new delegation_base; //pointer to class

		//Delegation number
			String ^txtb = textBox1->Text;
				tmp->SysStrToStr(tmp->delegation_number, txtb);
		//Aim of travel
			txtb = textBox5->Text;
				tmp->SysStrToStr(tmp->aim, txtb);
		//Data
			String ^date = dateTimePicker1->Value.ToString();
				tmp->SysStrToStr(tmp->f_data, date);
		//Payment
			txtb = textBox14->Text;
				tmp->SysStrToStr(tmp->daily_pay, txtb);

		t_dep = new departure;
		
		
		//initial city
			txtb = textBox6->Text;
				t_dep->SysStrToStr(t_dep->initial_city, txtb);
		//destination city
			txtb = textBox7->Text;
				t_dep->SysStrToStr(t_dep->destination_city, txtb);
		//day of departure
			txtb = textBox9->Text;
				t_dep->SysStrToStr(t_dep->day_departure, txtb);
		//distance
			txtb = textBox8->Text;
				t_dep->SysStrToStr(t_dep->distance, txtb);

		//dep hour
			txtb = textBox10->Text;
				t_dep->SysStrToStr(t_dep->dhour, txtb);
		//day of comeback
			txtb = textBox11->Text;
				t_dep->SysStrToStr(t_dep->day_comeback, txtb);
		//day of departure
			txtb = textBox12->Text;
				t_dep->SysStrToStr(t_dep->chour, txtb);

		t_del = new delegate;

		//name
			txtb = textBox2->Text;
				t_del->SysStrToStr(t_del->name, txtb);
		//surname
			txtb = textBox3->Text;
				t_del->SysStrToStr(t_del->surname, txtb);
		//position
			txtb = textBox4->Text;
				t_del->SysStrToStr(t_del->position, txtb);



		//Delegation
		String ^txtb1 = gcnew String(tmp->delegation_number.c_str());
		String ^txtdt = gcnew String(tmp->f_data.c_str());
		String ^txtb5 = gcnew String(tmp->aim.c_str());
		//Delegate
		String ^txtb2 = gcnew String(t_del->name.c_str());
		String ^txtb3 = gcnew String(t_del->surname.c_str());
		String ^txtb4 = gcnew String(t_del->position.c_str());
		//Departure
		String ^txtb6 = gcnew String(t_dep->initial_city.c_str());
		String ^txtb7 = gcnew String(t_dep->destination_city.c_str());
		String ^txtb9 = gcnew String(t_dep->day_departure.c_str());
		String ^txtb8 = gcnew String(t_dep->distance.c_str());
		String ^txtb10 = gcnew String(t_dep->dhour.c_str());
		String ^txtb11 = gcnew String(t_dep->day_comeback.c_str());
		String ^txtb12 = gcnew String(t_dep->chour.c_str());

		//CONVERSIONS
		t_dep->StrToF(t_dep->distance, t_dep->f_distance);
		t_dep->DateConv(t_dep->day_departure, t_dep->dday);
		t_dep->DateConv(t_dep->day_comeback, t_dep->cday);
		t_dep->HourConv(t_dep->dhour, t_dep->f_dhour);
		t_dep->HourConv(t_dep->chour, t_dep->f_chour);
		//Calculations
		//Distance&&MODE
		String ^ checker = this->comboBox1->GetItemText(this->comboBox1->SelectedItem);
		tmp->SysStrToStr(tmp->mtrans, checker);
		float transportcost;

		if (tmp->mtrans == "car")
		{
			transportcost = t_dep->f_distance*0.675;
		}

		if (tmp->mtrans == "motorcycle")
		{
			transportcost = t_dep->f_distance*0.234;
		}

		if (tmp->mtrans == "train")
		{
			transportcost = 0.2*t_dep->diet;
		}

		if (tmp->mtrans == "bus")
		{
			transportcost = 0.2*t_dep->diet;
		}

		if (tmp->mtrans == "other")
		{
			transportcost = 0.1*t_dep->diet + 5;
		}
		//Diet Hours
		int diet=0;
				//Comeback
		if (t_dep->hourdiff_c(t_dep->f_chour) >= 480)
		{
			diet = tmp->diet;
		}
				//Departure
		if (t_dep->hourdiff_d(t_dep->f_dhour) >= 480 && t_dep->hourdiff_d(t_dep->f_dhour)<=720) //if it's between 8 hour and 12 hours
		{
			diet =diet+(tmp->diet)/2;
		}
		else
		{
			if (t_dep->hourdiff_d(t_dep->f_dhour) > 720)
			{
				diet+=tmp->diet;
			}
			else
			{
			}

		}
		//Diet days
		int diff = t_dep->daydiff(t_dep->dday, t_dep->cday);
		//LumpSum
		int lump;
		if (checkBox2->Checked)
		{
			lump = ((3 * tmp->diet) / 2)*(diff+1);
		}
		if (checkBox1->Checked)
		{
			tmp->StrToF(tmp->daily_pay, tmp->dailypay);
				lump = tmp->dailypay*(diff+1);
		}
		//RESULT
	
		float res;
		diet = diff*tmp->diet + diet;
		res = diet+transportcost+lump;
		MessageBox::Show("Data: \n" 
			"Delegation number:  " + txtb1 + "\n"
			"Date: " + txtdt + "\n"
			"Name: " + txtb2 + "\n"
			"Surname: " + txtb3 + "\n"
			"Position: " + txtb4 + "\n"
			"Aim of Travel: " + txtb5 + "\n"
			"Initial city: " + txtb6 + "\n"
			"Destination city: " + txtb7+ "\n"
			"Day of departure: "+ txtb9+ "\n"
			"Day of comeback: "+txtb11 + "\n"
			"Result: " + res+"\n"
			"\t Transport:" +transportcost +"\n"
			"\t Diet: "+ diet+"("+ (diff+2)+"days)\n"
			"\t Lump sum: " +lump +"\n"
			,

								
								"Result", MessageBoxButtons::OK, MessageBoxIcon::None);	

		//CREATING RESULT FILE.TXT

		ofstream outfile("RESULT.txt");
		outfile << "Data: \nDelegation number:  " << tmp->delegation_number << "\n" <<
			"Date: " << tmp->f_data << "\n" <<
			"Name: " << t_del->name << "\n" <<
			"Surname: " << t_del->surname << "\n" <<
			"Position: " << t_del->position << "\n"<<
			"Aim of Travel: " <<tmp->aim<< "\n"<<
			"Initial city: " <<t_dep->initial_city<< "\n"<<
			"Destination city: " <<t_dep->destination_city<< "\n"<<
			"Day of departure: " <<t_dep->day_departure<< "\n"<<
			"Day of comeback: " <<t_dep->day_comeback<< "\n"<<
			"Result: " <<res<< "\n"<<
			"\t Transport:"<< transportcost << "\n"
			"\t Diet: " << diet << "(" << (diff + 2)<< "days)\n"
			"\t Lump sum: "<< lump << "\n";
		outfile.close();
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label20_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox14_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	if(checkBox1->Checked)
	{
		textBox14->Visible = 1;
		label20->Visible = 1;
	}
}
};

}
#endif