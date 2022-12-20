#include "MyForm.h"
#include "TSet.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;


[STAThreadAttribute]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MForms::MyForm form;
    Application::Run(% form);

    return 0;
}

std::string& MForms::MyForm::Convert_String_to_string(String^ s, std::string& os)
{
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    return os;
}

System::Void MForms::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MForms::MyForm::textBoxUniverse_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->textBoxUniverse->Text != "")
    {
        ChangeVisible(true);

        u_size = Convert::ToInt32(textBoxUniverse->Text);
    }
    else
        ChangeVisible(false);
}

System::Void MForms::MyForm::textBoxSetA_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MForms::MyForm::textBoxA_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MForms::MyForm::textBoxUniverse_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar))/* && e->KeyChar != '.'*/) {
        e->Handled = true;
    }
}

System::Void MForms::MyForm::textBoxSetB_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MForms::MyForm::textBoxB_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MForms::MyForm::buttonOr_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->textBoxResult->Text = "";

    if ((this->textBoxSetB->Text != "") && (this->textBoxSetA->Text != ""))
    {
        TSet A(u_size);
        TSet B(u_size);


        for (int i = 0; i < this->textBoxSetA->Text->Split(' ')->Length; ++i)
        {
            A.Add(Convert::ToInt32(this->textBoxSetA->Text->Split(' ')[i]));
            if ((textBoxSetA->Text->Length) % 2 == 0)
                this->textBoxSetA->Text += Convert::ToString(0);
        }
        this->textBoxSetA->Text = gcnew String(A.TSetToString().c_str());


        for (int i = 0; i < this->textBoxSetB->Text->Split(' ')->Length; ++i)
        {
            B.Add(Convert::ToInt32(this->textBoxSetB->Text->Split(' ')[i]));
            if ((textBoxSetB->Text->Length) % 2 == 0)
                this->textBoxSetB->Text += Convert::ToString(0);
        }
        this->textBoxSetB->Text = gcnew String(B.TSetToString().c_str());

        this->textBoxResult->Text = gcnew String((A | B).TSetToString().c_str());
    }
}

System::Void MForms::MyForm::buttonAnd_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->textBoxResult->Text = "";

    if ((this->textBoxSetB->Text != "") && (this->textBoxSetA->Text != ""))
    {
        TSet A(u_size);
        TSet B(u_size);

        string tmp;

        Convert_String_to_string(this->textBoxSetA->Text, tmp);
        if (tmp[tmp.length() - 1] == ' ')
            tmp += "0";

        this->textBoxSetA->Text = gcnew String(tmp.c_str());

        for (int i = 0; i < this->textBoxSetA->Text->Split(' ')->Length; ++i)
        {
            A.Add(Convert::ToInt32(this->textBoxSetA->Text->Split(' ')[i]));
        }

        this->textBoxSetA->Text = gcnew String(A.TSetToString().c_str());

        Convert_String_to_string(this->textBoxSetB->Text, tmp);
        if (tmp[tmp.length() - 1] == ' ')
            tmp += "0";

        this->textBoxSetB->Text = gcnew String(tmp.c_str());

        for (int i = 0; i < this->textBoxSetB->Text->Split(' ')->Length; ++i)
        {
            B.Add(Convert::ToInt32(this->textBoxSetB->Text->Split(' ')[i]));
        }

        this->textBoxSetB->Text = gcnew String(B.TSetToString().c_str());

        this->textBoxResult->Text = gcnew String((A & B).TSetToString().c_str());
    }
}

System::Void MForms::MyForm::buttonNotA_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->textBoxResult->Text = "";

    if (this->textBoxSetA->Text != "")
    {
        TSet A(u_size);

        string tmp;

        Convert_String_to_string(this->textBoxSetA->Text, tmp);
        if (tmp[tmp.length() - 1] == ' ')
            tmp += "0";

        this->textBoxSetA->Text = gcnew String(tmp.c_str());

        for (int i = 0; i < this->textBoxSetA->Text->Split(' ')->Length; ++i)
        {
            A.Add(Convert::ToInt32(this->textBoxSetA->Text->Split(' ')[i]));
        }

        this->textBoxSetA->Text = gcnew String(A.TSetToString().c_str());

        this->textBoxResult->Text = gcnew String((~A).TSetToString().c_str());
    }
}

System::Void MForms::MyForm::buttonNotB_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->textBoxResult->Text = "";

    if (this->textBoxSetB->Text != "")
    {
        TSet B(u_size);

        string tmp;

        Convert_String_to_string(this->textBoxSetB->Text, tmp);
        if (tmp[tmp.length() - 1] == ' ')
            tmp += "0";

        this->textBoxSetB->Text = gcnew String(tmp.c_str());

        for (int i = 0; i < this->textBoxSetB->Text->Split(' ')->Length; ++i)
        {
            B.Add(Convert::ToInt32(this->textBoxSetB->Text->Split(' ')[i]));
        }

        this->textBoxSetB->Text = gcnew String(B.TSetToString().c_str());

        this->textBoxResult->Text = gcnew String((~B).TSetToString().c_str());
    }
}
