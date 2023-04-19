#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

struct Patient {
    string name;
    int age;
    string gender;
};

struct Doctor {
    string name;
    string specialization;
};

struct Appointment {
    Doctor doctor;
    Patient patient;
    string date;
    string time;
};

vector<Appointment> appointments;
void addAppointment(Doctor doctor, Patient patient, string date,string time) {
    ofstream fout;
    fout.open("C:\\Users\\сулпакэ\\OneDrive\\Рабочий стол\\c++ esepter\\doctor\\patients_base\\"+patient.name+".txt",ofstream::app);
    if (!fout.is_open()) {
        cout << "Error"<<endl;
    }
    else {
        fout << "Dear " << patient.name << " " << "Dr." << doctor.name << " will be waiting for you on " << date << " at " << time << " for appointment"<<endl;
        fout << "Patient data-base:\n" << "Gender: " << patient.gender << "\nage: " << patient.age<<"\nDoctor specialization:"<<doctor.specialization<<"\nDoctor name: "<<doctor.name<<endl;
        Appointment appointment = { doctor, patient, date };
        appointments.push_back(appointment);
        cout << "Appointment added successfully!" << endl;
        cout << "Dear " << patient.name << " " << "Dr." << doctor.name << " will be waiting for you on " << date << " at " << time << " for appointment" << endl;
    }
    fout.close();
}
    
int main() {

    Patient patient;
    Doctor doctor;

    int i, j, z;
    int del;
    string date[5] = { "10.04.2023","11.04.2023","12.04.2023","13.04.2023","14.04.2023" };
    string time[5] = { "10:00","11:00","12:00","13:00","14:00" };
    cout << "Enter your name :";
    getline(cin, patient.name);
    cout << "1)Registration \n2)see/cancel to appointment  \n Choose:";
    cin >> del;
    while (del > 2 || del < 1) {
        cout << "Enter again :";
        cin >> del;
    }
    if (del == 1) {
        cout << "Hi, to adding appointment please answer to next questions:" << endl;
        cout << "";
        cout << "choise you gender 1) Male or 2)Female :";
        cin >> z;
        while (z > 2 || z < 1) {
            if (z > 2 || z < 1) {
                cout << "Enter again : 1)Male nemese 2)Female :";
                cin >> z;
            }
        }
        switch (z) {
        case 1:patient.gender = "Male "; break;
        case 2:patient.gender = "Female "; break;
        }
        cout << "Enter your age :";
        cin >> patient.age;
        while (patient.age < 0) {
            cout << "Enter your normal age : ";
            cin >> patient.age;
        }
        cout << "Choose specialization : \n 1) therapist \n 2) cardiologist \n 3) traumatologist \n 4) ophthalmologist \n 5) lore" << endl;
        int num; cin >> num;
        while (num > 5 || num < 1) {
            cout << "Choose again ";
            cin >> num;

        }
        switch (num)
        {
        case 1:doctor.specialization = "therapist";
            if (patient.age > 18)
            {
                doctor.name = "John Smith";
            }
            else doctor.name = "Sara Watson";
            break;
        case 2:doctor.specialization = "cardio";
            if (patient.age > 18)
            {
                doctor.name = "Kira Kosarin";
            }
            else doctor.name = "Kostya Bykov";
            break;
        case 3:
            doctor.specialization = "traumalog";
            if (patient.age > 18)
            {
                doctor.name = "Bekzhan Askhatov";
            }
            else doctor.name = "Qaraqat Zhumabaeva";
            break;
        case 4:doctor.specialization = "ophtalmolog";
            if (patient.age > 18)
            {
                doctor.name = "Aijan Rahimova";
            }
            else doctor.name = "Aruzhan Zhumadieva";
            break;
        case 5:doctor.specialization = "lore";
            if (patient.age > 18)
            {
                doctor.name = "Arlan Karimov";
            }
            else doctor.name = "Raushan Damirova";
            break;

        default:cout << "ondai vrach zhok";
            break;
        }
        cout << "Choose date of appointment :\n" << "1) " << date[0] << "\n" << "2) " << date[1] << "\n" << "3) " << date[2] << "\n" << "4) " << date[3] << "\n" << "5)" << date[4] << endl;
        cin >> i;
        while (i > 5 || i < 1) {
            cout << "Enter again,no such date";
            cin >> i;
        }
        cout << "Choose time of appointment :\n" << "1) " << time[0] << "\n" << "2) " << time[1] << "\n" << "3) " << time[2] << "\n" << "4) " << time[3] << "\n" << "5)" << time[4] << endl;
        cin >> j;
        while (j > 5 || j < 1) {
            cout << "Enter again,no such time";
            cin >> j;

        }

        addAppointment(doctor, patient, date[i], time[j]);
    }
    if (del == 2) {
        ifstream fin;
        fin.open("C:\\Users\\сулпакэ\\OneDrive\\Рабочий стол\\c++ esepter\\doctor\\patients_base\\" + patient.name + ".txt");
        if (!fin.is_open()) 
        {
            cout << "You are not registered";
        }
        else
        {
            int udal;
            cout << "You registrated: "<<endl;
            char ch;
            while (fin.get(ch)) {
                cout << ch;
            }
            cout << "\nYou cancel from appointment? \n1)NO \n2)Yes: ";
            cin >> udal;
            if (udal == 1) {
              while (fin.get(ch)) {
                    cout << ch;
              }
                fin.close();
            }
            if (udal == 2) {
                cout << "Sizdin derekteriniz zhoyuldy";
                cout << "\n\n\n\n\n\n";
                }
        }
    }
}
  
