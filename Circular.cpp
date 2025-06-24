/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * Projek ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section operations
 * project ini memiliki beberapa oprasi antara lain:
 * 1.Insert
 * 2.Delete
 * display
 * 
 * @section Cara penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1.en queue 
 * 2.de queue 
 * 3.display 
 * 4.3xit
 * @author Profil 
 * - nama : {Ahmad Galang Pamungkas} 
 * - nim  : {20240140080} 
 * - kelas: {B}
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright {Ahmad Galang Pamungkas}@umy.ac.id(C) 2025
 * 
 */
 

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk oprasi lengkap queus
 * 
 */
class Queues{
private:
    int FRONT;///< variable private front untuk menyimpan posisi depan antrian
    int REAR;///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5///< variable private max untuk menyimpan ukuran maksimum antrian
    int queue_array[5];///< variable private queue_array untuk menyimpan elmen antrian
    

public:
 /**
  * @brief construct a new Quees object
  * set default queues null
  * with front = -1 and rear = -1
 */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukan data dalam antrian
     * data di masukan dalam variabel queue_array
    */

    void insert()
    {
        // int num;///< variabel num untuk menyimpan nilai
        cout << "Enter a Number :";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; // 1.a
            return;                       // 1.b
        }
        // 2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0;  // 2.b
        }
        else
        {
            // jika REAR berada di posisi terakhitr array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk mengahpus data dalam antrian
     * data dihapukan dari dalam variabele queue_array
    */

    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deeted from the queue is : " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di poisi terakhir, kembali ke awal  array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief method untuk menampulkan data dalam antrian
     * data di tampilkan yang berada dalam variabele queue_array
    */

    void display()
    {
        int FRONT_position = FRONT;///< variable front_position untuk posisi element
        int REAR_position = REAR;///< variable rear_position untuk menandakan posisi element trahir

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElement in te queue are...\n";

        // jika FRONT_position <= REAR_position, terasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
        }
        FRONT_position = 0;
    }
};
/**
 * @brief methodnutama untuk menjalankan program
 * 
 * @return int
*/
int main()
{
    Queues q;//< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variabele ch untuk menyiapkan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2.Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter yor choice (1-4)" << endl;
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invaid option!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
    return 0;
};