//Joe Leland
//Program that analyzes a .txt or .csv file. First parameter upto the | delimter is the phone number, followed by the message. Calculates participation from each member of the chat. Calculates unique words and their frequency. Can search through messages for occurances of words.
#include "header.h"
#include <sstream>



int main(){
    cout << setprecision(2) << fixed << showpoint;
    string je = "15037105177", ja = "19713205181", er = "15035152382", le = "15038906957", br = "15035727064", tr = "13609365636", jo = "19713376569";
    string j = "Joe", t = "Trent", e = "Erik", l = "Leo", jm = "Jason", jn = "Jerah", b = "Brennan";
    friends joee(j);
    friends *trentt = new friends(t); //trentt(t);
    friends erikk(e), leoo(l), jasonn(jm), jerahh(jn), brennann(b);
    string word;
    string check;
    float total = 0.0;
    ifstream inFile;
    inFile.open("BDD.csv");
    //char tword[100];
    string skip;
    while(!inFile.eof()){
        getline(inFile, check, '|');
        if(!check.compare(je)){
            jerahh.totalwords += 1;
        }
        if(!check.compare(ja)){
            ++jasonn.totalwords;
        }
        if(!check.compare(er)){
            ++erikk.totalwords;
        }
        if(!check.compare(le)){
            ++leoo.totalwords;
        }
        if(!check.compare(br)){
            ++brennann.totalwords;
        }
        if(!check.compare(tr)){
            trentt->totalwords += 1;
        }
        if(!check.compare(jo)){
            ++joee.totalwords;
        }
        string n = "\n";
        getline(inFile, word);
        for(int i = 0; i < word.length(); ++i){
            //word[i].tolower();
        }
        stringstream s(word);
        string words;
        inFile.clear();
        if(!check.compare(je)){//15037105177){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                jerahh.insert(temp);
            }
        }
        else if(!check.compare(ja)){//19713205181){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                jasonn.insert(temp);
            }
        }
        else if(!check.compare(er)){//15035152382){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                erikk.insert(temp);
            }
            //inFile >> word;
        }
        else if(!check.compare(le)){//15038906957){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                leoo.insert(temp);
            }
            //inFile >> word;
        }
        else if(!check.compare(br)){//15035727064){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                brennann.insert(temp);
            }
            //inFile >> word;
        }
        else if(!check.compare(tr)){//13609365636){//trent
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                trentt->insert(temp);
            }
        }
        else if(!check.compare(jo)){//19713376569){
            for(int i = 0; s >> words; ++i){
                node*temp = new node(words);
                joee.insert(temp);
            }
        }
        ++total;
        inFile.peek();
        }

    //total += 2275;
    //joee.totalwords += 2275;
    inFile.close();
    cout << endl;
    cout << "Total Messages: " << total << endl;
    cout << endl << endl << endl << endl;
    cout << "Trent: " << trentt->totalwords << '\n'
         << "Joe: " << joee.totalwords << '\n'
         << "Leo: " << leoo.totalwords << '\n'
         << "Erik: " << erikk.totalwords << '\n'
         << "Jason: " << jasonn.totalwords << '\n'
         << "Jerah: " << jerahh.totalwords << '\n'
         << "Brennan: " << brennann.totalwords << endl << endl;

    cout << "Trent has contributed %" << (trentt->totalwords/total) * 100 << '\n'
         << "Jason has contributed %" << (jasonn.totalwords/total) * 100 << '\n'
         << "Joe has contributed %" << (joee.totalwords/total) * 100 << '\n'
         << "Leo has contributed %" << (leoo.totalwords/total) * 100 << '\n'
         << "Erik has contributed %" << (erikk.totalwords/total) * 100 << '\n'
         << "Jerah has contributed %" << (jerahh.totalwords/total) * 100 << '\n'
         << "Brennan has contributed %" << (brennann.totalwords/total) * 100 << endl;

    char choice = 'o';
    string f;
    string k;
        //node *ti = jerahh.orderIt();
        //ti->display();
        //erikk.build();
    //trentt->displayWords();
    joee.write();
    while(choice != 'q' && choice != 'Q'){
        cout << "What we doin?\n1. Word search.\n" << endl;;
        cin >> choice;
        cin.clear();
        cin.ignore(200, '\n');
        //cin >> f;
        string tempp;
        locale loc1;
        switch(choice){
            case '1':
            //cout << "Unique word count: " << trentt->size << endl;
            cout << "What word we looking for?: ";
            cin >> k;
            tempp = k;
            for(string::size_type i = 0; i < tempp.length(); ++i){
                tempp[i] = tolower(tempp[i], loc1);
            }
            cout << '\n';
            cout << "Trent";
            trentt->search(k);
            cout << '\n';
            cout << "Joe";
            joee.search(k);
            cout << '\n';
            cout << "Leo";
            leoo.search(k);
            cout << '\n';
            cout << "Jason";
            jasonn.search(k);
            cout << '\n';
            cout << "Erik";
            erikk.search(k);
            cout << '\n';
            cout << "Brennan";
            brennann.search(k);
            cout << '\n';
            cout << "Jerah";
            jerahh.search(k);
            break;

            default:
                cout << "Invalid." << endl;
                break;
        }



    }
    cout << endl << endl << endl << endl;
    //cout << trentt->size << endl;
    //leoo.displayWords();
    delete trentt;









return 0;
}
