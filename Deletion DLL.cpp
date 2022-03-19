// Program C++ untuk menghapus node dari
// Daftar Tertaut Ganda
// C++ Deletion Double Linked List
#include <bits/stdc++.h>
using namespace std;

/* simpul dari daftar tertaut ganda */
class Node
{
	public:
	int data;
	Node* next;
	Node* prev;
};

/* Berfungsi untuk menghapus node pada Double Linked List.
head_ref --> penunjuk ke penunjuk simpul kepala.
del --> pointer ke node yang akan dihapus. */
void deleteNode(Node** head_ref, Node* del)
{
	/* kasus dasar */
	if (*head_ref == NULL || del == NULL)
		return;

	/* Jika simpul yang akan dihapus adalah simpul kepala */
	if (*head_ref == del)
		*head_ref = del->next;

	/* Ubah berikutnya hanya jika simpul menjadi
    dihapus BUKAN simpul terakhir */
	if (del->next != NULL)
		del->next->prev = del->prev;

	/* Ubah prev hanya jika node menjadi
    dihapus BUKAN simpul pertama */
	if (del->prev != NULL)
		del->prev->next = del->next;

	/* Akhirnya, bebaskan memori yang ditempati oleh del*/
	free(del);
	return;
}

/* FUNGSI UTILITAS */
/* Berfungsi untuk menyisipkan node pada
awal dari Daftar Tertaut Ganda */
void push(Node** head_ref, int new_data)
{
	/* alokasikan node */
	Node* new_node = new Node();

	/* letakkan didalam data */
	new_node->data = new_data;

	/* skarena kita menambahkan di awal,
    sebelumnya selalu NULL */
	new_node->prev = NULL;

	/* tautkan daftar lama dari simpul baru */
	new_node->next = (*head_ref);

	/* ubah simpul kepala sebelumnya ke simpul baru */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* pindahkan data yang menjadi kepala untuk menunjuk ke simpul baru */
	(*head_ref) = new_node;
}

/* Berfungsi untuk mencetak node dalam daftar tertaut ganda yang diberikan
Fungsi ini sama dengan printList() dari daftar tertaut tunggal */
void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* menjalankan kode */
int main()
{
	/* Mulailah dengan daftar kosong */
	Node* head = NULL;

	
	push(&head, 6);
	push(&head, 2);
	push(&head, 11);
	push(&head, 1);
	push(&head, 9);
	push(&head, 5);
	

	cout << "Data Awal : ";
	printList(head);

	/* hapus node dari daftar tertaut ganda */
	deleteNode(&head, head); /*hapus node pertama*/
	deleteNode(&head, head->next); /*hapus node tengah*/
	deleteNode(&head, head->next); /*hapus node terakhir*/

	
	cout << "\nDaftar Data yang Tersisa : ";
	printList(head);

	return 0;
}

