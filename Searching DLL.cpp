// Program C++ untuk mencari element
//C++ Searching Double Linked List

#include <bits/stdc++.h>
using namespace std;

// Struktur simpul dari daftar tertaut ganda
struct Node {

	// Menyimpan nilai data dari sebuah simpul
	int data;

	// penunjuk pointer ke simpul berikutnya
	Node* next;

	// penunjuk pointer ke simpul sebelumnya
	Node* prev;
};

// Berfungsi untuk menyisipkan node pada awal dari Daftar Tertaut Ganda
void push(Node** head_ref, int new_data)
{

	// Alokasikan memori untuk simpul baru
	Node* new_node
		= (Node*)malloc(sizeof(struct Node));

	// Masukkan datanya
	new_node->data = new_data;

	// Karena simpul ditambahkan pada awal, sebelumnya selalu NULL
	new_node->prev = NULL;

	// Tautkan daftar lama ke simpul baru
	new_node->next = (*head_ref);

	// Jika penunjuk ke kepala bukan NULL
	if ((*head_ref) != NULL) {

		// Ubah kepala sebelumnya
		// simpul ke simpul baru
		(*head_ref)->prev = new_node;
	}

	// Pindahkan kepala untuk menunjuk ke simpul baru
	(*head_ref) = new_node;
}

// Fungsi untuk mencari posisi
// bilangan bulat dalam daftar tertaut ganda
int search(Node** head_ref, int x)
{

	// Kepala Node
	Node* temp = *head_ref;

	// Menyimpan posisi bilangan bulat
   // dalam daftar tertaut ganda
	int pos = 0;

	// Lintasi daftar tertaut ganda
	while (temp->data != x
		&& temp->next != NULL) {

		// Perbarui pos
		pos++;

		// Perbarui suhu
		temp = temp->next;
	}

	// Jika bilangan bulat tidak ada dalam daftar tertaut ganda
	if (temp->data != x)
		return -1;

	// Jika bilangan bulat ada di daftar tertaut ganda
	return (pos + 1);
}

// menjalankan kode
int main()
{
	Node* head = NULL;
	int X = 14;

	
	push(&head, 10);
	push(&head, 30);
	push(&head, 11);
	push(&head, 21);
	push(&head, 14);

	cout << "Data ditemukan pada indeks ke-";
	cout << search(&head, X);

	return 0;
}
