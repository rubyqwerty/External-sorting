#include "pch.h"
#include "Form1.h"


System::Void ExternalSorting::Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	dataGridView1->RowCount = 5;
	dataGridView1->Columns[0]->Width = 100;
	for (int i = 1; i < 6; ++i)
		dataGridView1->Columns[i]->Width = 100;
	dataGridView1->Rows[0]->Cells[1]->Value = "Простое 2ф";
	dataGridView1->Rows[1]->Cells[1]->Value = "Простое 1ф";
	dataGridView1->Rows[2]->Cells[1]->Value = "Естественное 2ф";
	dataGridView1->Rows[3]->Cells[1]->Value = "Естественное 1ф";
	dataGridView1->Rows[4]->Cells[1]->Value = "Поглощение";
	dataGridView1->Rows[0]->Cells[0]->Value = false;
	dataGridView1->Rows[1]->Cells[0]->Value = false;
	dataGridView1->Rows[2]->Cells[0]->Value = false;
	dataGridView1->Rows[3]->Cells[0]->Value = false;
	dataGridView1->Rows[4]->Cells[0]->Value = false;
	for (int i = 0; i < 5; ++i)
		dataGridView1->Rows[i]->Height = 30;
}

void ExternalSorting::Form1::Clear()
{
	for (int i = 0; i < 5; ++i)
		for (int j = 2; j < 5; ++j)
			dataGridView1->Rows[i]->Cells[j]->Value = "";
	for (int j = 0; j < 5; ++j)
		dataGridView1->Rows[j]->Cells[5]->Value = false;
}

System::Void ExternalSorting::Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Clear();
	vc A1, A2, A3, A4, A5;
	int Size = (int)numericUpDown1->Value;
	Sorting::CreateArray(Size,A1, &A2, &A3, &A4, &A5);
	A5.push_back((double)A5.size() * (double)numericUpDown2->Value / (double)100);
	ShowResult(0, A1, Sorting::ExternalMergeSort2F);
	ShowResult(1, A2, Sorting::ExternalMergeSort1F);
	ShowResult(2, A3, Sorting::ExternalNaturalMergingSort1f);
	ShowResult(3, A4, Sorting::ExternalNaturalMergingSort2f);
	ShowResult(4, A5, Sorting::AbsorbingSort);
}

void ExternalSorting::Form1::ShowResult(int number, vc& a, specifications (*Sort)(vc&))
{
	if (dataGridView1->Rows[number]->Cells[0]->Value->ToString() == "True") {
		specifications s = Sort(a);
		dataGridView1->Rows[number]->Cells[2]->Value = s.comparisons;
		dataGridView1->Rows[number]->Cells[3]->Value = s.assignments;
		dataGridView1->Rows[number]->Cells[4]->Value = s.time;
		dataGridView1->Rows[number]->Cells[5]->Value = Sorting::IsSorted(a);
	}
}


