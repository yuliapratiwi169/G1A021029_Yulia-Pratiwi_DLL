
//C++ Insertion Double Linked List
#include <bits/stdc++.h>
using namespace std;

// sebuah linked list node
class Node
{
	public:
	int data;
	Node* next;
	Node* prev;
};

/* Diberi referensi (pointer to pointer)
ke kepala daftar
dan sebuah int, menyisipkan simpul baru pada
depan daftar. */
void push(Node** head_ref, int new_data)
{
	/* 1. alokasikan node */
	Node* new_node = new Node();

	/* 2. letakkan didalam data */
	new_node->data = new_data;

	/* 3. Jadikan simpul baru berikutnya sebagai kepala
    dan sebelumnya sebagai NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. ubah simpul kepala sebelumnya ke simpul baru */
	if  ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. gerakkan kepala untuk menunjuk ke simpul baru */
	(*head_ref) = new_node;
}

/* Diberikan sebuah simpul sebagai prev_node, masukkan
simpul baru setelah simpul yang diberikan */
void insertAfter(Node* prev_node, int new_data)
{
	/*1.periksa apakah prev_node yang diberikan adalah NULL */
	if (prev_node == NULL)
	{
		cout<<"simpul sebelumnya yang diberikan tidak boleh NULL";
		return;
	}

	/* 2. alokasikan simpul baru */
	Node* new_node = new Node();

	/* 3. letakkan didalam data */
	new_node->data = new_data;

	/* 4. Jadikan berikutnya dari simpul baru sebagai berikutnya dari prev_node */
	new_node->next = prev_node->next;

	/* 5. Jadikan prev_node berikutnya sebagai new_node */
	prev_node->next = new_node;

	/* 6. Jadikan prev_node seperti sebelumnya dari new_node */
	new_node->prev = prev_node;

	/* 7. Ubah sebelumnya dari simpul baru_node berikutnya */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Diberi referensi (pointer to pointer) ke kepala
dari DLL dan int, menambahkan simpul baru di akhir */
void append(Node** head_ref, int new_data)
{
	/* 1. alokasikan node */
	Node* new_node = new Node();

	Node* last = *head_ref; /* used in step 5*/

	/* 2. letakkan didalam data */
	new_node->data = new_data;

	/* 3. Node baru ini akan menjadi node terakhir, jadi
          buat selanjutnya sebagai NULL*/
	new_node->next = NULL;

	/* 4. Jika Linked List kosong, maka buat yang baru
          simpul sebagai kepala */
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. pilihan lain, melintasi sampai simpul terakhir */
	while (last->next != NULL)
		last = last->next;

	/* 6. Ubah berikutnya dari simpul terakhir */
	last->next = new_node;

	/* 7. Jadikan simpul terakhir sebagai simpul baru sebelumnya */
	new_node->prev = last;

	return;
}

// Fungsi ini mencetak konten dari
// daftar tertaut mulai dari simpul yang diberikan
void printList(Node* node)
{
	Node* last;
	cout<<"\nUrutan Data dari Terkecil \n";
	while (node != NULL)
	{
		cout<<" "<<node->data<<" ";
		last = node;
		node = node->next;
	}

	cout<<"\nUrutan Data dari Terbesar \n";
	while (last != NULL)
	{
		cout<<" "<<last->data<<" ";
		last = last->prev;
	}
}

/* Jalankan program untuk menguji fungsi diatas*/
int main()
{
	/* Mulailah dengan daftar kosong */
	Node* head = NULL;
	
	append(&head, 5);
	
	push(&head, 9);
	
	push(&head, 13);
	
	append(&head, 3);
	
	cout << "DLL yang dibuat adalah: ";
	printList(head);

	return 0;
}
