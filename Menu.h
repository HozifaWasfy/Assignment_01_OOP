#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
class Menu{
public:
    Menu() : m1(0,0), m2(0,0) {}
    void Start(){
    int option = 0;
        do {
            cout << "----------------" << endl;
            cout << "#0: Exit" << endl;
            cout << "#1: Input your own matrix" << endl;
            cout << "#2: Getting an element at i and j" << endl;
            cout << "#3: Change an element at i and j" << endl;
            cout << "#4: Print the Matrix" << endl;
            cout << "#5: Multiplying Matrices" << endl;
            cout << "#6: Summation of matrices" << endl;
            cout <<  "Enter your choice: ";
            cin >> option;
            switch (option) {
                case 1:
                    readMatrix(m1);
                    break;
                case 2:
                    getElement();
                    break;
                case 3:
                    setElement();
                    break;
                case 4:
                    printMatrix(m1);
                    break;
                case 5:
                    multiplyMatrices();
                    break;
                case 6:
                    addMatrices();
                    break;
            }
        } while(option > 0);
    }
private:
    Matrix m1,m2;
    void readMatrix(Matrix& m) {
        cout<< "Enter the sizes of the matrix: M*N  " << endl;
        int M,N;
        cin>>M>>N;
        vector<int> vec;
        cout<< "Enter the elements of the matrix:" << endl;
        string value;
        while(cin >> value && value != "exit"){
            vec.push_back(stoi(value));
        }

      //  m(vec,M,N);
    }
    void getElement(){
    cout<<"Enter i: ";
        int i;
        cin >> i;
        cout<<"Enter j: ";
        int j;
        cin >> j;
        try{
            cout << "The element M(" << i << "," << j << ") is " << m1.getEntry(i,j) << endl;}
        catch(invalid_argument){cout << "invalid indecies try again"<<endl;}

        };
    void setElement(){
    cout<<"Enter i: ";
        int i;
        cin >> i;
        cout<<"Enter j: ";
        int j;
        cin >> j;
        cout<<"Enter new value: ";
        int v;
        cin>>v;
        try{
            m1.changeEntry(i,j,v);
            cout << "The element M(" << i << "," << j << ") is now" << v << endl;}
        catch(invalid_argument){cout << "invalid indecies try again"<<endl;}
    };
    void printMatrix(Matrix &m){
        try {m.print();}
        catch(invalid_argument){}
    };
    void multiplyMatrices(){
       Matrix m = m1*m2;
       m.print();
    };
    void addMatrices(){
    Matrix m = m1+m2;
       m.print();};
};


#endif // MENU_H_INCLUDED
